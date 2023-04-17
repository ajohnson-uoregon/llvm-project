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
#include "ClangRewriteUtils.h"

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace clang;
using namespace clang::ast_matchers;

using namespace clang::tooling;
using namespace llvm;

namespace clang {
namespace rewrite_tool {

extern Rewriter binding_rw;
extern std::vector<Binding> create_bindings(const MatchFinder::MatchResult& result, ASTContext* context);

template <typename T>
const T* findFirstChild(const Stmt* stmt) {
  for (auto i = stmt->child_begin(); i != stmt->child_end(); i++) {
    if (const T* node = dyn_cast<T>(*i)) {
      // printf("FOUND IT\n");
      return node;
    }
    return findFirstChild<T>(*i);
  }
  return nullptr;
}

class ReplaceBindingsCallback : public MatchFinder::MatchCallback {
public:
  ASTContext* context;
  CodeAction* action;
  Binding bind;
  std::vector<Binding> all_bindings;
  FileID fid;
  static std::vector<SourceRange> past_matches;
  std::vector<Binding> inner_bindings;
  static int line_delta;

  ReplaceBindingsCallback(CodeAction* action, Binding b, std::vector<Binding> bindings)
    : action(action), bind(b), all_bindings(bindings) {}

  void onStartOfTranslationUnit() override {}

