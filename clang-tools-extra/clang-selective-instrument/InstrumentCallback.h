#ifndef CLANG_INSTRUMENT_CALLBACK_H
#define CLANG_INSTRUMENT_CALLBACK_H

#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/AST/ASTContext.h"
#include "clang/Lex/Lexer.h"
#include "clang/Lex/Token.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/Rewrite/Core/RewriteBuffer.h"

#include "MatcherWrapper.h"
#include "CodeAction.h"

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace clang;
using namespace clang::ast_matchers;

using namespace clang::tooling;
using namespace llvm;

bool isLine(const Stmt* stmt) {
  if (isa<AsmStmt>(stmt) ||
      isa<NullStmt>(stmt) ||
      isa<ReturnStmt>(stmt) ||
      isa<ValueStmt>(stmt) // exprs
    ) {
    return true;
  }
  else {
    return false;
  }
}

bool isBlock(const Stmt* stmt) {
  if (isa<CompoundStmt>(stmt) ||
      isa<CoroutineBodyStmt>(stmt) ||
      isa<CXXCatchStmt>(stmt) ||
      isa<CXXForRangeStmt>(stmt) ||
      isa<CXXTryStmt>(stmt) ||
      isa<DoStmt>(stmt) ||
      isa<ForStmt>(stmt) ||
      isa<IfStmt>(stmt) ||
      isa<SwitchCase>(stmt) ||
      isa<SwitchStmt>(stmt) ||
      isa<WhileStmt>(stmt)
    ) {
    return true;
  }
  else {
    return false;
  }
}

// TODO:
// - DeclStmt
// - IndirectGotoStmt


// template <class T>
// class MatcherWrapper;
//
// class CodeAction;

template <class T>
class InstrumentCallback : public MatchFinder::MatchCallback {
public:
  static Rewriter rw;
  ASTContext* context;
  static int num_matched;
  static std::vector<FileID> files_changed;
  MatcherWrapper<T>* matcher;
  static bool verbose;
  static bool rewrite_file;

  InstrumentCallback(MatcherWrapper<T>* matcher) : matcher(matcher) {}

  ~InstrumentCallback() {}

  void onStartOfTranslationUnit() override {

  }

  void runActions(const MatchFinder::MatchResult& result, const Stmt* match) {
    // printf("run actions\n");
    for (CodeAction* action : matcher->actions) {
      switch (action->kind) {
        case InsertPrematch:
          addBeforeCode(match, result, action->code_snippet);
          break;
        case InsertPostmatch:
          addAfterCode(match, result, action->code_snippet);
          break;
        case Replace:
          // printf("WARNING: replacing code is not yet implemented.\n");
          replaceCode(match, result, action->code_snippet);
          break;
        default:
          printf("ERROR: unknown action kind\n");
      }
    }
  }

  void run(const MatchFinder::MatchResult& result) override {
    context = result.Context;
    rw.setSourceMgr(context->getSourceManager(), context->getLangOpts());

    const Stmt* match = result.Nodes.getNodeAs<Stmt>("match");

    if (!match || !context->getSourceManager().isWrittenInMainFile(match->getBeginLoc())) {
      return;
    }

    FullSourceLoc begin = context->getFullLoc(match->getBeginLoc());
    FullSourceLoc end = context->getFullLoc(match->getEndLoc());
    unsigned int begin_line = begin.getSpellingLineNumber();
    unsigned int begin_col = begin.getSpellingColumnNumber();
    unsigned int end_line = end.getSpellingLineNumber();
    unsigned int end_col = end.getSpellingColumnNumber();

    if (verbose) {
      printf("FOUND match for %s at %d:%d - %d:%d\n", matcher->getName().c_str(),
        begin_line, begin_col, end_line, end_col);
    }
    if (rw.isRewritable(match->getBeginLoc()) && rw.isRewritable(match->getEndLoc())) {
      // printf("is rewritable\n");

      runActions(result, match);
      // addBeforeCode(match, result);
      // addAfterCode(match, result);

      const RewriteBuffer* buff = rw.getRewriteBufferFor(rw.getSourceMgr().getFileID(match->getBeginLoc()));
      if (buff) {
        std::error_code erc;
        std::string newfname = rw.getSourceMgr().getFilename(match->getBeginLoc()).str();
        if (newfname.find(".") != std::string::npos) {
          std::string temp = ".test";
          temp.append(std::to_string(num_matched));
          newfname.insert(newfname.find("."), temp);
        }
        else {
          newfname.append(".test").append(std::to_string(num_matched));
        }

        if (verbose) {
          printf("%s\n", newfname.c_str());
        }
        raw_fd_ostream out(newfname, erc);
        buff->write(out);
        out.close();
        files_changed.push_back(rw.getSourceMgr().getFileID(match->getBeginLoc()));
        num_matched++;
      }
    }
  }

