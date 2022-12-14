#ifndef REPLACE_BINDINGS_CALLBACK_H
#define REPLACE_BINDINGS_CALLBACK_H

#include "clang/Frontend/FrontendActions.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"

#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/Lex/Lexer.h"
#include "clang/Lex/Token.h"
#include "clang/Rewrite/Core/RewriteBuffer.h"
#include "clang/Rewrite/Core/Rewriter.h"

#include "CodeAction.h"
#include "RewriteCallback.h"
#include "RewriteInternalCallback.h"
#include "ClangRewriteUtils.h"

using namespace clang;
using namespace clang::ast_matchers;

using namespace clang::tooling;
using namespace llvm;

namespace clang {
namespace rewrite_tool {

template <typename T>
const T* findFirstChild(const Stmt* stmt) {
  for (auto i = stmt->child_begin(); i != stmt->child_end(); i++) {
    if (const T* node = dyn_cast<T>(*i)) {
      printf("FOUND IT\n");
      return node;
    }
    return findFirstChild<T>(*i);
  }
  return nullptr;
}

static std::vector<SourceRange> banned_ranges;

bool in_banned_range(SourceRange rng) {
  for (SourceRange banned : banned_ranges) {
    if (banned.fullyContains(rng)) {
      return true;
    }
  }
  return false;
}

class ReplaceBindingsCallback : public MatchFinder::MatchCallback {
public:
  ASTContext* context;
  CodeAction* action;
  Binding bind;
  Rewriter::RewriteOptions opts;
  std::vector<Binding> all_bindings;
  SourceRange original_range;
  std::string original_file;

  ReplaceBindingsCallback(CodeAction* action, Binding b, std::vector<Binding> bindings,
      SourceRange og_range, std::string og_file)
    : action(action), bind(b), all_bindings(bindings), original_range(og_range),
      original_file(og_file) {
      opts.IncludeInsertsAtBeginOfRange = false;
    }

  ~ReplaceBindingsCallback() {}

  void onStartOfTranslationUnit() override {}

