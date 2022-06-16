#ifndef CLANG_REWRITE_UTILS_H
#define CLANG_REWRITE_UTILS_H

#include "clang/Basic/SourceManager.h"

using namespace clang;
using namespace clang::ast_matchers;

using namespace clang::tooling;
using namespace llvm;

std::vector<const FileEntry*> source_file_entries;

std::vector<std::string> spec_files;

ClangTool* Tool;

bool isInOneOfFileIDs(SourceLocation loc, std::vector<const FileEntry*> files, SourceManager& SrcMgr) {
  return llvm::any_of(files, [&](const FileEntry* file) {
    return SrcMgr.isInFileID(loc, SrcMgr.translateFile(file));
  });
}

#endif //CLANG_REWRITE_UTILS_H
