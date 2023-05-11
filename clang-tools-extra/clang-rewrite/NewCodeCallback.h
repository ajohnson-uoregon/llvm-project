#ifndef CLANG_NEW_CODE_CALLBACK_H
#define CLANG_NEW_CODE_CALLBACK_H

#include "llvm/Support/MemoryBufferRef.h"

#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/Lex/Lexer.h"
#include "clang/Lex/Token.h"

#include "CodeAction.h"
#include "SetupCallback.h"

#include <string>
#include <vector>

using namespace clang;
using namespace clang::ast_matchers;
using namespace clang::tooling;
using namespace llvm;

namespace clang {
namespace rewrite_tool {

DeclarationMatcher insert_before_match =
  functionDecl(allOf(
    hasAttr(attr::InsertCodeBefore),
    hasBody(compoundStmt(allOf(
      optionally(hasAnySubstatement(declStmt(
        containsAnyDeclaration(varDecl(hasAttr(attr::RewriteSetup)))
      ).bind("setup"))),
      hasAnySubstatement(attributedStmt(allOf(
        hasAttr(attr::MatcherBlock),
        hasSubStmt(compoundStmt(anything()))
      )).bind("body"))
    )))
  )).bind("insert_before_match");

DeclarationMatcher insert_after_match =
  functionDecl(allOf(
    hasAttr(attr::InsertCodeAfter),
    hasBody(compoundStmt(allOf(
      optionally(hasAnySubstatement(declStmt(
        containsAnyDeclaration(varDecl(hasAttr(attr::RewriteSetup)))
      ).bind("setup"))),
      hasAnySubstatement(attributedStmt(allOf(
        hasAttr(attr::MatcherBlock),
        hasSubStmt(compoundStmt(anything()))
      )).bind("body"))
    )))
  )).bind("insert_after_match");

DeclarationMatcher replace_match =
  functionDecl(allOf(
    hasAttr(attr::ReplaceCode),
    hasBody(compoundStmt(allOf(
      optionally(hasAnySubstatement(declStmt(
        containsAnyDeclaration(varDecl(hasAttr(attr::RewriteSetup)))
      ).bind("setup"))),
      hasAnySubstatement(attributedStmt(allOf(
        hasAttr(attr::MatcherBlock),
        hasSubStmt(compoundStmt(anything()))
      )).bind("body"))
    )))
  )).bind("replace");


std::vector<CodeAction *> all_actions;

class NewCodeCallback : public MatchFinder::MatchCallback {
public:
  ASTContext *context;
  NewCodeKind kind;
  std::string kind_name = "unknown";
  static std::vector<CodeAction> actions;

  void run(const MatchFinder::MatchResult &result) override {
    printf("running NewCodeCallback\n");

    context = result.Context;

    const FunctionDecl *func = result.Nodes.getNodeAs<FunctionDecl>(kind_name);

    if (!func ||
        !context->getSourceManager().isWrittenInMainFile(func->getBeginLoc())) {
      printf("ERROR: invalid function definition in transformation\n");
      return;
    }

    FullSourceLoc begin = context->getFullLoc(func->getBeginLoc());
    FullSourceLoc end = context->getFullLoc(func->getEndLoc());
    unsigned int begin_line = begin.getSpellingLineNumber();
    unsigned int begin_col = begin.getSpellingColumnNumber();
    unsigned int end_line = end.getSpellingLineNumber();
    unsigned int end_col = end.getSpellingColumnNumber();

    std::string action_name = func->getNameAsString();

    printf("FOUND %s action called %s at %d:%d - %d:%d\n", kind_name.c_str(),
           action_name.c_str(), begin_line, begin_col, end_line, end_col);

    // grab all matcher names, put in list
    std::vector<std::string> matcher_names;
    for (Attr* attr : func->attrs()) {
      switch(attr->getKind()) {
        case attr::ReplaceCode:
          for (StringRef m : cast<ReplaceCodeAttr>(attr)->matchers()) {
            // llvm::outs() << m << "\n";
            matcher_names.push_back(m.str());
          }
          break;
        case attr::InsertCodeAfter:
          for (StringRef m : cast<InsertCodeAfterAttr>(attr)->matchers()) {
            // llvm::outs() << m << "\n";
            matcher_names.push_back(m.str());
          }
          break;
        case attr::InsertCodeBefore:
          for (StringRef m : cast<InsertCodeBeforeAttr>(attr)->matchers()) {
            // llvm::outs() << m << "\n";
            matcher_names.push_back(m.str());
          }
          break;
        default:
          break;
      }
    }

    // grab body of matcher_block attr as new code
    const AttributedStmt* body = result.Nodes.getNodeAs<AttributedStmt>("body");
    if (!body || !context->getSourceManager().isWrittenInMainFile(body->getBeginLoc())) {
      printf("ERROR: invalid body\n");
      return;
    }
    // printf("function body\n");
    // body->dump();

    FullSourceLoc body_begin = context->getFullLoc(body->getBeginLoc());
    FullSourceLoc body_end = context->getFullLoc(body->getEndLoc());

    FileID fid = body_begin.getFileID();
    unsigned int begin_offset = body_begin.getFileOffset();
    unsigned int end_offset = body_end.getFileOffset();

    printf("begin offset %u\n", begin_offset);
    printf("end offset   %u\n", end_offset);
    printf("array length %u\n", end_offset - begin_offset);

    std::optional<llvm::MemoryBufferRef> buff =
        context->getSourceManager().getBufferOrNone(fid);

    char *body_code_c = new char[end_offset - begin_offset + 2];
    if (buff.has_value()) {
      memcpy(body_code_c, &(buff->getBufferStart()[begin_offset]),
             (end_offset - begin_offset + 2) * sizeof(char));
      body_code_c[end_offset - begin_offset + 1] =
          '\0'; // force null terminated for Reasons
      printf("body code??? %s\n", body_code_c);
    } else {
      printf("no buffer :<\n");
    }

    std::string body_code(body_code_c);
    delete[] body_code_c;

    // grab setup code
    // TODO: make yet another callback to go searching for all setup code in range
    StatementMatcher setup_match =
      declStmt(containsAnyDeclaration(varDecl(
        hasAttr(attr::RewriteSetup)
      ))).bind("setup");

    SetupCallback setupcb({begin_line, begin_col, end_line, end_col});
    MatchFinder setup_finder;

    setup_finder.addMatcher(setup_match, &setupcb);

    int retval = Tool->run(newFrontendActionFactory(&setup_finder).get());

    std::string setup_code = setupcb.setup_code;

    CodeAction *act =
        new CodeAction(body_code, setup_code, action_name, kind, matcher_names,
          context->getSourceManager().getFilename(func->getBeginLoc()).str(),
          SourceRange(body_begin,
                      body_end));
    all_actions.push_back(act);

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