  void run(const MatchFinder::MatchResult &result) override {
    // printf("RUNNING THE THING\n");
    printf("found match for binding\n");
    context = result.Context;
    binding_rw.setSourceMgr(context->getSourceManager(), context->getLangOpts());

    const Expr* exp = result.Nodes.getNodeAs<Expr>("match");
    const NamedDecl* decl = result.Nodes.getNodeAs<NamedDecl>("match");

    bool expr_valid = true;
    bool decl_valid = true;

    if (!exp ||
        context->getSourceManager().getFilename(exp->getBeginLoc()).str() != action->spec_file_name)
         {
      // printf("ERROR: invalid expr binding match loc\n");
      expr_valid = false;
    }

    if (!decl ||
        context->getSourceManager().getFilename(decl->getBeginLoc()).str() != action->spec_file_name) {
      // printf("ERROR: invalid decl binding match loc\n");
      decl_valid = false;
    }

    if (!expr_valid && !decl_valid) {
      // printf("ERROR: no valid binding match loc\n");
      return;
    }

    SourceRange match_range;
    if (expr_valid) {
      // printf("expr valid\n");
      // printf("file name %s\n", context->getSourceManager().getFilename(expr->getBeginLoc()).str().c_str());
      match_range = SourceRange(exp->getBeginLoc(), exp->getEndLoc());
    }
    else if (decl_valid) {
      // printf("decl valid\n");
      // printf("file name %s\n", context->getSourceManager().getFilename(decl->getBeginLoc()).str().c_str());
      match_range = SourceRange(decl->getBeginLoc(), decl->getEndLoc());
    }

    printf("action source range\n");
    action->snippet_range.dump(context->getSourceManager());
    printf("match range\n");
    match_range.dump(context->getSourceManager());
    if (!action->snippet_range.fullyContains(match_range) || in_banned_range(match_range)) {
      // printf("ERROR: match not in action's snippet\n");
      return;
    }


    FullSourceLoc begin;
    FullSourceLoc end;
    FullSourceLoc match;

    // just in case, we may need it later
    RewriteInternalCallback<ast_matchers::internal::DynTypedMatcher> **callbacks;
    if (expr_valid) {
      if (bind.name == "clang_rewrite::loop_body" ||
          bind.qual_name == "clang_rewrite::loop_body") {
        printf("YAY LOOP BODY\n");
        exp->dump();
        // auto parentmap = context->getParentMapContext().getParents(*expr);
        DynTypedNodeList Parents = context->getParents(*exp);
        llvm::SmallVector<DynTypedNode, 8> Stack(Parents.begin(), Parents.end());
        const CallExpr* call;
        while (!Stack.empty()) {
          const auto &CurNode = Stack.back();
          Stack.pop_back();
          if (const CompoundStmt* comp = CurNode.get<CompoundStmt>()) {
            begin = context->getFullLoc(comp->getLBracLoc());
            end = context->getFullLoc(comp->getRBracLoc());
            match = begin;
            break;
          }
          else if (const CallExpr* callexpr = CurNode.get<CallExpr>()) {
            if (callexpr->getDirectCallee()->getQualifiedNameAsString() ==
                "clang_rewrite::loop_body") {
                  call = callexpr;
            }
            llvm::append_range(Stack, context->getParents(CurNode));
          }
          else {
            llvm::append_range(Stack, context->getParents(CurNode));
          }
        }

        if (call->getNumArgs() > 0) {
          const Expr* mods = call->getArg(0);
          mods->dump();
          const InitListExpr* initlist = findFirstChild<InitListExpr>(mods);
          if (initlist != nullptr) {
            // run binding replacement on cxxConstructExpr code
            const Expr* init = initlist->getInit(0);
            FullSourceLoc il_begin = context->getFullLoc(init->getBeginLoc());
            FullSourceLoc il_end = context->getFullLoc(init->getEndLoc());
            FileID il_fid = il_begin.getFileID();
            unsigned int il_begin_offset = il_begin.getFileOffset();
            unsigned int il_end_offset = il_end.getFileOffset();

            banned_ranges.push_back(SourceRange(il_begin, il_end));

            llvm::Optional<llvm::MemoryBufferRef> buff =
              context->getSourceManager().getBufferOrNone(il_fid);

            char *code = new char[il_end_offset - il_begin_offset + 1];
            if (buff.has_value()) {
              memcpy(code, &(buff->getBufferStart()[il_begin_offset]),
                     (il_end_offset - il_begin_offset + 1) * sizeof(char));
              code[il_end_offset - il_begin_offset] =
                  '\0'; // force null terminated for Reasons
              printf("code??? %s\n", code);
            } else {
              printf("no buffer :<\n");
            }

            StatementMatcher inits_matcher = callExpr(allOf(
              callee(functionDecl(hasName("clang_rewrite::loop_body"))),
              hasArgument(0, cxxBindTemporaryExpr(hasSubExpr(
                cxxConstructExpr(hasArgument(0,
                  cxxStdInitializerListExpr(hasSubExpr(materializeTemporaryExpr(hasSubExpr(
                    initListExpr(hasInit(0, cxxConstructExpr(hasArgument(0, expr(anything()).bind("body")))))
                  ))))
                ))
              )))
            )).bind("matcher");

            MatchFinder inits_finder;
            MatcherGenCallback mgcb(/*is_internal_matcher=*/true, all_bindings);

            inits_finder.addMatcher(inits_matcher, &mgcb);

            Tool->run(newFrontendActionFactory(&inits_finder).get());

            CodeAction act(std::string(code), "tempaction", NewCodeKind::Replace,
              {"tempmatcher"}, context->getSourceManager().getFilename(il_begin).str(),
              SourceRange(il_begin, il_end));

            for (auto m : internal_matchers) {
              m->addAction(&act);
            }

            MatchFinder replace_finder;
            callbacks = new RewriteInternalCallback<ast_matchers::internal::DynTypedMatcher>
              *[internal_matchers.size()];

            int i = 0;
            for (MatcherWrapper<ast_matchers::internal::DynTypedMatcher> *m : internal_matchers) {
              callbacks[i] =
                new RewriteInternalCallback<ast_matchers::internal::DynTypedMatcher>(m,
                  all_bindings, original_range, original_file);
              replace_finder.addDynamicMatcher(m->getMatcher(), callbacks[i]);
              i++;
            }

            Tool->run(newFrontendActionFactory(&replace_finder).get());

            // options:
            //  - replace in binding.value - no
            //  - fake action?? - wtf even
            //  - rewrite on top of rewrite - rewrite with existing binding, then
            //    a series of rewrites for internal matcher actions - have to
            //    figure out offsets

            // run this callback but with the og loop source range as place to look
          }
        }
      }
      else {
        begin = context->getFullLoc(exp->getBeginLoc());
        end = context->getFullLoc(exp->getEndLoc());
        match = context->getFullLoc(exp->getBeginLoc());
      }
    }
    else if (decl_valid) {
      begin = context->getFullLoc(decl->getBeginLoc());
      end = context->getFullLoc(decl->getEndLoc());
      match = context->getFullLoc(decl->getLocation());
    }

    unsigned int begin_line = begin.getSpellingLineNumber();
    unsigned int begin_col = begin.getSpellingColumnNumber();
    unsigned int end_line = end.getSpellingLineNumber();
    unsigned int end_col = end.getSpellingColumnNumber();

    FileID fid = begin.getFileID();
    unsigned int begin_offset = begin.getFileOffset();
    unsigned int end_offset = end.getFileOffset();
    unsigned int match_offset = match.getFileOffset();

    if (begin_offset == end_offset) {
      printf("one char match, luls\n");
      end_offset += 1;
    }

    printf("FOUND match for binding at %d:%d - %d:%d\n",
           begin_line, begin_col, end_line, end_col);

    llvm::Optional<llvm::MemoryBufferRef> buff =
      context->getSourceManager().getBufferOrNone(fid);

    char* code = new char[end_offset - begin_offset + 1];
    if (buff.has_value()) {
      memcpy(code, &(buff->getBufferStart()[begin_offset]),
             (end_offset - begin_offset + 1) * sizeof(char));
      code[end_offset - begin_offset] = '\0';
      printf("matched range: %s\n", code);
      printf("               ");
      for (unsigned int i = 0; i < match_offset - begin_offset; i++) {
        printf(" ");
      }
      printf("^\n");
    }
    delete[] code;


    if (expr_valid && (bind.name == "clang_rewrite::loop_body" ||
        bind.qual_name == "clang_rewrite::loop_body")) {
      binding_rw.ReplaceText(begin, end_offset - begin_offset + 1, bind.value);

      // figure out offsets for inline m/r pairs we found above
      for (int i = 0; i < internal_matchers.size(); i++) {
        RewriteInternalCallback<ast_matchers::internal::DynTypedMatcher>* cb = callbacks[i];
        if (cb->is_valid) {
          printf("rewrite start offset %u\n", cb->rewrite_start_offset);
          printf("length %u\n", cb->rewrite_end_offset - cb->rewrite_start_offset +1);
          printf("new code for luls %s\n", cb->new_code.c_str());
          if (!cb->new_code.empty()) {
            binding_rw.ReplaceText(
              begin.getLocWithOffset(cb->rewrite_start_offset),
              cb->rewrite_end_offset - cb->rewrite_start_offset+1,
              cb->new_code);
          }
        }
      }
    }
    else if (expr_valid) {
      printf("expr\n");
      exp->dump();

      char* name_c = new char[end_offset - match_offset + 1];
      size_t space;
      if (buff.has_value()) {
        memcpy(name_c, &(buff->getBufferStart()[match_offset]),
               (end_offset - match_offset + 1) * sizeof(char));
        name_c[end_offset - match_offset] = '\0';
        StringRef name(name_c);
        // TODO something clever to figure out which name was used in the og
        // code, use that as the length of stuff to replace
        // if (bind.name == bind.qual_name) {
        //   space = bind.name.size();
        // }
        // else if (bind.name.empty()) {
        //   space = bind.qual_name.size();
        // }
        // else if (bind.qual_name.empty()) {
        //   space = bind.name.size();
        // }
        // else if (name.find(" ") != StringRef::npos) {
        //   space = name.find(" ");
        // }
        // else {
        //   space = 1;
        // }
        space = Lexer::MeasureTokenLength(exp->getBeginLoc(),
          context->getSourceManager(), context->getLangOpts());
        printf("oh noes %lu\n", space);

        exp->getExprLoc().dump(context->getSourceManager());
        binding_rw.ReplaceText(exp->getExprLoc(), space, bind.value);
      }
    }
    else if (decl_valid) {
      printf("decl\n");
      decl->dump();

      char* name_c = new char[end_offset - match_offset + 1];
      size_t space;
      if (buff.has_value()) {
        memcpy(name_c, &(buff->getBufferStart()[match_offset]),
               (end_offset - match_offset + 1) * sizeof(char));
        name_c[end_offset - match_offset] = '\0';
        StringRef name(name_c);
        if (name.find(" ") != StringRef::npos) {
          space = name.find(" ");
        }
        else {
          space = 1;
        }

        binding_rw.ReplaceText(decl->getLocation(), space, bind.value);
      }
      delete[] name_c;
    }
    std::string new_code = binding_rw.getRewrittenText(action->snippet_range);

    printf("new code!!!! %s\n", new_code.c_str());
    action->edited_code_snippet = new_code;
    internal_matchers.clear();
  }

  void onEndOfTranslationUnit() override {}
};

}
}
#endif // REPLACE_BINDINGS_CALLBACK_H