  void onEndOfTranslationUnit() override {
    // printf("dump\n");
    // llvm::outs() << rw.getRewrittenText(context->getTranslationUnitDecl()->getSourceRange());
    // clear out duplicates
    std::sort(files_changed.begin(), files_changed.end());
    auto new_end = std::unique(files_changed.begin(), files_changed.end());
    files_changed.erase(new_end, files_changed.end());

    for (FileID f : files_changed) {
      const RewriteBuffer* buff = rw.getRewriteBufferFor(f);
      std::error_code erc;
      std::string newfname = rw.getSourceMgr().getFileEntryForID(f)->getName().str();
      if (newfname.find(".") != std::string::npos) {
        std::string temp = ".test_final";
        newfname.insert(newfname.find("."), temp);
      }
      else {
        newfname.append(".test_final");
      }

      if (verbose) {
        printf("%s\n", newfname.c_str());
      }
      raw_fd_ostream out(newfname, erc);
      buff->write(out);
      out.close();
    }

    files_changed.clear();
  }


  void checkedInsertTextAfterToken(const MatchFinder::MatchResult& result, SourceLocation loc, std::string text, bool isBeforeCode = false) {
    if ((isBeforeCode && locValidForCodeInsertBefore(result)) || (!isBeforeCode && locValidForCodeInsertAfter(result))) {
      rw.InsertTextAfterToken(loc, text.c_str());
    }
    else {
      FullSourceLoc full_loc = context->getFullLoc(loc);
      unsigned int line = full_loc.getSpellingLineNumber();
      unsigned int col = full_loc.getSpellingColumnNumber();
      if (verbose) {
        printf("WARNING: location %d:%d not valid for code insertion, skipping\n", line, col);
      }

    }
  }

  void checkedInsertTextBefore(const MatchFinder::MatchResult& result, SourceLocation loc, std::string text, bool isBeforeCode = false) {
    if ((isBeforeCode && locValidForCodeInsertBefore(result)) || (!isBeforeCode && locValidForCodeInsertAfter(result))) {
      rw.InsertTextBefore(loc, text.c_str());
    }
    else {
      FullSourceLoc full_loc = context->getFullLoc(loc);
      unsigned int line = full_loc.getSpellingLineNumber();
      unsigned int col = full_loc.getSpellingColumnNumber();
      if (verbose) {
        printf("WARNING: location %d:%d not valid for code insertion, skipping\n", line, col);
      }
    }
  }

  void addBeforeCode(const Stmt* match, const MatchFinder::MatchResult& result, std::string beforetxt) {

    if (auto* comp = dyn_cast<CompoundStmt>(match)) {
      checkedInsertTextAfterToken(result, comp->getLBracLoc(), beforetxt, true);
    }
    else {
      checkedInsertTextBefore(result, match->getBeginLoc(), beforetxt, true);
    }
  }

  void addAfterCode(const Stmt* match, const MatchFinder::MatchResult& result, std::string aftertxt) {

    if (isBlock(match)) {
      if (auto* comp = dyn_cast<CompoundStmt>(match)) {
        checkedInsertTextBefore(result, comp->getRBracLoc(), aftertxt);
      }
      else{
        checkedInsertTextAfterToken(result, match->getEndLoc(), aftertxt);
      }
    }
    else if (isLine(match)) {
      // go to end of line
      SourceLocation eol = Lexer::getLocForEndOfToken(match->getBeginLoc(), 0, context->getSourceManager(), context->getLangOpts());
      Optional<Token> tok = Lexer::findNextToken(eol, context->getSourceManager(), context->getLangOpts());
      // printf("tok %s\n", tok->getName());
      while (tok.hasValue() && tok->isNot(clang::tok::semi)) {
        tok = Lexer::findNextToken(eol, context->getSourceManager(), context->getLangOpts());
        eol = tok->getLocation();
        // printf("tok %s\n", tok->getName());
      }
      // insert call after that
      checkedInsertTextAfterToken(result, eol, aftertxt.c_str());
    }
    else {
      if (verbose) {
        printf("WARNING: unhandled location type, treating as block\n");
      }
      checkedInsertTextAfterToken(result, match->getEndLoc(), aftertxt.c_str());
    }
  }

