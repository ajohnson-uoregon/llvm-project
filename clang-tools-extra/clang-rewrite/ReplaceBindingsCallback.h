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

#include <iostream>
#include <fstream>

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
  FileID fid;
  bool file_changed = false;

  ReplaceBindingsCallback(CodeAction* action, Binding b, std::vector<Binding> bindings,
      SourceRange og_range, std::string og_file)
    : action(action), bind(b), all_bindings(bindings), original_range(og_range),
      original_file(og_file) {
      opts.IncludeInsertsAtBeginOfRange = false;
    }

  ~ReplaceBindingsCallback() {}

  void handle_loop_body_macro() {

  }

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
        !context->getSourceManager().getFilename(exp->getBeginLoc()).endswith("clang_rewrite_temp_source.cpp"))
         {
      if (exp) printf("filename??? %s\n", context->getSourceManager().getFilename(exp->getBeginLoc()).str().c_str());
      printf("ERROR: invalid expr binding match loc\n");
      expr_valid = false;
    }

    if (!decl ||
        !context->getSourceManager().getFilename(decl->getBeginLoc()).endswith("clang_rewrite_temp_source.cpp")) {
      if (decl) printf("filename??? %s\n", context->getSourceManager().getFilename(decl->getBeginLoc()).str().c_str());
      printf("ERROR: invalid decl binding match loc\n");
      decl_valid = false;
    }

    if (!expr_valid && !decl_valid) {
      printf("ERROR: no valid binding match loc\n");
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

    // printf("action source range\n");
    // action->snippet_range.dump(context->getSourceManager());
    // printf("match range\n");
    // match_range.dump(context->getSourceManager());
    // if (!action->snippet_range.fullyContains(match_range) || in_banned_range(match_range)) {
    //   // printf("ERROR: match not in action's snippet\n");
    //   return;
    // }
    // valid range ensured by matcher only looking for things in [[clang::matcher_block]]


    FullSourceLoc begin;
    FullSourceLoc end;
    FullSourceLoc match;

    // just in case, we may need it later
    RewriteInternalCallback<ast_matchers::internal::DynTypedMatcher> **callbacks;
    if (expr_valid) {
      if (bind.name == "clang_rewrite::loop_body" ||
          bind.qual_name == "clang_rewrite::loop_body") {
        // printf("YAY LOOP BODY\n");
        // exp->dump();
        // // auto parentmap = context->getParentMapContext().getParents(*expr);
        // DynTypedNodeList Parents = context->getParents(*exp);
        // llvm::SmallVector<DynTypedNode, 8> Stack(Parents.begin(), Parents.end());
        // const CallExpr* call;
        // while (!Stack.empty()) {
        //   const auto &CurNode = Stack.back();
        //   Stack.pop_back();
        //   if (const CompoundStmt* comp = CurNode.get<CompoundStmt>()) {
        //     begin = context->getFullLoc(comp->getLBracLoc());
        //     end = context->getFullLoc(comp->getRBracLoc());
        //     match = begin;
        //     break;
        //   }
        //   else if (const CallExpr* callexpr = CurNode.get<CallExpr>()) {
        //     if (callexpr->getDirectCallee()->getQualifiedNameAsString() ==
        //         "clang_rewrite::loop_body") {
        //           call = callexpr;
        //     }
        //     llvm::append_range(Stack, context->getParents(CurNode));
        //   }
        //   else {
        //     llvm::append_range(Stack, context->getParents(CurNode));
        //   }
        // }
        //
        // if (call->getNumArgs() > 0) {
        //   const Expr* mods = call->getArg(0);
        //   mods->dump();
        //   const InitListExpr* initlist = findFirstChild<InitListExpr>(mods);
        //   if (initlist != nullptr) {
        //     // run binding replacement on cxxConstructExpr code
        //     const Expr* init = initlist->getInit(0);
        //     FullSourceLoc il_begin = context->getFullLoc(init->getBeginLoc());
        //     FullSourceLoc il_end = context->getFullLoc(init->getEndLoc());
        //     FileID il_fid = il_begin.getFileID();
        //     unsigned int il_begin_offset = il_begin.getFileOffset();
        //     unsigned int il_end_offset = il_end.getFileOffset();
        //
        //     banned_ranges.push_back(SourceRange(il_begin, il_end));
        //
        //     llvm::Optional<llvm::MemoryBufferRef> buff =
        //       context->getSourceManager().getBufferOrNone(il_fid);
        //
        //     char *code = new char[il_end_offset - il_begin_offset + 1];
        //     if (buff.has_value()) {
        //       memcpy(code, &(buff->getBufferStart()[il_begin_offset]),
        //              (il_end_offset - il_begin_offset + 1) * sizeof(char));
        //       code[il_end_offset - il_begin_offset] =
        //           '\0'; // force null terminated for Reasons
        //       printf("code??? %s\n", code);
        //     } else {
        //       printf("no buffer :<\n");
        //     }
        //
        //     StatementMatcher inits_matcher = callExpr(allOf(
        //       callee(functionDecl(hasName("clang_rewrite::loop_body"))),
        //       hasArgument(0, cxxBindTemporaryExpr(hasSubExpr(
        //         cxxConstructExpr(hasArgument(0,
        //           cxxStdInitializerListExpr(hasSubExpr(materializeTemporaryExpr(hasSubExpr(
        //             initListExpr(hasInit(0, cxxConstructExpr(hasArgument(0, expr(anything()).bind("body")))))
        //           ))))
        //         ))
        //       )))
        //     )).bind("matcher");
        //
        //     MatchFinder inits_finder;
        //     MatcherGenCallback mgcb(/*is_internal_matcher=*/true, all_bindings);
        //
        //     inits_finder.addMatcher(inits_matcher, &mgcb);
        //
        //     Tool->run(newFrontendActionFactory(&inits_finder).get());
        //
        //     fid = begin.getFileID();
        //     unsigned int begin_offset = begin.getFileOffset();
        //     unsigned int end_offset = end.getFileOffset();
        //     unsigned int match_offset = match.getFileOffset();
        //
        //     binding_rw.ReplaceText(original_range.getBegin(), end_offset - begin_offset + 1, bind.value);
        //
        //     printf("wat?\n%s\n", binding_rw.getRewrittenText(action->snippet_range).c_str());

            // std::ofstream temp_file("clang_rewrite_temp_spec.cpp");
            //
            // // const RewriteBuffer* temp_buff = binding_rw.getRewriteBufferFor(fid);
            // SourceLocation file_begin = context->getSourceManager().getLocForStartOfFile(context->getFullLoc(original_range.getBegin()).getFileID());
            // SourceLocation file_end = context->getSourceManager().getLocForEndOfFile(context->getFullLoc(original_range.getBegin()).getFileID());
            // temp_file << binding_rw.getRewrittenText(SourceRange(file_begin, file_end));
            // temp_file.close();
            //
            // llvm::cl::OptionCategory TempCategory("Internal category that should never be seen.");
            //
            // llvm::Expected<CommonOptionsParser> ExpectedParser =
            //     CommonOptionsParser::create(global_argc, global_argv, TempCategory);
            //
            // printf("argc %d\n", global_argc);
            // for (int i = 0; i < global_argc; i++) {
            //   printf("argv %s\n", global_argv[i]);
            // }
            //
            // if (!ExpectedParser) {
            //   // Fail gracefully for unsupported options.
            //   llvm::errs() << ExpectedParser.takeError();
            //   return;
            // }
            //
            // CommonOptionsParser& OptionsParser = ExpectedParser.get();
            // ClangTool process_temp(Tool->getCompilationDatabase(), {"clang_rewrite_temp.cpp"});
            //
            // CodeAction act(std::string(code), "", "tempaction", NewCodeKind::Replace,
            //   {"tempmatcher"}, context->getSourceManager().getFilename(il_begin).str(),
            //   SourceRange(il_begin, il_end));
            //
            // for (auto m : internal_matchers) {
            //   m->addAction(&act);
            // }
            //
            // MatchFinder replace_finder;
            // callbacks = new RewriteInternalCallback<ast_matchers::internal::DynTypedMatcher>
            //   *[internal_matchers.size()];
            //
            // int i = 0;
            // for (MatcherWrapper<ast_matchers::internal::DynTypedMatcher> *m : internal_matchers) {
            //   callbacks[i] =
            //     new RewriteInternalCallback<ast_matchers::internal::DynTypedMatcher>(m,
            //       all_bindings, original_range, original_file);
            //   replace_finder.addDynamicMatcher(m->getMatcher(), callbacks[i]);
            //   i++;
            // }
            //
            // process_temp.run(newFrontendActionFactory(&replace_finder).get());

            // run this callback but with the og loop source range as place to look
          // }
        // }
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

    fid = begin.getFileID();
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


      // figure out offsets for inline m/r pairs we found above
      // for (int i = 0; i < internal_matchers.size(); i++) {
      //   RewriteInternalCallback<ast_matchers::internal::DynTypedMatcher>* cb = callbacks[i];
      //   if (cb->is_valid) {
      //     printf("rewrite start offset %u\n", cb->rewrite_start_offset);
      //     printf("length %u\n", cb->rewrite_end_offset - cb->rewrite_start_offset +1);
      //     printf("new code for luls %s\n", cb->new_code.c_str());
      //     if (!cb->new_code.empty()) {
      //       int curr_offset = 0;
      //       SourceLocation curr_loc = begin;
      //       while (curr_offset < cb->rewrite_start_offset) {
      //         printf("token offset funtimes %d\n", curr_offset);
      //         curr_offset += Lexer::MeasureTokenLength(curr_loc, context->getSourceManager(), context->getLangOpts());
      //         llvm::Optional<Token> tok = Lexer::findNextToken(curr_loc, context->getSourceManager(), context->getLangOpts());
      //         if (tok.has_value()) {
      //           curr_loc = tok->getLocation();
      //           llvm::errs() << tok->getName() << "\n";
      //           if (tok->isOneOf(tok::TokenKind::unknown, tok::TokenKind::eof)) {
      //             llvm::errs() << tok->getLiteralData() << "\n";
      //             break;
      //           }
      //         }
      //         else {
      //           printf("ERROR: bad token\n");
      //           break;
      //         }
      //       }
      //       binding_rw.ReplaceText(
      //         curr_loc /*begin.getLocWithOffset(cb->rewrite_start_offset)*/,
      //         cb->rewrite_end_offset - cb->rewrite_start_offset+1,
      //         cb->new_code);
      //       printf("wat2?\n");
      //       const RewriteBuffer* test = binding_rw.getRewriteBufferFor(fid);
      //       test->write(llvm::errs());
      //       printf("\n");
      //     }
      //   }
      // }
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
        file_changed = true;
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
        file_changed = true;
      }
      delete[] name_c;
    }
    std::string new_code = binding_rw.getRewrittenText(match_range);

    printf("new code!!!! %s\n", new_code.c_str());
    action->edited_code_snippet = new_code;
    internal_matchers.clear();
  }

  void onEndOfTranslationUnit() override {
    if (file_changed) {
      std::ofstream temp_file("clang_rewrite_temp_source_1.cpp");

      SourceLocation file_begin = context->getSourceManager().getLocForStartOfFile(fid);
      SourceLocation file_end = context->getSourceManager().getLocForEndOfFile(fid);

      temp_file << binding_rw.getRewrittenText(SourceRange(file_begin, file_end));
      temp_file.close();
    }
    else {
      printf("file not changed\n");
    }

  }
};

}
}
#endif // REPLACE_BINDINGS_CALLBACK_H