  void run(const MatchFinder::MatchResult &result) override {
    printf("running ReplaceBindingsCallback\n");

    context = result.Context;
    binding_rw.setSourceMgr(context->getSourceManager(), context->getLangOpts());

    const Expr* exp = result.Nodes.getNodeAs<Expr>("clang_rewrite_match");
    const NamedDecl* decl = result.Nodes.getNodeAs<NamedDecl>("clang_rewrite_match");

    // TODO: can I condense the two names into one?
    if (!exp && !decl) {
      exp = result.Nodes.getNodeAs<Expr>("clang_rewrite_top_level_match");
      decl = result.Nodes.getNodeAs<NamedDecl>("clang_rewrite_top_level_match");
    }

    bool expr_valid = true;
    bool decl_valid = true;

    if (!exp ||
        !context->getSourceManager().getFilename(exp->getBeginLoc()).endswith("clang_rewrite_temp_source.cpp." + std::to_string(num_bind_files) + ".bind.cpp"))
         {
      if (exp) printf("filename??? %s\n", context->getSourceManager().getFilename(exp->getBeginLoc()).str().c_str());
      printf("ERROR: invalid expr binding match loc\n");
      expr_valid = false;
    }

    if (!decl ||
        !context->getSourceManager().getFilename(decl->getBeginLoc()).endswith("clang_rewrite_temp_source.cpp." + std::to_string(num_bind_files) + ".bind.cpp")) {
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

    FullSourceLoc begin;
    FullSourceLoc end;
    FullSourceLoc match;

    if (expr_valid) {
      begin = context->getFullLoc(exp->getBeginLoc());
      end = context->getFullLoc(exp->getEndLoc());
      match = context->getFullLoc(exp->getBeginLoc());
    }
    else if (decl_valid) {
      begin = context->getFullLoc(decl->getBeginLoc());
      end = context->getFullLoc(decl->getEndLoc());
      match = context->getFullLoc(decl->getLocation());
    }

    //dump
    unsigned int begin_line = begin.getSpellingLineNumber();
    unsigned int begin_col = begin.getSpellingColumnNumber();
    unsigned int end_line = end.getSpellingLineNumber();
    unsigned int end_col = end.getSpellingColumnNumber();
    printf("FOUND match for binding at %d:%d - %d:%d\n",
           begin_line, begin_col, end_line, end_col);

    if (bind.has_valid_range) {
      if (!locIsInRangeHard(bind.valid_over, begin_line, begin_col, end_line, end_col)) {
        printf("match not in binding's valid range\n");
        return;
      }
    }

    fid = begin.getFileID();
    unsigned int begin_offset = begin.getFileOffset();
    unsigned int end_offset = end.getFileOffset();
    unsigned int match_offset = match.getFileOffset();

    if (begin_offset == end_offset) {
      printf("one char match, luls\n");
      end_offset += 1;
    }

    if (std::find(past_matches.begin(), past_matches.end(), match_range) != past_matches.end()) {
      printf("duplicate match\n");
      return;
    }
    else {
      past_matches.push_back(match_range);
    }

    std::optional<llvm::MemoryBufferRef> buff =
      context->getSourceManager().getBufferOrNone(fid);

    if (expr_valid) {
      printf("expr\n");
      exp->dump();
      if (bind.name == "clang_rewrite::loop_body" ||
          bind.qual_name == "clang_rewrite::loop_body") {
        // go match loop_body in file - might need to rewrite file in between
        // pull matcher/replacer pair
        // run MatcherGenCallback to put matcher into internal_matchers
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

        // TODO: only find matches within range?
        MatchFinder inits_finder;
        MatcherGenCallback mgcb(/*is_internal_matcher=*/true, all_bindings);

        inits_finder.addMatcher(inits_matcher, &mgcb);

        printf("ABOUT TO RUN THE THING\n");
        ClangTool process_temp(Tool->getCompilationDatabase(), {"clang_rewrite_temp_source.cpp.bind_final.cpp"});
        process_temp.run(newFrontendActionFactory(&inits_finder).get());
        // rewrite file with b.value wrapped in internal matcher_block attr
        // to do that we need the callexpr
        DynTypedNodeList Parents = context->getParents(*exp);
        llvm::SmallVector<DynTypedNode, 8> Stack(Parents.begin(), Parents.end());
        const CallExpr* call; // DO NOT try to get the location of this
        std::string matcher_text = "";
        std::string replacer_text = "";
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
                  const Expr* arg = callexpr->getArg(0);
                  const InitListExpr* initlist = findFirstChild<InitListExpr>(arg);
                  const Expr* matcher = cast<CXXConstructExpr>(initlist->getInit(0))->getArg(0);
                  const Expr* replacer = cast<CXXConstructExpr>(initlist->getInit(0))->getArg(1);

                  FullSourceLoc m_begin = context->getFullLoc(matcher->getBeginLoc());
                  FullSourceLoc m_end = context->getFullLoc(matcher->getEndLoc());

                  FullSourceLoc r_begin = context->getFullLoc(replacer->getBeginLoc());
                  FullSourceLoc r_end = context->getFullLoc(replacer->getEndLoc());

                  matcher_text = binding_rw.getRewrittenText(SourceRange(m_begin,
                    Lexer::getLocForEndOfToken(m_end, 0, context->getSourceManager(), context->getLangOpts())));
                  replacer_text = binding_rw.getRewrittenText(SourceRange(r_begin,
                    Lexer::getLocForEndOfToken(r_end, 0, context->getSourceManager(), context->getLangOpts())));

                  matcher_text = matcher_text.substr(0, matcher_text.size()-1);
                  replacer_text = replacer_text.substr(0, replacer_text.size()-1);
                  printf("matcher text? %s\n", matcher_text.c_str());
                  printf("replacer text? %s\n", replacer_text.c_str());
            }
            llvm::append_range(Stack, context->getParents(CurNode));
          }
          else {
            llvm::append_range(Stack, context->getParents(CurNode));
          }
        }

        begin_line = begin.getSpellingLineNumber();
        begin_col = begin.getSpellingColumnNumber();
        end_line = end.getSpellingLineNumber();
        end_col = end.getSpellingColumnNumber();
        printf("TRUE match for binding at %d:%d - %d:%d\n",
               begin_line, begin_col, end_line, end_col);

        begin_offset = begin.getFileOffset();
        end_offset = end.getFileOffset();

        size_t space = end_offset - begin_offset + 1;
        printf("space %lu\n", space);

        binding_rw.ReplaceText(begin, space, bind.value);
        // binding_rw.overwriteChangedFiles();

        int num_lines = std::count(bind.value.begin(), bind.value.end(), '\n');
        printf("num lines = %d\n", num_lines);

        int num_cols = bind.value.size() - bind.value.rfind("\n");
        printf("num cols = %d\n", num_cols);
        // run some kind of generic finder callback to generate bindings from
        // match itself

        std::vector<Binding> internal_bindings = create_bindings(result, context);
        printf("internal bindings:\n");
        for (Binding b : internal_bindings) {
          b.has_valid_range = true;
          if (num_lines == 0) {
            b.valid_over = {begin_line+line_delta, begin_col, begin_line+num_lines+line_delta, begin_col+num_cols};
          }
          else {
            b.valid_over = {begin_line+line_delta, begin_col, begin_line+num_lines+line_delta, num_cols};
          }
          dump_binding(b);
        }
        inner_bindings.insert(inner_bindings.begin(), internal_bindings.begin(), internal_bindings.end());
        // generate bindings from matchers we made with mgcb
        for (auto m : internal_matchers) {
          if (locIsInRangeHard(begin_line, begin_col, end_line, end_col,
                m->getLine(), m->getCol())) {
            Binding b;
            b.matchers = {VariantMatcher::SingleMatcher(m->getMatcher())};
            b.name = matcher_text;
            b.qual_name = matcher_text;
            b.value = replacer_text;
            b.kind = BindingKind::VarNameBinding;
            b.has_valid_range = true;
            if (num_lines == 0) {
              b.valid_over = {begin_line+line_delta, begin_col, begin_line+num_lines+line_delta, begin_col+num_cols};
            }
            else {
              b.valid_over = {begin_line+line_delta, begin_col, begin_line+num_lines+line_delta, num_cols};
            }
            inner_bindings.push_back(b);
          }
        }
        printf("inner bindings\n");
        for (Binding b : inner_bindings) {
          dump_binding(b);
        }
        // dump bindings into inner_bindings, hand back to RewriteCallback

        // TODO: this is a hack, do it better
        line_delta += num_lines - (end_line-begin_line);
      }
      else {
        if (isa<DeclRefExpr>(exp)) {
          char* name_c = new char[end_offset - match_offset + 1];
          size_t space;
          if (buff.has_value()) {
            memcpy(name_c, &(buff->getBufferStart()[match_offset]),
                   (end_offset - match_offset + 1) * sizeof(char));
            name_c[end_offset - match_offset] = '\0';
            StringRef name(name_c);

            space = Lexer::MeasureTokenLength(exp->getBeginLoc(),
              context->getSourceManager(), context->getLangOpts());
            printf("oh noes %lu\n", space);

            exp->getExprLoc().dump(context->getSourceManager());
            binding_rw.ReplaceText(exp->getExprLoc(), space, bind.value);
          }
        }
        else {
          // get true range
          // we can trust begin and begin_line/_col
          FullSourceLoc true_end = context->getFullLoc(
            Lexer::getLocForEndOfToken(end, 1, context->getSourceManager(), context->getLangOpts()));

          begin_line = begin.getSpellingLineNumber();
          begin_col = begin.getSpellingColumnNumber();
          end_line = true_end.getSpellingLineNumber();
          end_col = true_end.getSpellingColumnNumber();
          printf("TRUE match for binding at %d:%d - %d:%d\n",
                 begin_line, begin_col, end_line, end_col);

          begin_offset = begin.getFileOffset();
          end_offset = true_end.getFileOffset();

          size_t space = end_offset - begin_offset + 1;
          printf("space %lu\n", space);

          // replace true range
          binding_rw.ReplaceText(begin, space, bind.value);

          int num_lines = std::count(bind.value.begin(), bind.value.end(), '\n');
          printf("num lines = %d\n", num_lines);

          int num_cols = bind.value.size() - bind.value.rfind("\n");
          printf("num cols = %d\n", num_cols);

          // create bindings from result
          std::vector<Binding> internal_bindings = create_bindings(result, context);
          printf("internal bindings:\n");
          for (Binding& b : internal_bindings) {
            b.has_valid_range = true;
            if (num_lines == 0) {
              b.valid_over = {begin_line+line_delta, begin_col, begin_line+num_lines+line_delta, begin_col+num_cols};
            }
            else {
              b.valid_over = {begin_line+line_delta, begin_col, begin_line+num_lines+line_delta, num_cols};
            }

            dump_binding(b);
          }
          inner_bindings.insert(inner_bindings.begin(), internal_bindings.begin(), internal_bindings.end());
          // hand bindings back to RewriteCallback

          // TODO: this is a hack, do it better
          line_delta += num_lines - (end_line-begin_line);
        }
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
  }

