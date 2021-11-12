// Declares clang::SyntaxOnlyAction.
#include "clang/Frontend/FrontendActions.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
// Declares llvm::cl::extrahelp.
#include "llvm/Support/CommandLine.h"

#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/Lex/Lexer.h"
#include "clang/Lex/Token.h"
#include "clang/Rewrite/Core/RewriteBuffer.h"
#include "clang/Rewrite/Core/Rewriter.h"

#include "CodeAction.h"
#include "InstrumentCallback.h"
#include "MatcherWrapper.h"
#include "NewCodeCallback.h"
#include "MatcherGenCallback.h"
#include "tests/test_matchers.cpp"

#include <algorithm>
#include <fstream>
#include <vector>

using namespace clang;
using namespace clang::ast_matchers;

using namespace clang::tooling;
using namespace llvm;

// Apply a custom category to all command-line options so that they are the
// only ones displayed.
static llvm::cl::OptionCategory
    SelectiveInstrumentCategory("Selective instrumentation options");

// TODO: set to false :3
cl::opt<bool> verbose("verbose", cl::desc("Print verbose (debug) output."),
                      cl::init(true), cl::cat(SelectiveInstrumentCategory));
cl::alias verboseshort("v", cl::desc("Short for --verbose."),
                       cl::aliasopt(verbose), cl::Hidden);

cl::opt<bool> quiet("quiet", cl::desc("Disable output."), cl::init(false),
                    cl::cat(SelectiveInstrumentCategory));
cl::alias quietshort("q", cl::desc("Short for --quiet."), cl::aliasopt(quiet),
                     cl::Hidden);

cl::opt<bool>
    rewrite_file("rewrite-file",
                 cl::desc("Rewrite input file with instrumentation code."),
                 cl::init(true), cl::cat(SelectiveInstrumentCategory));
cl::opt<bool> norewrite_file("no-rewrite-file",
                             cl::desc("Do not rewrite input file."),
                             cl::init(true),
                             cl::cat(SelectiveInstrumentCategory));

cl::opt<std::string>
    inst_file("inst-file",
              cl::desc("File with code changes to be made at matched points."),
              cl::cat(SelectiveInstrumentCategory));

// CommonOptionsParser declares HelpMessage with a description of the common
// command-line options related to the compilation database and input files.
// It's nice to have this help message in all tools.
static cl::extrahelp CommonHelp(CommonOptionsParser::HelpMessage);

// A help message for this specific tool can be added afterwards.
// static cl::extrahelp MoreHelp("\nMore help text...\n");

// static bool areSameVariable(const ValueDecl *First, const ValueDecl *Second)
// {
//   return First && Second &&
//          First->getCanonicalDecl() == Second->getCanonicalDecl();
// }
//

int main(int argc, const char **argv) {
  auto ExpectedParser =
      CommonOptionsParser::create(argc, argv, SelectiveInstrumentCategory);
  if (!ExpectedParser) {
    // Fail gracefully for unsupported options.
    llvm::errs() << ExpectedParser.takeError();
    return 1;
  }
  CommonOptionsParser &OptionsParser = ExpectedParser.get();
  ClangTool Tool(OptionsParser.getCompilations(),
                 OptionsParser.getSourcePathList());

  // for (std::string path : OptionsParser.getSourcePathList()) {
  //   printf("source path %s\n", path.c_str());
  // }

  if (norewrite_file) {
    rewrite_file = false;
  }
  if (quiet) {
    verbose = false;
  }
  int retval;
  // TODO: multiple inst files
  if (!inst_file.empty()) {
    ClangTool InstTool(OptionsParser.getCompilations(), {inst_file});

    MatchFinder inst_finder;
    InsertPrematchCallback prematch_callback;
    InsertPostmatchCallback postmatch_callback;
    ReplaceCallback replace_callback;
    MatcherGenCallback matcher_callback;
    // ReplaceCallback2 r2d2;

    inst_finder.addMatcher(insert_before_match, &prematch_callback);
    inst_finder.addMatcher(insert_after_match, &postmatch_callback);
    inst_finder.addMatcher(replace_match, &replace_callback);
    inst_finder.addMatcher(matcher, &matcher_callback);
    // inst_finder.addMatcher(replace2, &r2d2);

    // MatcherWrapper<DynTypedMatcher>* m = new MatcherWrapper<DynTypedMatcher>(rettest, "returns_test",
    //   "test",
    //   0, 0);
    // user_matchers.push_back(m);

    retval = InstTool.run(newFrontendActionFactory(&inst_finder).get());
  }

  InstrumentCallback<StatementMatcher>::verbose = verbose;
  InstrumentCallback<StatementMatcher>::rewrite_file = rewrite_file;

  printf("NUM MATCHERS FOUND: %ld\n", user_matchers.size());

  MatchFinder Finder;

  // TODO are we going to need any other kinds of matchers? probably
  // DeclarationMatchers
  // https://clang.llvm.org/doxygen/classclang_1_1ast__matchers_1_1MatchFinder.html


  // temp hack until we have a real front end
  // stmt_matchers.push_back(new MatcherWrapper<StatementMatcher>(
  //     ReturnIntMatcher, "returns", "this", 81, 1));
  // stmt_matchers.push_back(new MatcherWrapper<StatementMatcher>(
  //     LoopCondMatcher, "loops", "this", 74, 1));
  // stmt_matchers.push_back(new MatcherWrapper<StatementMatcher>(
  //     ThenMatcher, "then code", "this", 84, 1));

  // decl_matchers.push_back(new MatcherWrapper<DeclarationMatcher>(
  //     IntDeclMatcher, "intdecl", "this", 24, 1));
  // decl_matchers.push_back(new MatcherWrapper<DeclarationMatcher>(
  //     AddMatcher, "addfxn", "this", 27, 1));

  // for each matcher, go through all the actions and find the ones relevant to
  // it
  for (auto m : user_matchers) {
    // printf("matcher name %s\n", m->getName().c_str());
    for (CodeAction *act : all_actions) {
      if (act->do_for_matcher(m->getName())) {
        m->addAction(act);
      }
    }
  }

  InstrumentCallback<ast_matchers::internal::DynTypedMatcher> **callbacks =
      new InstrumentCallback<ast_matchers::internal::DynTypedMatcher> *[user_matchers.size()];

  int i = 0;
  for (MatcherWrapper<ast_matchers::internal::DynTypedMatcher> *m : user_matchers) {
    callbacks[i] = new InstrumentCallback<ast_matchers::internal::DynTypedMatcher>(m);
    Finder.addDynamicMatcher(m->getMatcher(), callbacks[i]);
    if (verbose) {
      m->dump();
    }
    i++;
  }
  retval = Tool.run(newFrontendActionFactory(&Finder).get());

  for (MatcherWrapper<ast_matchers::internal::DynTypedMatcher> *m : user_matchers) {
    delete m;
  }
  for (CodeAction *act : all_actions) {
    delete act;
  }
  for (unsigned int j = 0; j < user_matchers.size(); j++) {
    delete callbacks[j];
  }
  delete[] callbacks;

  return retval;
}

// TODO
// user specified code and actions
//    replace with arguments
// for each match, rewrite ast before and after to call inst function
//    figure out which inst function based on finsturment-functions
// for each match, annotate with attribute
//    make new attribute(s)
// in codegen, if we see a node with that attribute, give the block we're
// generating the same attribute (?)
//    add codegenopt like finstrument-functions
// in llvm pass, add calls to instrumentation funcs at appropriate points
//    new llvm pass