  void replaceCode(const Stmt* match, const MatchFinder::MatchResult& result, std::string replacetxt) {

    // TODO: verify all things for blocks
    Rewriter::RewriteOptions opts;
    opts.IncludeInsertsAtBeginOfRange = false;
    if (isBlock(match)) {
      if (auto* comp = dyn_cast<CompoundStmt>(match)) {
        rw.ReplaceText(SourceRange(comp->getLBracLoc(), comp->getRBracLoc()), replacetxt, opts);
      }
      else {
        // TODO: verify, it can't be this simple
        rw.ReplaceText(SourceRange(match->getBeginLoc(), match->getEndLoc()), replacetxt, opts);
      }
    }
    else if (isLine(match)) {
      printf("waaaaaaaaaaaaat\n");
      match->getBeginLoc().dump(result.Context->getSourceManager());
      match->getEndLoc().dump(result.Context->getSourceManager());
      rw.ReplaceText(SourceRange(match->getBeginLoc(), match->getEndLoc()), replacetxt, opts);
    }
    else {
      if (verbose) {
        printf("WARNING: unhandled location type, treating as block\n");
      }
      rw.ReplaceText(SourceRange(match->getBeginLoc(), match->getEndLoc()), replacetxt, opts);
    }
  }

  bool locValidForCodeInsertBefore(const MatchFinder::MatchResult& result) {
    const Stmt* stmt = result.Nodes.getNodeAs<Stmt>("match");
    const Stmt* root = result.Nodes.getNodeAs<Stmt>("root");
    // check if is inside conditional (for, if, elseif, while, etc)
    if (!root) {
      root = stmt;
    }
    SourceRange insert_point(stmt->getBeginLoc(), stmt->getEndLoc());

    if (auto* w = dyn_cast<DoStmt>(root)) {
      SourceRange while_cond(w->getCond()->getBeginLoc(), w->getCond()->getEndLoc());

      if (while_cond.fullyContains(insert_point)) {
        return false;
      }
    }
    else if (auto* f = dyn_cast<ForStmt>(root)) {
      SourceRange for_start(f->getInit()->getBeginLoc(), f->getInc()->getBeginLoc());

      if (for_start.fullyContains(insert_point)) {
        return false;
      }
    }
    else if (auto* i = dyn_cast<IfStmt>(root)) {
      SourceRange if_cond(i->getCond()->getBeginLoc(), i->getCond()->getEndLoc());

      if (if_cond.fullyContains(insert_point)) {
        return false;
      }
    }
    else if (auto* s = dyn_cast<SwitchStmt>(root)) {
      SourceRange switch_cond(s->getCond()->getBeginLoc(), s->getCond()->getEndLoc());

      if (switch_cond.fullyContains(insert_point)) {
        return false;
      }
    }
    else if (auto* w = dyn_cast<WhileStmt>(root)) {
      SourceRange while_cond(w->getCond()->getBeginLoc(), w->getCond()->getEndLoc());

      if (while_cond.fullyContains(insert_point)) {
        return false;
      }
    }

    return true;
  }

  bool locValidForCodeInsertAfter(const MatchFinder::MatchResult& result) {
    const Stmt* stmt = result.Nodes.getNodeAs<Stmt>("match");
    // check if will obviously be dead code (after return, break, continue)
    // anything more difficult left for future work/integration with unused code pass
    if (isa<BreakStmt>(stmt) ||
        isa<ContinueStmt>(stmt) ||
        isa<CoreturnStmt>(stmt) ||
        isa<GotoStmt>(stmt) ||
        isa<ReturnStmt>(stmt)) {
      return false;
    }
    // check if is inside conditional (for, if, elseif, while, etc)
    return locValidForCodeInsertBefore(result);
  }

  bool locValidForCodeInsert(const MatchFinder::MatchResult& result) {
    return locValidForCodeInsertBefore(result) && locValidForCodeInsertAfter(result);
  }
};

template <class T>
Rewriter InstrumentCallback<T>::rw;
template <class T>
std::vector<FileID> InstrumentCallback<T>::files_changed;
template <class T>
int InstrumentCallback<T>::num_matched = 0;
template <class T>
bool InstrumentCallback<T>::verbose = false;
template <class T>
bool InstrumentCallback<T>::rewrite_file = true;

#endif