  void onEndOfTranslationUnit() override {
    // binding_rw.overwriteChangedFiles();

    // std::ofstream temp_file(temp_file_name + ".bind_final.cpp");
    //
    // SourceLocation file_begin = context->getSourceManager().getLocForStartOfFile(fid);
    // SourceLocation file_end = context->getSourceManager().getLocForEndOfFile(fid);

    // Rewriter::buffer_iterator buff_iter = binding_rw.buffer_begin();
    const RewriteBuffer* buff = binding_rw.getRewriteBufferFor(fid);
    // binding_rw.overwriteChangedFiles();
    std::error_code erc;
    raw_fd_ostream out(temp_file_name + ".bind_final.cpp", erc);
    // temp_file << binding_rw.getRewrittenText(SourceRange(file_begin, file_end));
    if (buff) {
      buff->write(out);
    }

    out.close();

    num_bind_files++;
    raw_fd_ostream out_numbered(temp_file_name + "." + std::to_string(num_bind_files) + ".bind.cpp", erc);
    if (buff) {
      buff->write(out_numbered);
    }
    out_numbered.close();
    // temp_file.close();
    binding_rw.clearAllRewriteBuffers(binding_rw.getSourceMgr());
    line_delta = 0;
  }

};

std::vector<SourceRange> ReplaceBindingsCallback::past_matches;
int ReplaceBindingsCallback::line_delta = 0;

}
} // namespaces
#endif // REPLACE_BINDINGS_CALLBACK_H
