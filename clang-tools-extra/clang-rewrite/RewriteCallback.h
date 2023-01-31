#ifndef CLANG_REWRITE_CALLBACK_H
#define CLANG_REWRITE_CALLBACK_H

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

class DumpCallback : public MatchFinder::MatchCallback {
public:
  void run(const MatchFinder::MatchResult &result) override {

    const TranslationUnitDecl* tudecl = result.Nodes.getNodeAs<TranslationUnitDecl>("tudecl");

    if (!tudecl) {
      printf("ERROR: bad tudecl\n");
      return;
    }
    else {
      tudecl->dump();
    }
  }
};

template <class T>
class RewriteCallback : public MatchFinder::MatchCallback {
public:
  RewriteCallback(MatcherWrapper<T> *matcher) : matcher(matcher) {}

  ~RewriteCallback() {}

  void onStartOfTranslationUnit() override {}

  void run(const MatchFinder::MatchResult &result) override {
    printf("running RewriteCallback\n");
  }

  void onEndOfTranslationUnit() override {}
};
}
}// namespaces

#endif //CLANG_REWRITE_CALLBACK_H
