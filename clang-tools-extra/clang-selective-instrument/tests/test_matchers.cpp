#ifndef TEST_MATCHERS
#define TEST_MATCHERS

#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang;
using namespace clang::ast_matchers;


StatementMatcher LoopCondMatcher =
  forStmt(hasCondition(
    binaryOperator(hasOperatorName("<"),
      hasLHS(ignoringParenImpCasts(declRefExpr(to(varDecl().bind("lhs"))))),
      hasRHS(ignoringParenImpCasts(declRefExpr(to(varDecl().bind("rhs")))))
    ).bind("match"))).bind("root");

StatementMatcher ReturnIntMatcher =
  returnStmt(hasReturnValue(integerLiteral().bind("retval"))).bind("match");

StatementMatcher ThenMatcher =
  ifStmt(hasThen(compoundStmt().bind("match"))).bind("root");

DeclarationMatcher IntDeclMatcher =
  varDecl(hasType(asString("int"))).bind("match");

DeclarationMatcher AddMatcher =
  functionDecl(allOf(
    matchesName("add*"),
    parameterCountIs(2)
  ));

#endif
