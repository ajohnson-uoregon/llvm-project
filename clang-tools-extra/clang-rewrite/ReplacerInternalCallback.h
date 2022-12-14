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
    std::vector<Binding> bindings;
    std::vector<Binding> literals;

    explicit ReplacerInternalVisitor(ASTContext* context,
        std::vector<Binding> bindings, std::vector<Binding> literals) :
        context(context), bindings(bindings), literals(literals) {
      internal_rep_rw.setSourceMgr(context->getSourceManager(), context->getLangOpts());
    }

    bool VisitDeclRefExpr(DeclRefExpr* declref) {
      printf("HAHA\n");
      std::string name = declref->getDecl()->getNameAsString();
      std::string qualname = declref->getDecl()->getQualifiedNameAsString();

      for (Binding b : literals) {
        if (qualname == b.qual_name || name == b.name) {
          unsigned int begin_offset = context->getFullLoc(declref->getBeginLoc()).getFileOffset();
          unsigned int end_offset = context->getFullLoc(declref->getEndLoc()).getFileOffset();
          printf("length %u\n", end_offset-begin_offset+1);
          internal_rep_rw.ReplaceText(declref->getBeginLoc(), end_offset-begin_offset+1, b.value);
        }
      }
      for (Binding b : bindings) {
        if (qualname == b.qual_name || name == b.name) {
          unsigned int begin_offset = context->getFullLoc(declref->getBeginLoc()).getFileOffset();
          unsigned int end_offset = context->getFullLoc(declref->getEndLoc()).getFileOffset();
          printf("length %u\n", end_offset-begin_offset+1);
          internal_rep_rw.ReplaceText(declref->getBeginLoc(), end_offset-begin_offset+1, b.value);
        }
      }
      return true;
    }
  };

  class ReplacerInternalCallback : public MatchFinder::MatchCallback {
  public:
    ASTContext* context;
    std::vector<Binding> bindings;
    std::vector<Binding> literals;
    std::string rep_file;
    SourceRange rep_range;

    std::string new_code;

    ReplacerInternalCallback(ASTContext* context, std::vector<Binding> bindings,
        std::vector<Binding> literals, std::string rep_file, SourceRange rep_range) :
      context(context), bindings(bindings), literals(literals), rep_file(rep_file),
      rep_range(rep_range) {}

    void run(const MatchFinder::MatchResult& result) override {
      context = result.Context;

      const Expr* rep = result.Nodes.getNodeAs<Expr>("replacer");

      if (!rep || context->getSourceManager().getFilename(rep->getBeginLoc()) != rep_file) {
        printf("ERROR: invalid inline replacer\n");
        return;
      }

      ReplacerInternalVisitor visitor(context, bindings, literals);
      visitor.TraverseStmt(const_cast<Expr*>(rep));

      // I have to do everything in this house
      unsigned int offset = Lexer::MeasureTokenLength(rep_range.getEnd(), context->getSourceManager(), context->getLangOpts());
      new_code = internal_rep_rw.getRewrittenText(
        CharSourceRange(SourceRange(rep_range.getBegin(), rep_range.getEnd().getLocWithOffset(offset)), false));
      printf("new code\n%s\n", new_code.c_str());
    }
  };


}
}

#endif // CLANG_REWRITE_REPLACER_INTERNAL_CALLBACK_H
