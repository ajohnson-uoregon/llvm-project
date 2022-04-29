#ifndef CLANG_CODE_ACTION_H
#define CLANG_CODE_ACTION_H

#include <algorithm>
#include <string>
#include <vector>
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/FileSystem.h"
#include "clang/Basic/Builtins.h"
#include "clang/Basic/LangOptions.h"
#include "clang/Basic/SourceManager.h"
#include "clang/Basic/FileManager.h"
#include "clang/Basic/Diagnostic.h"
#include "clang/Basic/DiagnosticOptions.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "llvm/Support/Path.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/MemoryBufferRef.h"

#include "ConstructMatchers.h"
#include "ClangRewriteUtils.h"

using namespace clang;
using namespace clang::ast_matchers;
using namespace llvm;

namespace clang {
namespace rewrite_tool {

enum NewCodeKind {
  InsertPrematch,
  InsertPostmatch,
  Replace,
};

typedef struct Binding {
  std::string name;
  std::string qual_name;
  std::string value;
} Binding;

class ReplaceBindingsCallback : public MatchFinder::MatchCallback {
public:
  FileID fid;
  ASTContext* context;

  ReplaceBindingsCallback(FileID fid) : fid(fid) {}

  ~ReplaceBindingsCallback() {}

  void run(const MatchFinder::MatchResult &result) override {
    printf("found match for binding\n");
    context = result.Context;

    const Expr* expr = result.Nodes.getNodeAs<Expr>("match");
    const NamedDecl* decl = result.Nodes.getNodeAs<NamedDecl>("match");

    bool expr_valid = true;
    bool decl_valid = true;

    if (!expr ||
        !context->getSourceManager().isInFileID(expr->getBeginLoc(), fid)) {
      printf("ERROR: invalid expr binding match loc\n");
      expr_valid = false;
    }

    if (!decl ||
        !context->getSourceManager().isInFileID(decl->getBeginLoc(), fid)) {
      printf("ERROR: invalid decl binding match loc\n");
      decl_valid = false;
    }

    if (!expr_valid && !decl_valid) {
      printf("ERROR: no valid binding match loc\n");
      return;
    }

    FullSourceLoc begin;
    FullSourceLoc end;

    if (expr_valid) {
      begin = context->getFullLoc(expr->getBeginLoc());
      end = context->getFullLoc(expr->getEndLoc());
    }
    else if (decl_valid) {
      begin = context->getFullLoc(decl->getBeginLoc());
      end = context->getFullLoc(decl->getEndLoc());
    }

    unsigned int begin_line = begin.getSpellingLineNumber();
    unsigned int begin_col = begin.getSpellingColumnNumber();
    unsigned int end_line = end.getSpellingLineNumber();
    unsigned int end_col = end.getSpellingColumnNumber();

    printf("FOUND match for binding at %d:%d - %d:%d\n",
           begin_line, begin_col, end_line, end_col);
  }
};

class CodeAction {
public:
  ASTContext* context;
  std::vector<DynTypedNode> nodes;
  std::string base_code_snippet; // the code as it appears in the spec
  std::string edited_code_snippet; // the code after bound snippets have been copy-pasted in
  NewCodeKind kind;
  std::vector<std::string> matcher_names;
  std::string action_name;

  Rewriter rewrite;
  FileID snippet_file;

  IntrusiveRefCntPtr<DiagnosticOptions> DiagOpts = new DiagnosticOptions();
  DiagnosticsEngine Diagnostics;
  IntrusiveRefCntPtr<llvm::vfs::InMemoryFileSystem> InMemoryFileSystem =
    new llvm::vfs::InMemoryFileSystem();
  IntrusiveRefCntPtr<llvm::vfs::OverlayFileSystem> OverlayFileSystem =
    new llvm::vfs::OverlayFileSystem(llvm::vfs::getRealFileSystem());
  FileManager Files;

  // ASTContext (LangOptions &LOpts, SourceManager &SM, IdentifierTable &idents,
  //   SelectorTable &sels, Builtin::Context &builtins, TranslationUnitKind TUKind)

  CodeAction(SourceManager& SM, LangOptions LangOpts, IdentifierTable& idents,
      SelectorTable& selectors, Builtin::Context builtins, TranslationUnitKind TUKind,
      std::vector<DynTypedNode> nodes, NewCodeKind kind,
      std::vector<std::string> matcher_names, std::string code, std::string action_name)
      :
        nodes(nodes), base_code_snippet(code), kind(kind),
        matcher_names(matcher_names), action_name(action_name),
        rewrite(SM, LangOpts),
        Diagnostics(IntrusiveRefCntPtr<DiagnosticIDs>(new DiagnosticIDs), &*DiagOpts),
        Files(FileSystemOptions(), OverlayFileSystem)
  {
    context = new ASTContext(LangOpts, SM, idents, selectors, builtins, TUKind);
    OverlayFileSystem->pushOverlay(InMemoryFileSystem);
    snippet_file = createInMemoryFile(action_name, base_code_snippet);
    // llvm::Optional<llvm::MemoryBufferRef> buff = Sources.getBufferOrNone(snippet_file);
    //
    // if (buff.hasValue()) {
    //   Lexer my_lexer(snippet_file, buff.getValue(), Sources, LangOpts);
    //   bool more_to_lex = true;
    //   Token tok;
    //   printf("code: %s\n", base_code_snippet.c_str());
    //   while (more_to_lex) {
    //     more_to_lex = !my_lexer.LexFromRawLexer(tok);
    //     tokens.push_back(tok);
    //     printf("token %s ", tok.getName());
    //     if (tok.isAnyIdentifier()) {
    //       std::string ident = tok.getRawIdentifier().str();
    //       printf("ident %s ", ident.c_str());
    //     }
    //     printf("\n");
    //   }
    // }
    // else {
    //   printf("ERROR: bad code snippet in action\n");
    // }
  }

