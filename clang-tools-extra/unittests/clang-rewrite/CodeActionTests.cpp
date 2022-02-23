#include "CodeAction.h"
#include "gtest/gtest.h"
#include <vector>
#include <string>

namespace clang {
namespace rewrite_tool {
namespace {

class CodeActionTest : public ::testing::Test {
public:
  std::string format(llvm::StringRef Code) {
    tooling::Replacements Replaces = format::reformat(
        format::getLLVMStyle(), Code, {tooling::Range(0, Code.size())});
    auto ChangedCode = tooling::applyAllReplacements(Code, Replaces);
    EXPECT_TRUE(static_cast<bool>(ChangedCode));
    if (!ChangedCode) {
      llvm::errs() << llvm::toString(ChangedCode.takeError());
      return "";
    }
    return *ChangedCode;
  }
};

TEST(CodeActionTest, CodeActionMembers) {
  CodeAction act(InsertPostmatch, {"test1", "test2"}, "return var;",
    "after_return", LangOptions());

  EXPECT_TRUE(act.do_for_matcher("test1"));
  EXPECT_FALSE(act.do_for_matcher("nope"));

  act.add_matcher("test3");

  EXPECT_TRUE(act.do_for_matcher("test3"));

  // EXPECT_EQ("test1, test2, test3,\n", act.dump_list());
}


} //namespaces
}
}
