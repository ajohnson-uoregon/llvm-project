#ifndef CLANG_REWRITE_CODE_LITERALS_CALLBACK_H
#define CLANG_REWRITE_CODE_LITERALS_CALLBACK_H

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

#include "CodeAction.h"
#include "MatcherWrapper.h"
#include "ClangRewriteUtils.h"
#include "MatcherGenCallback.h"
#include "ReplaceBindingsCallback.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace clang;
using namespace clang::ast_matchers;

using namespace clang::tooling;
using namespace llvm;

namespace clang {
namespace rewrite_tool {

class CodeLiteralsVisitor : public RecursiveASTVisitor<CodeLiteralsVisitor> {
public:
  std::vector<std::string> strings = {};
  std::vector<Binding>* bindings;

  explicit CodeLiteralsVisitor(std::vector<Binding>* bindings) :
  bindings(bindings) {}

  bool VisitStringLiteral(StringLiteral* str) {
    strings.push_back(str->getString().str());
    return true;
  }

  bool VisitDeclRefExpr(DeclRefExpr* ref) {
    ValueDecl* decl = ref->getDecl();
    std::string name = decl->getNameAsString();
    std::string qualname = decl->getQualifiedNameAsString();
    printf("found declrefexpr %s (%s)\n", name.c_str(), qualname.c_str());

    for (Binding b : *bindings) {
      printf("binding: %s (%s)\n", b.name.c_str(), b.qual_name.c_str());
      if (name == b.name || qualname == b.qual_name) {
        printf("found matching binding: %s\n", b.value.c_str());
        strings.push_back(b.value);
        return true;
      }
    }
    printf("ERROR: no matching binding for to_str %s\n", name.c_str());
    strings.push_back(name);

    return true;
  }
};

class CodeLiteralsCallback : public MatchFinder::MatchCallback {
public:
  ASTContext* context;
  std::vector<Binding>* bindings;

  CodeLiteralsCallback(std::vector<Binding>* bindings) :
    bindings(bindings) {}

  void run(const MatchFinder::MatchResult &result) override {
    printf("running code literals callback\n");

    context = result.Context;

    const CallExpr* literal_call = result.Nodes.getNodeAs<CallExpr>("code_literal_call");

    if (!literal_call || !context->getSourceManager().isWrittenInMainFile(literal_call->getBeginLoc())) {
      printf("ERROR: invalid code literal call location\n");
      return;
    }

    const VarDecl* literal_decl = result.Nodes.getNodeAs<VarDecl>("code_literal_decl");

    if (!literal_decl || !context->getSourceManager().isWrittenInMainFile(literal_decl->getBeginLoc())) {
      printf("ERROR: invalid code literal decl location\n");
      return;
    }

    const Expr* arg = literal_call->getArg(0);
    arg->dump();

    CodeLiteralsVisitor visitor(bindings);

    visitor.TraverseStmt(const_cast<Expr*>(arg));

    std::string new_name = "";
    for (std::string str : visitor.strings) {
      new_name += str;
    }

    printf("NEW NAME %s\n", new_name.c_str());

    Binding b;
    b.name = literal_decl->getNameAsString();
    b.qual_name = literal_decl->getQualifiedNameAsString();
    b.value = new_name;

    // DO NOT attempt to create the matchers here, it gives SUPER WEIRD ERRORS
    // probably due to StringRefs being tied to this ASTContext, so when it
    // gets destructed with them still having active references, everything implodes

    b.kind = BindingKind::VarNameBinding;

    bindings->push_back(b);
  }
};

}
} // namespaces

#endif // CLANG_REWRITE_CODE_LITERALS_CALLBACK_H