  ~CodeAction() {}

  void add_node(DynTypedNode n) {
    if (std::find(nodes.begin(), nodes.end(), n) == nodes.end()) {
      nodes.push_back(n);
    }
  }

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
    return context->getSourceManager().createFileID(*Entry, SourceLocation(), SrcMgr::C_User);
  }

  void dump_bindings(std::vector<Binding>& bindings) {
    printf("All bindings:\n");
    for (Binding b : bindings) {
      printf("name: %s\n", b.name.c_str());
      printf("qual name: %s\n", b.qual_name.c_str());
      // for (unsigned int i = 0; i < b.names.size(); i++) {
      //   printf("  %s\t", b.names[i].c_str());
        // if (!b.tokenized_names.empty()) {
        //   for (Token t : b.tokenized_names[i]) {
        //     printf("%s ", t.getName());
        //     if (t.isAnyIdentifier()) {
        //       printf("(%s) ", t.getRawIdentifier().str().c_str());
        //     }
        //   }
        // }
        // else {
        //   printf("tokenized_names empty\n");
        // }
        // printf("\n");
      printf("\tvalue: %s\n", b.value.c_str());
      printf("\n");
    }
  }

  // void tokenize_bindings(std::vector<Binding>& bindings) {
  //   printf("tokenize\n");
  //   for (Binding b : bindings) {
  //     for (std::string name : b.names) {
  //       FileID fid = createInMemoryFile(action_name + name, name);
  //       llvm::Optional<llvm::MemoryBufferRef> buff = Sources.getBufferOrNone(fid);
  //
  //       if (buff.hasValue()) {
  //         // std::vector<Token> token_name;
  //         b.tokenized_names.push_back(std::vector<Token>());
  //         Lexer my_lexer(fid, buff.getValue(), Sources, LangOpts);
  //         bool more_to_lex = true;
  //         Token tok;
  //         while (more_to_lex) {
  //           more_to_lex = !my_lexer.LexFromRawLexer(tok);
  //           b.tokenized_names.back().push_back(tok);
  //           printf("tok %s\n", tok.getName());
  //         }
  //         if (b.tokenized_names.empty()) {
  //           printf("WAT\n");
  //         }
  //         // b.tokenized_names.push_back(std::move(token_name));
  //       }
  //       else {
  //         printf("no buffer???\n");
  //       }
  //     }
  //   }
  // }

  void replace_bound_code(std::vector<Binding>& bindings) {
    edited_code_snippet = ""; // clear it out before doing anything

    Rewriter::RewriteOptions opts;
    opts.IncludeInsertsAtBeginOfRange = false;

    // tokenize_bindings(bindings);
    dump_bindings(bindings);

    // DO NOT UNCOMMENT
    // for (DynTypedNode n : nodes) {
    //   n.print(llvm::outs(), PrintingPolicy(context.getLangOpts()));
    // }

    for (Binding b : bindings) {
      printf("LOOKING for things named %s\n", b.name.c_str());
      ReplaceBindingsCallback cb(snippet_file);
      MatchFinder finder;
      VariantMatcher declmatcher =
        constructBoundMatcher("namedDecl", "match",
          constructMatcher("hasName",
            StringRef(b.qual_name),
          1),
        0);
      VariantMatcher refmatcher =
        constructBoundMatcher("declRefExpr", "match",
          constructMatcher("to",
            constructMatcher("namedDecl",
              constructMatcher("hasName",
                StringRef(b.qual_name),
              3),
            2),
          1),
        0);

      llvm::Optional<DynTypedMatcher> dynmatcher = declmatcher.getSingleMatcher();
      if (dynmatcher) {
        finder.addDynamicMatcher(*dynmatcher, &cb);
      }
      else {
        printf("ERROR: bad decl matcher\n");
        return;
      }

      dynmatcher = refmatcher.getSingleMatcher();
      if (dynmatcher) {
        finder.addDynamicMatcher(*dynmatcher, &cb);
      }
      else {
        printf("ERROR: bad ref matcher\n");
        return;
      }

      // for (DynTypedNode n : nodes) {
      //   finder.match(n, context);
      // }
      finder.matchAST(*context);
    }

    // iterator token_iter = tokens.begin();
    // printf("code: %s\n", base_code_snippet.c_str());
    // if (!bindings.empty()) {
    //   while (token_iter != tokens.end()) {
    //     int bindings_index = 0;
    //     int names_index = 0;
    //     while (bindings_index < bindings.size()) {
    //       std::string name = bindings[bindings_index].names[names_index];
    //       if (matching_substream_starting_at(token_iter, ))
    //     }
    //   }
    // }


    const RewriteBuffer* rwbuff = rewrite.getRewriteBufferFor(snippet_file);
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

}
} // namespaces

#endif //CLANG_CODE_ACTION_H
