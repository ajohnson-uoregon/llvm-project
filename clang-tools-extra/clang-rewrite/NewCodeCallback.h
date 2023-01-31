#ifndef CLANG_NEW_CODE_CALLBACK_H
#define CLANG_NEW_CODE_CALLBACK_H

#include "llvm/Support/MemoryBufferRef.h"

#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/Lex/Lexer.h"
#include "clang/Lex/Token.h"

#include "CodeAction.h"

#include <string>
#include <vector>

using namespace clang;
using namespace clang::ast_matchers;
using namespace clang::tooling;
using namespace llvm;

namespace clang {
namespace rewrite_tool {

class NewCodeCallback : public MatchFinder::MatchCallback {
public:
  ASTContext *context;
  NewCodeKind kind;
  std::string kind_name = "unknown";
  static std::vector<CodeAction> actions;
  
  void run(const MatchFinder::MatchResult &result) override {
    printf("running NewCodeCallback\n");
  }
};

// subclasses for all types of actions
class InsertPrematchCallback : public NewCodeCallback {
public:
  InsertPrematchCallback() {
    kind = InsertPrematch;
    kind_name = "insert_before_match";
  }
};

class InsertPostmatchCallback : public NewCodeCallback {
public:
  InsertPostmatchCallback() {
    kind = InsertPostmatch;
    kind_name = "insert_after_match";
  }
};

class ReplaceCallback : public NewCodeCallback {
public:
  ReplaceCallback() {
    kind = Replace;
    kind_name = "replace";
  }
};

}
} //namespaces

#endif //CLANG_NEW_CODE_CALLBACK_H
