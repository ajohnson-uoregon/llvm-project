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

using namespace clang;
using namespace clang::ast_matchers;

using namespace clang::tooling;
using namespace llvm;

namespace clang {
namespace rewrite_tool {

class ReplaceBindingsCallback : public MatchFinder::MatchCallback {
public:

  void onStartOfTranslationUnit() override {}

  void run(const MatchFinder::MatchResult &result) override {
    printf("running ReplaceBindingsCallback\n");
  }

  void onEndOfTranslationUnit() override {}

};

}
} // namespaces
#endif // REPLACE_BINDINGS_CALLBACK_H
