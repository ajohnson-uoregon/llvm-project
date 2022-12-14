#ifndef CLANG_REWRTIE_INTERNAL_CALLBACK_H
#define CLANG_REWRTIE_INTERNAL_CALLBACK_H

#include "clang/Frontend/FrontendActions.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"

#include "clang/AST/ASTContext.h"
// #include "clang/AST/DeclTemplate.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/Lex/Lexer.h"
#include "clang/Lex/Token.h"
#include "clang/Rewrite/Core/RewriteBuffer.h"
#include "clang/Rewrite/Core/Rewriter.h"

#include "CodeAction.h"
#include "MatcherWrapper.h"
#include "ClangRewriteUtils.h"
#include "MatcherGenCallback.h"
#include "ReplaceBindingsCallback.h"
#include "ReplacerInternalCallback.h"

#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

using namespace clang;
using namespace clang::ast_matchers;

using namespace clang::tooling;
using namespace llvm;

namespace clang {
namespace rewrite_tool {

template <class T>
class RewriteInternalCallback : public MatchFinder::MatchCallback {
public:
  static Rewriter file_rw;
  ASTContext *context;
  static int num_matched;
  MatcherWrapper<T> *matcher;

  std::vector<Binding> literal_bindings;
  std::vector<Binding> bound_code;

  SourceRange orig_range;
  std::string orig_file;

  SourceRange match_range;
  int rewrite_start_offset;
  int rewrite_end_offset;
  std::string new_code;
  bool is_valid = false;

  RewriteInternalCallback(MatcherWrapper<T>* matcher,
      std::vector<Binding> literals, SourceRange og_range, std::string og_file)
    : matcher(matcher), literal_bindings(literals), orig_range(og_range),
      orig_file(og_file) {}

  ~RewriteInternalCallback() {}

  void onStartOfTranslationUnit() override {}

