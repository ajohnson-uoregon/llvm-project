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

class ReplaceBindingsCallback : public MatchFinder::MatchCallback {
public:
  ASTContext* context;
  CodeAction* action;
  Binding bind;
  std::vector<Binding> all_bindings;
  FileID fid;
  static std::vector<SourceRange> past_matches;

  ReplaceBindingsCallback(CodeAction* action, Binding b, std::vector<Binding> bindings)
    : action(action), bind(b), all_bindings(bindings) {}

  void onStartOfTranslationUnit() override {}

  void run(const MatchFinder::MatchResult &result) override {
    printf("running ReplaceBindingsCallback\n");

    context = result.Context;
    binding_rw.setSourceMgr(context->getSourceManager(), context->getLangOpts());

    const Expr* exp = result.Nodes.getNodeAs<Expr>("match");
    const NamedDecl* decl = result.Nodes.getNodeAs<NamedDecl>("match");

    bool expr_valid = true;
    bool decl_valid = true;

    if (!exp ||
        !context->getSourceManager().getFilename(exp->getBeginLoc()).endswith("clang_rewrite_temp_source.cpp.bind.cpp"))
         {
      if (exp) printf("filename??? %s\n", context->getSourceManager().getFilename(exp->getBeginLoc()).str().c_str());
      printf("ERROR: invalid expr binding match loc\n");
      expr_valid = false;
    }

    if (!decl ||
        !context->getSourceManager().getFilename(decl->getBeginLoc()).endswith("clang_rewrite_temp_source.cpp.bind.cpp")) {
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

    if (std::find(past_matches.begin(), past_matches.end(), match_range) != past_matches.end()) {
      printf("duplicate match\n");
      return;
    }
    else {
      past_matches.push_back(match_range);
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

    fid = begin.getFileID();
    unsigned int begin_offset = begin.getFileOffset();
    unsigned int end_offset = end.getFileOffset();
    unsigned int match_offset = match.getFileOffset();

    if (begin_offset == end_offset) {
      printf("one char match, luls\n");
      end_offset += 1;
    }

    llvm::Optional<llvm::MemoryBufferRef> buff =
      context->getSourceManager().getBufferOrNone(fid);

    if (expr_valid) {
      printf("expr\n");
      exp->dump();

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
    // std::ofstream temp_file(temp_file_name + ".bind_final.cpp");
    //
    // SourceLocation file_begin = context->getSourceManager().getLocForStartOfFile(fid);
    // SourceLocation file_end = context->getSourceManager().getLocForEndOfFile(fid);

    // Rewriter::buffer_iterator buff_iter = binding_rw.buffer_begin();
    const RewriteBuffer* buff = binding_rw.getRewriteBufferFor(fid);
    std::error_code erc;
    raw_fd_ostream out(temp_file_name + ".bind_final.cpp", erc);
    // temp_file << binding_rw.getRewrittenText(SourceRange(file_begin, file_end));
    buff->write(out);
    out.close();
    // temp_file.close();
  }

};

std::vector<SourceRange> ReplaceBindingsCallback::past_matches;

}
} // namespaces
#endif // REPLACE_BINDINGS_CALLBACK_H
