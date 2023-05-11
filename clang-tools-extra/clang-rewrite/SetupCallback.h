#ifndef SETUP_CALLBACK_H
#define SETUP_CALLBACK_H

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
#include <algorithm>

using namespace clang;
using namespace clang::ast_matchers;

using namespace clang::tooling;
using namespace llvm;

namespace clang {
namespace rewrite_tool {

class SetupCallback : public MatchFinder::MatchCallback {
public:
  ASTContext* context;
  std::string setup_code = "";
  Location valid_range;

  SetupCallback(Location valid_range) : valid_range(valid_range) {}

  void run(const MatchFinder::MatchResult& result) override {
    printf("running SetupCallback\n");

    context = result.Context;

    const DeclStmt* setup = result.Nodes.getNodeAs<DeclStmt>("setup");

    if (!setup || !context->getSourceManager().isWrittenInMainFile(setup->getBeginLoc())) {
      printf("ERROR: invalid setup\n");
      return;
    }

    FullSourceLoc setup_begin = context->getFullLoc(setup->getBeginLoc());
    FullSourceLoc setup_end = context->getFullLoc(setup->getEndLoc());

    unsigned int begin_line = setup_begin.getSpellingLineNumber();
    unsigned int begin_col = setup_begin.getSpellingColumnNumber();

    if (!locIsInRangeHard(valid_range, begin_line, begin_col)) {
      printf("loc not in range\n");
      return;
    }

    FileID fid = setup_begin.getFileID();
    unsigned int begin_offset = setup_begin.getFileOffset();
    unsigned int end_offset = setup_end.getFileOffset();

    std::optional<llvm::MemoryBufferRef> buff =
      context->getSourceManager().getBufferOrNone(fid);

    char* setup_code_c = new char[end_offset - begin_offset + 2];
    if (buff.has_value()) {
      memcpy(setup_code_c, &(buff->getBufferStart()[begin_offset]),
              (end_offset - begin_offset + 2) * sizeof(char));
      setup_code_c[end_offset - begin_offset + 1] = '\0';
      setup_code += std::string(setup_code_c);
      printf("setup code??? %s\n", setup_code_c);
    }
    delete[] setup_code_c;
  }

};

}
}

#endif // SETUP_CALLBACK_H
