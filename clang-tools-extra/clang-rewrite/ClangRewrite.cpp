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

#include "ClangRewriteUtils.h"
#include "CodeAction.h"
#include "RewriteCallback.h"
#include "MatcherWrapper.h"
#include "NewCodeCallback.h"
#include "MatcherGenCallback.h"
#include "FindLiteralsCallback.h"
#include "NameRewriterCallback.h"

#include <algorithm>
#include <fstream>
#include <vector>

using namespace clang;
using namespace clang::ast_matchers;
using namespace clang::tooling;
using namespace llvm;
using namespace clang::rewrite_tool;

// Apply a custom category to all command-line options so that they are the
// only ones displayed.
static llvm::cl::OptionCategory
    RewriteCategory("Automatic code rewriting options");

// TODO: set to false :3
cl::opt<bool> verbose("verbose", cl::desc("Print verbose (debug) output."),
                      cl::init(true), cl::cat(RewriteCategory));
cl::alias verboseshort("v", cl::desc("Short for --verbose."),
                       cl::aliasopt(verbose), cl::Hidden);

cl::opt<bool> quiet("quiet", cl::desc("Disable output."), cl::init(false),
                    cl::cat(RewriteCategory));
cl::alias quietshort("q", cl::desc("Short for --quiet."), cl::aliasopt(quiet),
                     cl::Hidden);

cl::opt<bool>
    rewrite_file("rewrite-file",
                 cl::desc("Rewrite input file with matchers and modifiers."),
                 cl::init(true), cl::cat(RewriteCategory));
cl::opt<bool> norewrite_file("no-rewrite-file",
                             cl::desc("Do not rewrite input file."),
                             cl::init(true),
                             cl::cat(RewriteCategory));

cl::opt<std::string>
    inst_file("spec-file",
              cl::desc("Specification file; file with code changes to be made at matched points."),
              cl::cat(RewriteCategory));

// CommonOptionsParser declares HelpMessage with a description of the common
// command-line options related to the compilation database and input files.
// It's nice to have this help message in all tools.
static cl::extrahelp CommonHelp(CommonOptionsParser::HelpMessage);

int main(int argc, const char** argv) {

  llvm::Expected<CommonOptionsParser> ExpectedParser =
      CommonOptionsParser::create(argc, argv, RewriteCategory);
  if (!ExpectedParser) {
    // Fail gracefully for unsupported options.
    llvm::errs() << ExpectedParser.takeError();
    return 1;
  }

  CommonOptionsParser& OptionsParser = ExpectedParser.get();
  std::vector<std::string> sources = OptionsParser.getSourcePathList();
  std::vector<std::string> all_files = sources;
  if (!inst_file.empty()) {
    spec_files.push_back(inst_file);
  }
  all_files.insert(all_files.end(), spec_files.begin(), spec_files.end());

  Tool = new ClangTool(OptionsParser.getCompilations(),
                 all_files);

  for (std::string file : sources) {
    llvm::ErrorOr<const FileEntry*> entry = Tool->getFiles().getFile(file);
    if (entry) {
      source_file_entries.push_back(*entry);
    }
  }

  if (norewrite_file) {
    rewrite_file = false;
  }
  if (quiet) {
    verbose = false;
  }

  int retval;

  // TODO: multiple inst files
  if (!inst_file.empty()) {
    MatchFinder literal_finder;
    FindLiteralsCallback literals_callback;

    literal_finder.addMatcher(literal_vector, &literals_callback);

    // grab literals from namespace or list
    retval = Tool->run(newFrontendActionFactory(&literal_finder).get());
    if (retval) {
      printf("Problems with finding literals.\n");
      return retval;
    }

    MatchFinder name_rewriter;
    NameRewriterCallback name_rewrite_callback(inst_file);

    name_rewriter.addMatcher(insert_before_match, &name_rewrite_callback);
    name_rewriter.addMatcher(insert_after_match, &name_rewrite_callback);
    name_rewriter.addMatcher(replace_match, &name_rewrite_callback);
    name_rewriter.addMatcher(matcher_stmt, &name_rewrite_callback);
    name_rewriter.addMatcher(matcher_decl, &name_rewrite_callback);

    retval = Tool->run(newFrontendActionFactory(&name_rewriter).get());

    MatchFinder inst_finder;
    InsertPrematchCallback prematch_callback;
    InsertPostmatchCallback postmatch_callback;
    ReplaceCallback replace_callback;
    MatcherGenCallback matcher_callback(/*is_internal_matcher=*/false, {});

    inst_finder.addMatcher(insert_before_match, &prematch_callback);
    inst_finder.addMatcher(insert_after_match, &postmatch_callback);
    inst_finder.addMatcher(replace_match, &replace_callback);
    inst_finder.addMatcher(matcher_stmt, &matcher_callback);
    inst_finder.addMatcher(matcher_decl, &matcher_callback);

    // find matchers and replacers, make CodeActions
    ProcessSpec = new ClangTool(Tool->getCompilationDatabase(), {temp_file_name+".rewritten_spec.cpp"});
    retval = ProcessSpec->run(newFrontendActionFactory(&inst_finder).get());
    if (retval) {
      printf("Problems with creating matchers and transformations.\n");
      return retval;
    }
  }

  printf("NUM MATCHERS FOUND: %ld\n", user_matchers.size());

  MatchFinder Finder;

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

  std::ofstream temp_file(temp_file_name);
  std::ifstream og_file(sources[0]); //TODO: multiple files

  temp_file << "#include \"ClangRewriteMacros.h\"\n";

  std::string line;
  while (getline(og_file, line)) {
    temp_file << line << "\n";
  }

  temp_file.close();
  og_file.close();

  ProcessTemp = new ClangTool(Tool->getCompilationDatabase(), {temp_file_name});

  RewriteCallback<ast_matchers::internal::DynTypedMatcher> **callbacks =
      new RewriteCallback<ast_matchers::internal::DynTypedMatcher> *[user_matchers.size()];

  int i = 0;
  for (MatcherWrapper<ast_matchers::internal::DynTypedMatcher> *m : user_matchers) {
    callbacks[i] = new RewriteCallback<ast_matchers::internal::DynTypedMatcher>(m);
    Finder.addDynamicMatcher(m->getMatcher(), callbacks[i]);
    if (verbose) {
      m->dump();
    }
    i++;
  }
  // actually run the rewrites
  retval = ProcessTemp->run(newFrontendActionFactory(&Finder).get());

  std::ofstream new_file(sources[0] + ".rewrite.cpp");
  std::ifstream rewritten_file(temp_file_name);

  bool first_line = true; // skip the include we threw in
  while(getline(rewritten_file, line)) {
    if (!first_line) {
      new_file << line << "\n";
    }
    else {
      first_line = false;
    }
  }

  new_file.close();
  rewritten_file.close();

  // cleanup
  for (MatcherWrapper<ast_matchers::internal::DynTypedMatcher> *m : user_matchers) {
    delete m;
  }
  for (MatcherWrapper<ast_matchers::internal::DynTypedMatcher> *m : internal_matchers) {
    delete m;
  }
  for (CodeAction *act : all_actions) {
    delete act;
  }
  for (unsigned int j = 0; j < user_matchers.size(); j++) {
    delete callbacks[j];
  }
  delete[] callbacks;

  if (retval) {
    printf("Problems with rewriting file.\n");
  }

  return retval;
}
