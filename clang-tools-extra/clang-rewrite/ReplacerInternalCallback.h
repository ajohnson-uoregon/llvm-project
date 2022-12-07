#ifndef CLANG_REWRITE_REPLACER_INTERNAL_CALLBACK_H
#define CLANG_REWRITE_REPLACER_INTERNAL_CALLBACK_H

#include "clang/Frontend/FrontendActions.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"

#include "clang/AST/ASTContext.h"
// #include "clang/AST/DeclTemplate.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/Lex/Lexer.h"
#include "clang/Lex/Token.h"
#include "clang/Rewrite/Core/RewriteBuffer.h"
#include "clang/Rewrite/Core/Rewriter.h"

#include "ClangRewriteUtils.h"
#include "RewriteInternalCallback.h"

#include <string>
#include <vector>

using namespace clang;
using namespace clang::ast_matchers;

using namespace clang::tooling;
using namespace llvm;

namespace clang {
namespace rewrite_tool {
  class ReplacerInternalVisitor : public RecursiveASTVisitor<ReplacerInternalVisitor> {
  public:
    ASTContext* context;
    Rewriter file_rw;

    explicit ReplacerInternalVisitor(ASTContext* context, Rewriter& file_rw) :
      context(context), file_rw(file_rw) {}

    bool VisitDeclRefExpr(DeclRefExpr* declref) {
      printf("HAHA\n");
      return false;
    }
  };

  class ReplacerInternalCallback : public MatchFinder::MatchCallback {
  public:
    static Rewriter file_rw;
    ASTContext* context;
    std::vector<Binding> bindings;
    std::vector<Binding> literals;
    std::string orig_file;

    ReplacerInternalCallback(ASTContext* context, std::vector<Binding> bindings,
        std::vector<Binding> literals, std::string orig_file) :
      context(context), bindings(bindings), literals(literals), orig_file(orig_file) {}

    void run(const MatchFinder::MatchResult& result) override {
      context = result.Context;
      file_rw.setSourceMgr(context->getSourceManager(), context->getLangOpts());

      const Expr* rep = result.Nodes.getNodeAs<Expr>("replacer");

      if (!rep || context->getSourceManager().getFilename(rep->getBeginLoc()) != orig_file) {
        printf("ERROR: invalid inline replacer\n");
        return;
      }

      ReplacerInternalVisitor visitor(context, file_rw);
      visitor.TraverseStmt(const_cast<Expr*>(rep));
    }
  };

  Rewriter ReplacerInternalCallback::file_rw;
}
}

#endif // CLANG_REWRITE_REPLACER_INTERNAL_CALLBACK_H
