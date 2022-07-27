#ifndef CLANG_CODE_ACTION_H
#define CLANG_CODE_ACTION_H

#include <algorithm>
#include <string>
#include <vector>
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/FileSystem.h"
#include "clang/Basic/LangOptions.h"
#include "clang/Basic/SourceManager.h"
#include "clang/Basic/FileManager.h"
#include "clang/Basic/Diagnostic.h"
#include "clang/Basic/DiagnosticOptions.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "llvm/Support/Path.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/MemoryBufferRef.h"

using namespace clang;
using namespace clang::ast_matchers;

using namespace llvm;

enum NewCodeKind {
  InsertPrematch,
  InsertPostmatch,
  Replace,
};

class CodeAction {
public:
  std::string base_code_snippet; // the code as it appears in the spec
  std::string edited_code_snippet; // the code after bound snippets have been copy-pasted in
  NewCodeKind kind;
  std::vector<std::string> matcher_names;
  std::string action_name;

  IntrusiveRefCntPtr<DiagnosticOptions> DiagOpts = new DiagnosticOptions();
  DiagnosticsEngine Diagnostics;
  IntrusiveRefCntPtr<llvm::vfs::InMemoryFileSystem> InMemoryFileSystem =
    new llvm::vfs::InMemoryFileSystem();
  IntrusiveRefCntPtr<llvm::vfs::OverlayFileSystem> OverlayFileSystem =
    new llvm::vfs::OverlayFileSystem(llvm::vfs::getRealFileSystem());
  FileManager Files;
  SourceManager Sources;
  const LangOptions LangOpts;
  Rewriter rewrite;

  CodeAction(NewCodeKind kind, std::vector<std::string> matcher_names,
             std::string code, std::string action_name, const LangOptions& LangOpts)
      : base_code_snippet(code), kind(kind), matcher_names(matcher_names),
        action_name(action_name),
        Diagnostics(IntrusiveRefCntPtr<DiagnosticIDs>(new DiagnosticIDs), &*DiagOpts),
        Files(FileSystemOptions(), OverlayFileSystem), Sources(Diagnostics, Files),
        LangOpts(LangOpts), rewrite(Sources, LangOpts)
  {
    OverlayFileSystem->pushOverlay(InMemoryFileSystem);
  }

  ~CodeAction() {}

  void add_matcher(std::string m) {
    matcher_names.push_back(m);
    // TODO: do we need to unique these???
    std::sort(matcher_names.begin(), matcher_names.end());
    auto new_end = std::unique(matcher_names.begin(), matcher_names.end());
    matcher_names.erase(new_end, matcher_names.end());
  }

  bool do_for_matcher(std::string matcher) {
    // if no matcher is specified, do it for everything
    if (matcher_names.empty()) {
      return true;
    }
    return std::find(matcher_names.begin(), matcher_names.end(), matcher) !=
           matcher_names.end();
  }

  // borrowed from clang/unittests/Tooling/RewriterTestContext.h:
  FileID createInMemoryFile(StringRef Name, StringRef Content) {
    std::unique_ptr<llvm::MemoryBuffer> Source =
        llvm::MemoryBuffer::getMemBuffer(Content);
    InMemoryFileSystem->addFile(Name, 0, std::move(Source));

    auto Entry = Files.getOptionalFileRef(Name);
    assert(Entry);
    return Sources.createFileID(*Entry, SourceLocation(), SrcMgr::C_User);
  }

  void dump_bindings(std::map<std::string, std::string> bindings) {
    printf("All bindings:\n");
    for (auto b : bindings) {
      printf("%s: %s\n", b.first.c_str(), b.second.c_str());
    }
  }

  void replace_bound_code(std::map<std::string, std::string> bindings) {
    edited_code_snippet = ""; // clear it out before doing anything
    FileID fid = createInMemoryFile(action_name, base_code_snippet);
    llvm::Optional<llvm::MemoryBufferRef> buff = Sources.getBufferOrNone(fid);
    Rewriter::RewriteOptions opts;
    opts.IncludeInsertsAtBeginOfRange = false;

    if (buff.hasValue()) {
      Lexer my_lexer(fid, buff.getValue(), Sources, LangOpts);
      bool more_to_lex = true;
      Token tok;
      printf("code: %s\n", base_code_snippet.c_str());
      dump_bindings(bindings);
      while (more_to_lex) {
        more_to_lex = !my_lexer.LexFromRawLexer(tok);
        printf("token %s ", tok.getName());
        if (tok.isAnyIdentifier()) {
          std::string ident = tok.getRawIdentifier().str();
          printf("ident %s ", ident.c_str());
          if (bindings.find(ident) != bindings.end()) {
            SourceLocation token_loc = tok.getLocation();
            unsigned int token_len = tok.getLength();
            printf("length %d", token_len);
            rewrite.ReplaceText(token_loc, token_len, bindings.find(ident)->second);
          }
        }
        printf("\n");
      }
    }
    else {
      printf("ERROR: bad code snippet in action\n");
    }

    const RewriteBuffer* rwbuff = rewrite.getRewriteBufferFor(fid);
    if (rwbuff) {
      llvm::raw_string_ostream out(edited_code_snippet);
      rwbuff->write(out);
      out.flush();
    }
    else {
      edited_code_snippet = base_code_snippet;
    }

    printf("new code: %s\n", edited_code_snippet.c_str());

  }

  void dump_list() {
    for (std::string s : matcher_names) {
      printf("%s,", s.c_str());
    }
    printf("\n");
  }

  void dump() {
    printf("Action type: %d\n", kind);
    printf("Applied to matchers:\n");
    for (std::string s : matcher_names) {
      printf("    %s\n", s.c_str());
    }
    printf("Code snippet:\n%s\n", base_code_snippet.c_str());
  }
};

#endif