  void run(const MatchFinder::MatchResult &result) override {
    printf("HALLO\n");

    context = result.Context;

    const Expr* match = result.Nodes.getNodeAs<Expr>("clang_rewrite_top_level_match");

    // check if match in range of og for loop
    if (!match ||
        context->getSourceManager().getFilename(match->getBeginLoc()).str() != orig_file) {
      printf("in wrong file\n");
      return;
    }

    match_range = SourceRange(match->getBeginLoc(), match->getEndLoc());
    if (!orig_range.fullyContains(match_range)) {
      printf("match not in source range\n");
      return;
    }

    unsigned int og_start_offset = context->getSourceManager().getFileOffset(orig_range.getBegin());
    // unsigned int og_end_offset   = context->getSourceManager().getFileOffset(orig_range.getEnd());

    unsigned int match_start_offset = context->getSourceManager().getFileOffset(match->getBeginLoc());
    unsigned int match_end_offset   = context->getSourceManager().getFileOffset(match->getEndLoc());

    rewrite_start_offset = match_start_offset - og_start_offset;
    rewrite_end_offset = match_end_offset - og_start_offset;

    match->dump();

    // find all bound nodes from matcher (copy paste)
    for (std::pair<std::string, DynTypedNode> n : result.Nodes.getMap()) {
      llvm::outs() << n.first << " : \n";
      n.second.dump(llvm::outs(), *context);
      const Stmt *stmt = result.Nodes.getNodeAs<Stmt>(n.first);
      const NamedDecl *decl = result.Nodes.getNodeAs<NamedDecl>(n.first);
      const Type *type = result.Nodes.getNodeAs<Type>(n.first);

      if (stmt) {
        SourceRange code_loc = stmt->getSourceRange();
        code_loc.print(llvm::outs(), context->getSourceManager());
        printf("\n");
        FullSourceLoc code_begin = context->getFullLoc(code_loc.getBegin());

        // some nodes (like declRefExpr) have begin == end, so we want to get the
        // end of the *token*
        // others (like callExpr) have ending pointing to the start of the last
        // token (eg, ')' ), but we want to get that too
        // so in general it's best to just get the loc of the end of the token
        FullSourceLoc code_end = context->getFullLoc(Lexer::getLocForEndOfToken(
            code_loc.getEnd(), 0, context->getSourceManager(),
            context->getLangOpts()));

        if (!code_begin.isValid() || !code_end.isValid()) {
          continue;
        }

        FileID fid = code_begin.getFileID();
        unsigned int begin_offset = code_begin.getFileOffset();
        unsigned int end_offset = code_end.getFileOffset();

        printf("begin offset %u\n", begin_offset);
        printf("end offset   %u\n", end_offset);
        printf("array length %u\n", end_offset - begin_offset);

        llvm::Optional<llvm::MemoryBufferRef> buff =
            context->getSourceManager().getBufferOrNone(fid);

        char *code = new char[end_offset - begin_offset + 1];
        if (buff.has_value()) {
          memcpy(code, &(buff->getBufferStart()[begin_offset]),
                 (end_offset - begin_offset + 1) * sizeof(char));
          code[end_offset - begin_offset] =
              '\0'; // force null terminated for Reasons
          printf("code??? %s\n", code);
        } else {
          printf("no buffer :<\n");
        }

        // n.second.dump(llvm::outs(), *context);
        llvm::outs() << "\n";
        Binding b;
        // for (auto s : n.second) {
        //   if (s != "clang_rewrite_top_level_match") {
        //     b.names.push_back(s);
        //   }
        // }
        // b.value = std::string(code);
        if (n.first != "clang_rewrite_top_level_match") {
          std::pair<StringRef, StringRef> split = StringRef(n.first).split(";");
          b.name = split.first.str();
          b.qual_name = split.second.str();
          b.value = std::string(code);
          b.kind = BindingKind::VarNameBinding;
          bound_code.push_back(b);
        }

        delete[] code;
      }
      else if (decl) {
        std::string name = decl->getNameAsString();
        std::string qualified_name = decl->getQualifiedNameAsString();
        printf("name: %s\n", name.c_str());
        printf("qualified name: %s\n", qualified_name.c_str());

        n.second.dump(llvm::outs(), *context);
        llvm::outs() << "\n";
        Binding b;

        // for (auto s : n.second) {
        //   if (s != "clang_rewrite_top_level_match") {
        //     b.names.push_back(s);
        //   }
        // }
        // b.value = name;
        // bound_code.push_back(b);
        if (n.first != "clang_rewrite_top_level_match") {
          std::pair<StringRef, StringRef> split = StringRef(n.first).split(";");
          b.name = split.first.str();
          b.qual_name = split.second.str();
          b.value = name;
          b.kind = BindingKind::VarNameBinding;
          bound_code.push_back(b);
        }
      }
      else if (type) {
        std::string name = QualType(type, 0).getAsString();
        printf("type name: %s\n", name.c_str());
        n.second.dump(llvm::outs(), *context);
        llvm::outs() << "\n";
        Binding b;
        // for (auto s : n.second) {
        //   if (s != "clang_rewrite_top_level_match") {
        //     b.names.push_back(s);
        //   }
        // }
        // b.value = name;
        // bound_code.push_back(b);
        if (n.first != "clang_rewrite_top_level_match") {
          std::pair<StringRef, StringRef> split = StringRef(n.first).split(";");
          b.name = split.first.str();
          b.qual_name = split.second.str();
          b.value = name;
          b.kind = BindingKind::TypeBinding;
          bound_code.push_back(b);
        }
      }
      else {
        printf("ERROR: unknown node kind in NodeMap\n");
      }

    }

    // get other half of init list
    for (CodeAction* action : matcher->actions) {
      // do replace_bound_code variant on this
        // info needed:
        //  - range of second part of init list
      int offset = action->base_code_snippet.find(",") + 1;
      SourceRange init_list_second =
        SourceRange(action->snippet_range.getBegin().getLocWithOffset(offset),
                    action->snippet_range.getEnd().getLocWithOffset(-1));
        //  - range of match (have from this cb) (match_range)
        // do ReplaceBindingsCallback on second part of init list
      replace_bound_code(action, bound_code, init_list_second, action->spec_file_name);
        // replace range in og code with replaced second half of init list
      action->dump();
      action->dump_bindings(bound_code);
      printf("literals\n");
      action->dump_bindings(literal_bindings);
    }
    bound_code.clear();
  }

  void onEndOfTranslationUnit() override {
    // put rewritten code into edited_code_snippet of matcher action
  }

  void replace_bound_code(CodeAction* action, std::vector<Binding> bindings,
      SourceRange rep_range, std::string rep_file) {
    printf("OTHER REPLACE BOUND CODE\n");

    StatementMatcher inits_finder = callExpr(allOf(
      callee(functionDecl(hasName("clang_rewrite::loop_body"))),
      hasArgument(0, cxxBindTemporaryExpr(hasSubExpr(
        cxxConstructExpr(hasArgument(0,
          cxxStdInitializerListExpr(hasSubExpr(materializeTemporaryExpr(hasSubExpr(
            initListExpr(hasInit(0, cxxConstructExpr(allOf(
              hasArgument(0, expr(anything()).bind("matcher")),
              hasArgument(1, expr(anything()).bind("replacer"))
            )))).bind("clang_rewrite_init_list")
          ))))
        ))
      )))
    ));

    MatchFinder finder;
    ReplacerInternalCallback ri_cb(context, bindings, literal_bindings, rep_file, rep_range);
    finder.addMatcher(inits_finder, &ri_cb);

    Tool->run(newFrontendActionFactory(&finder).get());

    new_code = ri_cb.new_code;
    printf("new code\n%s\n", new_code.c_str());
    internal_rep_rw.resetAllRewriteBuffers(internal_rep_rw.getSourceMgr());

    action->edited_code_snippet = new_code;
    is_valid = true; // ??????
  }

};

}
}

#endif // CLANG_REWRTIE_INTERNAL_CALLBACK_H
