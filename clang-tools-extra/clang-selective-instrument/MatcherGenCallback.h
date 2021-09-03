#ifndef CLANG_MATCHER_GEN_CALLBACK_H
#define CLANG_MATCHER_GEN_CALLBACK_H

#include "llvm/Support/MemoryBufferRef.h"

#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/Lex/Lexer.h"
#include "clang/Lex/Token.h"

#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/AST/Type.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/Tooling.h"

#include "CodeAction.h"

#include <string>
#include <vector>
#include <unordered_map>

using namespace clang;
using namespace clang::ast_matchers;

using namespace clang::tooling;
using namespace llvm;

class BuildMatcherVisitor : public RecursiveASTVisitor<BuildMatcherVisitor> {
public:
  explicit BuildMatcherVisitor(ASTContext* context)
    : context(context) {}

    std::string get_matcher() {
      return matcher;
    }

    bool VisitCompoundStmt(CompoundStmt* comp) {
      // everything is wrapped in a CompoundStmt, so if we haven't seen
      // anything else, ignore it
      if (insert_point == 0) {
        return true;
      }
      else {
        update_matcher("compoundStmt()", 1);
        return true;
      }
    }

    bool VisitReturnStmt(ReturnStmt* ret) {
      update_matcher("returnStmt(hasReturnValue())", 2);
      return true;
    }

    bool VisitImplicitCastExpr(ImplicitCastExpr* expr) {
      update_matcher("ignoringParenImpCasts()", 1);
      return true;
    }

    bool VisitDeclRefExpr(DeclRefExpr* ref) {
      ValueDecl* decl = ref->getDecl();
      std::string name = decl->getNameAsString();
      if (decl->getType()->getTypeClass() != clang::Type::TypeClass::Auto) {
        std::string typeclass = decl->getType().getAsString();
        update_matcher("allOf(hasType(\"" + typeclass + "\"), expr().bind(\"" + name + "\"))", 0);
      }
      else {
        update_matcher("expr().bind(\"" + name + "\")", 0);
      }
      return true;
    }

private:
  ASTContext* context;
  std::string matcher = "";
  int insert_point = 0;
  int bind_point = 0;

  void update_matcher(std::string code, int sub) {
    matcher.insert(insert_point, code);
    insert_point += code.length() - sub;
    printf("%s\n", matcher.c_str());
    printf("new insert pt: %d\n", insert_point);
  }
};


DeclarationMatcher matcher =
  functionDecl(allOf(
    hasAttr(attr::Matcher),
    hasBody(compoundStmt(
      hasAnySubstatement(compoundStmt(anything()).bind("body"))
    ))
  )).bind("matcher");

std::unordered_map<std::string, std::string> stmt_matchers;

class MatcherGenCallback : public MatchFinder::MatchCallback {
public:
  ASTContext* context;
  std::string matcher_name;

  void run(const MatchFinder::MatchResult& result) override {
    printf("found matcher\n");
    context = result.Context;

    const FunctionDecl* func = result.Nodes.getNodeAs<FunctionDecl>("matcher");

    if (!func || !context->getSourceManager().isWrittenInMainFile(func->getBeginLoc())) {
      printf("ERROR: invalid matcher definition\n");
      return;
    }
    printf("full function\n");
    func->dump();

    FullSourceLoc begin = context->getFullLoc(func->getBeginLoc());
    FullSourceLoc end = context->getFullLoc(func->getEndLoc());
    unsigned int begin_line = begin.getSpellingLineNumber();
    unsigned int begin_col = begin.getSpellingColumnNumber();
    unsigned int end_line = end.getSpellingLineNumber();
    unsigned int end_col = end.getSpellingColumnNumber();

    for (Attr* attr : func->attrs()) {
      if (attr->getKind() == attr::Matcher) {
        StringRef name = cast<MatcherAttr>(attr)->getMatcherName();
        matcher_name = name.str();
      }
    }
    printf("FOUND matcher %s at %d:%d - %d:%d\n", matcher_name.c_str(), begin_line, begin_col, end_line, end_col);

    const CompoundStmt* body = result.Nodes.getNodeAs<CompoundStmt>("body");
    if (!body || !context->getSourceManager().isWrittenInMainFile(body->getBeginLoc())) {
      printf("ERROR: invalid body\n");
      return;
    }
    printf("function body\n");
    body->dump();

    BuildMatcherVisitor visitor(context);

    visitor.TraverseStmt(const_cast<CompoundStmt*>(body));

    std::string matcher = visitor.get_matcher();

    printf("final matcher:\n\t%s\n", matcher.c_str());

  }
};

#endif
