#ifndef CLANG_REWRITE_UTILS_H
#define CLANG_REWRITE_UTILS_H

#include "clang/Basic/SourceManager.h"
#include "clang/ASTMatchers/Dynamic/Registry.h"

#include "LocalASTMatchers.h"

using namespace clang;
using namespace clang::ast_matchers;

using namespace clang::tooling;
using namespace llvm;

std::vector<const FileEntry*> source_file_entries;

std::vector<std::string> spec_files;

ClangTool* Tool;

int global_argc;
const char** global_argv;

Rewriter binding_rw;
Rewriter internal_rep_rw;

bool isInOneOfFileIDs(SourceLocation loc, std::vector<const FileEntry*> files, SourceManager& SrcMgr) {
  return llvm::any_of(files, [&](const FileEntry* file) {
    return SrcMgr.isInFileID(loc, SrcMgr.translateFile(file));
  });
}

namespace clang {
namespace ast_matchers {
namespace dynamic {

#define REGISTER_MATCHER(name)                                                 \
  map->registerMatcher(#name, internal::makeMatcherAutoMarshall(                    \
                             ::clang::ast_matchers::name, #name));

  void registerLocalASTMatchers(RegistryMaps* map) {
    printf("registering local matchers\n");
    REGISTER_MATCHER(cudaBlockDim);
    REGISTER_MATCHER(cudaGridDim);
    REGISTER_MATCHER(cudaSharedMemPerBlock);
    REGISTER_MATCHER(cudaStream);
    REGISTER_MATCHER(hasExpectedReturnType);
    REGISTER_MATCHER(ignoringPointers);
  }

}
}
}

#endif //CLANG_REWRITE_UTILS_H
