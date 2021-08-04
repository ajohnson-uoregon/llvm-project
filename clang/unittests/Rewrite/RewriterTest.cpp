//===- unittests/Rewrite/RewriterTest.cpp - Rewriter tests ----------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/Tooling/Tooling.h"
#include "gtest/gtest.h"

using namespace clang;

namespace {

struct RangeTypeTest {
  std::unique_ptr<ASTUnit> AST;
  Rewriter Rewrite;
  SourceLocation FileStart;
  CharSourceRange CRange; // covers exact char range
  CharSourceRange TRange; // extends CRange to whole tokens
  SourceRange SRange;     // different type but behaves like TRange
  SourceLocation makeLoc(int Off) { return FileStart.getLocWithOffset(Off); }
  CharSourceRange makeCharRange(int StartOff, int EndOff) {
    return CharSourceRange::getCharRange(makeLoc(StartOff), makeLoc(EndOff));
  }
  RangeTypeTest(StringRef Code, int StartOff, int EndOff) {
    AST = tooling::buildASTFromCode(Code);
    ASTContext &C = AST->getASTContext();
    Rewrite = Rewriter(C.getSourceManager(), C.getLangOpts());
    FileStart = AST->getStartOfMainFileID();
    CRange = makeCharRange(StartOff, EndOff);
    SRange = CRange.getAsRange();
    TRange = CharSourceRange::getTokenRange(SRange);
  }
};

TEST(Rewriter, GetRewrittenTextRangeTypes) {
  // Check that correct text is retrieved for each range type.  Check again
  // after a modification.  Ranges remain in terms of the original text but
  // include the new text.
  StringRef Code = "int main() { return 0; }";
  //              get char range ^~~    = "ret"
  //             get token range ^~~+++ = "return"
  //            get source range ^~~+++ = "return"
  //                  insert "x" ^
  //              get char range ^~~    = "xret"
  //             get token range ^~~+++ = "xreturn"
  //            get source range ^~~+++ = "xreturn"
  RangeTypeTest T(Code, 13, 16);
  EXPECT_EQ(T.Rewrite.getRewrittenText(T.CRange), "ret");
  EXPECT_EQ(T.Rewrite.getRewrittenText(T.TRange), "return");
  EXPECT_EQ(T.Rewrite.getRewrittenText(T.SRange), "return");
  T.Rewrite.InsertText(T.makeLoc(13), "x");
  EXPECT_EQ(T.Rewrite.getRewrittenText(T.CRange), "xret");
  EXPECT_EQ(T.Rewrite.getRewrittenText(T.TRange), "xreturn");
  EXPECT_EQ(T.Rewrite.getRewrittenText(T.SRange), "xreturn");
}

TEST(Rewriter, ReplaceTextRangeTypes) {
  // Check that correct text is replaced for each range type.  Ranges remain in
  // terms of the original text but include the new text.
  StringRef Code = "int main(int argc, char *argv[]) { return argc; }";
  //                                                          foogc; }
  //                            replace char range with "foo" ^~
  //                                                      get ^~~~~ = "foogc;"
  //                           replace token range with "bar" ^~++
  //                                                      get ^~~~~ = "bar;"
  //                            replace source range with "0" ^~++
  //                                                      get ^~~~~ = "0;"
  RangeTypeTest T(Code, 42, 44);
  T.Rewrite.ReplaceText(T.CRange, "foo");
  EXPECT_EQ(T.Rewrite.getRewrittenText(T.makeCharRange(42, 47)), "foogc;");
  T.Rewrite.ReplaceText(T.TRange, "bar");
  EXPECT_EQ(T.Rewrite.getRewrittenText(T.makeCharRange(42, 47)), "bar;");
  T.Rewrite.ReplaceText(T.SRange, "0");
  EXPECT_EQ(T.Rewrite.getRewrittenText(T.makeCharRange(42, 47)), "0;");
}

TEST(Rewriter, ReplaceAfterInsertNoOpts) {
  // Check that remove/insert after insert behaves correctly based on the
  // RewriteOptions passed. This should erase extra text.

  StringRef code = "int main(int argc, char *argv[]) { return argc; } double "
                   "f(int text_to_erase) {}";
  //                        insert "int answer = 42;" ^
  //                                  replace with 42 ^
  //                                         extra text to erase ^
  std::unique_ptr<ASTUnit> AST = tooling::buildASTFromCode(code);
  ASTContext &C = AST->getASTContext();
  Rewriter Rewrite = Rewriter(C.getSourceManager(), C.getLangOpts());
  SourceLocation FileStart = AST->getStartOfMainFileID();
  SourceLocation insert_point = FileStart.getLocWithOffset(34);
  Rewrite.InsertText(insert_point, "int answer = 42;");
  SourceRange replace_range = SourceRange(FileStart.getLocWithOffset(34),
                                          FileStart.getLocWithOffset(45));
  Rewrite.ReplaceText(replace_range, "42;");
  EXPECT_EQ(
      Rewrite.getRewrittenText(SourceRange(FileStart.getLocWithOffset(33),
                                           FileStart.getLocWithOffset(65))),
      "{int answer = 42;42; text_to_erase");
}

TEST(Rewriter, ReplaceAfterInsertOpts) {
  // Check that remove/insert after insert behaves correctly based on the
  // RewriteOptions passed. This should NOT erase extra text.

  StringRef code = "int main(int argc, char *argv[]) { return argc; } double "
                   "f(int text_to_erase) {}";
  //                        insert "int answer = 42;" ^
  //                                  replace with 42 ^
  //                                         extra text to erase ^
  std::unique_ptr<ASTUnit> AST = tooling::buildASTFromCode(code);
  ASTContext &C = AST->getASTContext();
  Rewriter Rewrite = Rewriter(C.getSourceManager(), C.getLangOpts());
  SourceLocation FileStart = AST->getStartOfMainFileID();
  SourceLocation insert_point = FileStart.getLocWithOffset(34);
  Rewrite.InsertText(insert_point, "int answer = 42;");
  SourceRange replace_range = SourceRange(FileStart.getLocWithOffset(34),
                                          FileStart.getLocWithOffset(46));
  Rewriter::RewriteOptions opts;
  opts.IncludeInsertsAtBeginOfRange = false;
  Rewrite.ReplaceText(replace_range, "42;", opts);
  EXPECT_EQ(
      Rewrite.getRewrittenText(SourceRange(FileStart.getLocWithOffset(33),
                                           FileStart.getLocWithOffset(58))),
      "{int answer = 42;42; } double f(");
}

} // anonymous namespace
