#ifndef CLANG_FIND_LITERALS_CALLBACK_H
#define CLANG_FIND_LITERALS_CALLBACK_H

#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchersInternal.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/AST/Type.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/Tooling.h"

#include <string>
#include <vector>

namespace clang {
namespace rewrite_tool {


std::vector<std::string> clang_rewrite_literals;

DeclarationMatcher literal_vector = varDecl(hasName("clang_rewrite_literal_names")).bind("literals");

class FindLiteralsCallback : public MatchFinder::MatchCallback {
public:
  ASTContext* context;

  void run(const MatchFinder::MatchResult& result) override {
    printf("found literal array\n");
    context = result.Context;

    const VarDecl* lit = result.Nodes.getNodeAs<VarDecl>("literals");

    if (!lit || !context->getSourceManager().isWrittenInMainFile(lit->getBeginLoc())) {
      printf("ERROR: invalid matcher definition\n");
      return;
    }
    // printf("full literal decl\n");
    // lit->dump();

    findStringChildren(lit->getInit(), clang_rewrite_literals);

    printf("found literals:\n");
    for (std::string s : clang_rewrite_literals) {
      printf("  %s\n", s.c_str());
    }
  }

  // void findStringChildren(const VarDecl *decl, std::vector<std::string> &strings) {
  //   for (auto child : decl->getInit()->children()) {
  //     // specify *CLANG* StringLiteral to not overlap with llvm StringLiteral
  //     if (auto *str = dyn_cast<clang::StringLiteral>(child)) {
  //       strings.push_back(str->getString().str());
  //     } else {
  //       findStringChildren(child, strings);
  //     }
  //   }
  // }

  void findStringChildren(const Stmt *stmt, std::vector<std::string> &strings) {
    for (auto child : stmt->children()) {
      // specify *CLANG* StringLiteral to not overlap with llvm StringLiteral
      if (auto *str = dyn_cast<clang::StringLiteral>(child)) {
        strings.push_back(str->getString().str());
      } else {
        findStringChildren(child, strings);
      }
    }
  }
};

}
} //namespaces

#endif // CLANG_FIND_LITERALS_CALLBACK_H
