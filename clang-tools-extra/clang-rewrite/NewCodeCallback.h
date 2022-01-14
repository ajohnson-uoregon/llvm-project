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

DeclarationMatcher insert_before_match =
  functionDecl(allOf(
    hasAttr(attr::InsertCodeBefore),
    hasBody(compoundStmt(
      hasAnySubstatement(attributedStmt(allOf(
        isAttr(attr::MatcherBlock),
        hasSubStmt(compoundStmt(anything()).bind("body"))
      )))
    ))
  )).bind("insert_before_match");

DeclarationMatcher insert_after_match =
  functionDecl(allOf(
    hasAttr(attr::InsertCodeAfter),
    hasBody(compoundStmt(
      hasAnySubstatement(attributedStmt(allOf(
        isAttr(attr::MatcherBlock),
        hasSubStmt(compoundStmt(anything()).bind("body"))
      )))
    ))
  )).bind("insert_after_match");

DeclarationMatcher replace_match =
  functionDecl(allOf(
    hasAttr(attr::ReplaceCode),
    hasBody(compoundStmt(
      hasAnySubstatement(attributedStmt(allOf(
        isAttr(attr::MatcherBlock),
        hasSubStmt(compoundStmt(anything()).bind("body"))
      )))
    ))
  )).bind("replace");



std::vector<CodeAction *> all_actions;

class NewCodeCallback : public MatchFinder::MatchCallback {
public:
  ASTContext *context;
  NewCodeKind kind;
  std::string kind_name = "unknown";
  static std::vector<CodeAction> actions;

  void run(const MatchFinder::MatchResult &result) override {
    printf("run the thing!\n");
    context = result.Context;

    const FunctionDecl *func = result.Nodes.getNodeAs<FunctionDecl>(kind_name);

    if (!func ||
        !context->getSourceManager().isWrittenInMainFile(func->getBeginLoc())) {
      printf("ERROR: invalid function definition.\n");
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
      attr->printPretty(llvm::outs(), PrintingPolicy(context->getLangOpts()));
      printf("\n");
      switch(attr->getKind()) {
        case attr::ReplaceCode:
          for (StringRef m : cast<ReplaceCodeAttr>(attr)->matchers()) {
            llvm::outs() << m << "\n";
            matcher_names.push_back(m.str());
          }
          break;
        case attr::InsertCodeAfter:
          for (StringRef m : cast<InsertCodeAfterAttr>(attr)->matchers()) {
            llvm::outs() << m << "\n";
            matcher_names.push_back(m.str());
          }
          break;
        case attr::InsertCodeBefore:
          for (StringRef m : cast<InsertCodeBeforeAttr>(attr)->matchers()) {
            llvm::outs() << m << "\n";
            matcher_names.push_back(m.str());
          }
          break;
        default:
          break;
      }

    }

    // grab function body as new code
    const CompoundStmt* body = result.Nodes.getNodeAs<CompoundStmt>("body");
    if (!body || !context->getSourceManager().isWrittenInMainFile(body->getBeginLoc())) {
      printf("ERROR: invalid body\n");
      return;
    }
    printf("function body\n");
    body->dump();

    FullSourceLoc body_begin;
    FullSourceLoc body_end;
    if (!body->body_empty()) {
      body_begin = context->getFullLoc(body->body_front()->getBeginLoc());

      // go to end of line; stmts don't work, gotta lex to the end of the line
      SourceLocation eol = Lexer::getLocForEndOfToken(
          body->body_back()->getBeginLoc(), 0, context->getSourceManager(),
          context->getLangOpts());
      Optional<Token> tok = Lexer::findNextToken(
          eol, context->getSourceManager(), context->getLangOpts());
      while (tok.hasValue() && tok->isNot(clang::tok::semi)) {
        tok = Lexer::findNextToken(eol, context->getSourceManager(),
                                   context->getLangOpts());
        eol = tok->getLocation();
      }
      // TODO: this is a hack and we should be smarter about semicolons
      if (kind != Replace) {
        eol = tok->getEndLoc(); // grab semicolon
      }
      body_end = context->getFullLoc(eol);
    }
    else { // empty body just use brackets
      body_begin = context->getFullLoc(body->getLBracLoc());
      body_end = context->getFullLoc(body->getRBracLoc());
    }

    FileID fid = body_begin.getFileID();
    unsigned int begin_offset = body_begin.getFileOffset();
    unsigned int end_offset = body_end.getFileOffset();

    printf("begin offset %u\n", begin_offset);
    printf("end offset   %u\n", end_offset);
    printf("array length %u\n", end_offset - begin_offset);

    llvm::Optional<llvm::MemoryBufferRef> buff =
        context->getSourceManager().getBufferOrNone(fid);

    char *code = new char[end_offset - begin_offset + 1];
    if (buff.hasValue()) {
      memcpy(code, &(buff->getBufferStart()[begin_offset]),
             (end_offset - begin_offset + 1) * sizeof(char));
      code[end_offset - begin_offset] =
          '\0'; // force null terminated for Reasons
      printf("code??? %s\n", code);
    } else {
      printf("no buffer :<\n");
    }

    // make action, put in vector of actions
    CodeAction *act =
        new CodeAction(kind, matcher_names, std::string(code), action_name, context->getLangOpts());
    all_actions.push_back(act);

    delete[] code;
  }

private:
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


#endif
