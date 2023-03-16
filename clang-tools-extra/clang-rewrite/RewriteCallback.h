#ifndef CLANG_REWRITE_CALLBACK_H
#define CLANG_REWRITE_CALLBACK_H

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

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace clang;
using namespace clang::ast_matchers;

using namespace clang::tooling;
using namespace llvm;

namespace clang {
namespace rewrite_tool {

Rewriter file_rw;
Rewriter binding_rw;
Rewriter attr_stripper_rw;

class DumpCallback : public MatchFinder::MatchCallback {
public:
  void run(const MatchFinder::MatchResult &result) override {

    const TranslationUnitDecl* tudecl = result.Nodes.getNodeAs<TranslationUnitDecl>("tudecl");

    if (!tudecl) {
      printf("ERROR: bad tudecl\n");
      return;
    }
    else {
      tudecl->dump();
    }
  }
};

class AttrStripperCallback : public MatchFinder::MatchCallback {
public:
  ASTContext* context;
  FileID fid;
  std::string newfname = temp_file_name;

  void run(const MatchFinder::MatchResult &result) override {
    printf("running AttrStripperCallback\n");

    context = result.Context;
    attr_stripper_rw.setSourceMgr(context->getSourceManager(), context->getLangOpts());

    const CompoundStmt* match = result.Nodes.getNodeAs<CompoundStmt>("match");
    const DeclStmt* setup = result.Nodes.getNodeAs<DeclStmt>("setup");
    const AttributedStmt* body = result.Nodes.getNodeAs<AttributedStmt>("body");

    // TODO: check if in temp file?
    if (!match) {
      printf("ERROR: invalid attr match\n");
      return;
    }

    FullSourceLoc full_loc(match->getBeginLoc(), context->getSourceManager());
    fid = full_loc.getFileID();

    if (setup) {
      SourceRange setup_range(setup->getBeginLoc(), setup->getEndLoc());
      setup_range.print(llvm::outs(), context->getSourceManager());
      setup->dump();
      attr_stripper_rw.RemoveText(setup_range);
    }

    if (body) {
      SourceRange body_range(body->getBeginLoc(), body->getEndLoc());
      body_range.print(llvm::outs(), context->getSourceManager());
      const Stmt* inner = body->getSubStmt();
      SourceRange inner_range(inner->getBeginLoc(), inner->getEndLoc());
      inner_range.print(llvm::outs(), context->getSourceManager());
      attr_stripper_rw.RemoveText(SourceRange(body->getBeginLoc(), inner->getBeginLoc())); // get attr and {
      attr_stripper_rw.RemoveText(body->getEndLoc(), 1); // get close }
    }
    else {
      printf("ERROR: no matcher_block attr to erase?\n");
    }

    attr_stripper_rw.RemoveText(match->getLBracLoc(), 1); // get compound stmt {
    attr_stripper_rw.RemoveText(match->getRBracLoc(), 1); // get compound stmt }


    const RewriteBuffer* buff = attr_stripper_rw.getRewriteBufferFor(fid);
    std::error_code erc;
    newfname = newfname + ".attr.cpp";

    raw_fd_ostream out(newfname, erc);
    buff->write(out);
    out.close();
  }

  void onEndOfTranslationUnit() override {
    // const RewriteBuffer* buff = attr_stripper_rw.getRewriteBufferFor(fid);
    // std::error_code erc;
    // std::string newfname = temp_file_name + ".final";
    //
    // raw_fd_ostream out(newfname, erc);
    // buff->write(out);
    // out.close();
  }
};

template <class T>
class RewriteCallback : public MatchFinder::MatchCallback {
public:
  ASTContext* context;
  MatcherWrapper<T>* matcher;

  std::vector<Binding> bindings;

  RewriteCallback(MatcherWrapper<T> *matcher) : matcher(matcher) {}

  ~RewriteCallback() {}

  void onStartOfTranslationUnit() override {}

  void run(const MatchFinder::MatchResult &result) override {
    printf("running RewriteCallback\n");

    context = result.Context;
    file_rw.setSourceMgr(context->getSourceManager(), context->getLangOpts());

    const Stmt *smatch = result.Nodes.getNodeAs<Stmt>("clang_rewrite_top_level_match");
    const Decl *dmatch = result.Nodes.getNodeAs<Decl>("clang_rewrite_top_level_match");
    // const Type *tmatch = result.Nodes.getNodeAs<Type>

    if ((!smatch ||
         !context->getSourceManager().getFilename(smatch->getBeginLoc()).endswith("clang_rewrite_temp_source.cpp"))
    && (!dmatch ||
        !context->getSourceManager().getFilename(dmatch->getBeginLoc()).endswith("clang_rewrite_temp_source.cpp"))) {
      // if (verbose) {
       printf("no match or invalid type\n");
      // }
      return;
    }

    // create list of bindings
    printf("making list of bindings\n");
    for (std::pair<std::string, DynTypedNode> n : result.Nodes.getMap()) {
      llvm::outs() << n.first << " : \n";
      // n.second.dump(llvm::outs(), *context);

      const Stmt *stmt = result.Nodes.getNodeAs<Stmt>(n.first);
      const NamedDecl *decl = result.Nodes.getNodeAs<NamedDecl>(n.first);
      const Type *type = result.Nodes.getNodeAs<Type>(n.first);

      if (stmt) {
        SourceRange code_range = stmt->getSourceRange();
        code_range.print(llvm::outs(), context->getSourceManager()); printf("\n");

        FullSourceLoc code_begin = context->getFullLoc(code_range.getBegin());

        // some nodes (like declRefExpr) have begin == end, so we want to get the
        // end of the *token*
        // others (like callExpr) have ending pointing to the start of the last
        // token (eg, ')' ), but we want to get that too
        // so in general it's best to just get the loc of the end of the token
        FullSourceLoc code_end = context->getFullLoc(Lexer::getLocForEndOfToken(
            code_range.getEnd(), 0, context->getSourceManager(),
            context->getLangOpts()));

        // if we can't get a valid beginning *and* end, skip this one
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

        char *code_c = new char[end_offset - begin_offset + 1];
        if (buff.has_value()) {
          memcpy(code_c, &(buff->getBufferStart()[begin_offset]),
                 (end_offset - begin_offset + 1) * sizeof(char));
          code_c[end_offset - begin_offset] =
              '\0'; // force null terminated for Reasons
          printf("code??? %s\n", code_c);
        } else {
          printf("no buffer :<\n");
        }
        std::string code(code_c);
        delete[] code_c;

        llvm::outs() << "\n";

        Binding b;
        if (n.first != "clang_rewrite_top_level_match") {
          std::pair<StringRef, StringRef> split = StringRef(n.first).split(";");
          b.name = split.first.str();
          b.qual_name = split.second.str();
          b.value = code;
          b.kind = BindingKind::VarNameBinding;
          bindings.push_back(b);
        }
      }
      else if (decl) {
        std::string name = decl->getNameAsString();
        std::string qualified_name = decl->getQualifiedNameAsString();
        printf("name: %s\n", name.c_str());
        printf("qualified name: %s\n", qualified_name.c_str());

        // n.second.dump(llvm::outs(), *context);
        llvm::outs() << "\n";

        Binding b;
        if (n.first != "clang_rewrite_top_level_match") {
          std::pair<StringRef, StringRef> split = StringRef(n.first).split(";");
          b.name = split.first.str();
          b.qual_name = split.second.str();
          b.value = name;
          b.kind = BindingKind::VarNameBinding;
          bindings.push_back(b);
        }
      }
      else if (type) {
        std::string name = QualType(type, 0).getAsString();
        printf("type name: %s\n", name.c_str());
        // n.second.dump(llvm::outs(), *context);
        llvm::outs() << "\n";

        Binding b;
        if (n.first != "clang_rewrite_top_level_match") {
          std::pair<StringRef, StringRef> split = StringRef(n.first).split(";");
          b.name = split.first.str();
          b.qual_name = split.second.str();
          b.value = name;
          b.kind = BindingKind::TypeBinding;
          bindings.push_back(b);
        }
      }
      else {
        printf("ERROR: unknown node kind in NodeMap\n");
      }
    }

    SourceRange original_range;
    std::string original_file;

    if (smatch) {
      original_range = SourceRange(smatch->getBeginLoc(), smatch->getEndLoc());
      original_file = context->getSourceManager().getFilename(smatch->getBeginLoc());
    }
    else if (dmatch) {
      original_range = SourceRange(dmatch->getBeginLoc(), dmatch->getEndLoc());
      original_file = context->getSourceManager().getFilename(dmatch->getBeginLoc());
    }

    // std::string binding_file_name = temp_file_name;
    // make temp file
    std::ofstream temp_file(temp_file_name + ".bind.cpp");
    // now to actually do the replacements
    for (CodeAction* action : matcher->actions) {

      SourceLocation file_begin = context->getSourceManager().getLocForStartOfFile(context->getFullLoc(original_range.getBegin()).getFileID());
      SourceLocation file_end = context->getSourceManager().getLocForEndOfFile(context->getFullLoc(original_range.getEnd()).getFileID());

      file_rw.ReplaceText(original_range, "{" + action->setup_code_snippet + "\n" + action->base_code_snippet + "}");
      //
      // file_rw.InsertText(file_begin, "#include \"ClangRewriteMacros.h\"\n");
      temp_file << file_rw.getRewrittenText(SourceRange(file_begin, file_end));
      temp_file.close();

      // replace all the bindings
      replace_bound_code(action, bindings);

      // std::ofstream bind_file(binding_file_name + ".bind.final");
      //
      // bind_file << binding_rw.getRewrittenText(SourceRange(file_begin, file_end));
      // bind_file.close();

      action->dump_bindings(bindings);
      // file_rw.resetAllRewriteBuffers(file_rw.getSourceMgr());
      bindings.clear();
      // remove the attrs in the replacements now that we're done
      strip_attrs();
    }


  }

  void onEndOfTranslationUnit() override {}

  void replace_bound_code(CodeAction* action, std::vector<Binding> all_bindings) {
    printf("REPLACE BOUND CODE\n");

    //TODO:
    //  - make temp file
    //  - write source file into temp file with replacer copy-pasted in over the match
    //  - rewrite as many bindings as we can, ENDING with macros for Reasons
    //  - kinda recurse on macros; make a new temp file with current rewrites,
    //    then do the thing
    //  - grab modified source range out of temp file, drop it into og file
    //  - ???
    //  - profit

    std::sort(all_bindings.begin(), all_bindings.end(), bindings_compare());

    std::vector<Binding> deferred_bindings;
    std::vector<Binding> current_bindings;
    for (Binding b: all_bindings) {
      if (StringRef(b.name).startswith("clang_rewrite") || StringRef(b.qual_name).startswith("clang_rewrite")) {
        deferred_bindings.push_back(b);
      }
    }

    std::set_difference(all_bindings.begin(), all_bindings.end(),
                        deferred_bindings.begin(), deferred_bindings.end(),
                        std::inserter(current_bindings, current_bindings.begin()),
                        bindings_compare());

    ClangTool binding_tool(Tool->getCompilationDatabase(), {temp_file_name + ".bind.cpp"});


    for (Binding b : current_bindings) {
      MatchFinder finder;
      ReplaceBindingsCallback cb(action, b, current_bindings);
      printf("LOOKING for things named %s or %s\n", b.name.c_str(), b.qual_name.c_str());

      if (b.kind == BindingKind::VarNameBinding) {
        if (!b.name.empty() && !b.qual_name.empty()) {
          VariantMatcher inner_matcher =
            constructBoundMatcher("namedDecl", "match",
              constructMatcher("anyOf",
                constructMatcher("hasName", StringRef(b.name), 5),
                constructMatcher("hasName", StringRef(b.qual_name), 5),
              4),
            3);
          VariantMatcher declmatcher =
            constructMatcher("attributedStmt",
              constructMatcher("allOf",
                constructMatcher("hasAttr", StringRef("attr::MatcherBlock"), 2),
                constructMatcher("hasDescendant",
                  constructMatcher("eachOf",
                    inner_matcher,
                    constructMatcher("forEachDescendant", inner_matcher, 4),
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

          VariantMatcher inner_matcher2 =
            constructBoundMatcher("declRefExpr", "match",
              constructMatcher("to",
                constructMatcher("namedDecl",
                  constructMatcher("anyOf",
                    constructMatcher("hasName", StringRef(b.name), 7),
                    constructMatcher("hasName", StringRef(b.qual_name), 7),
                  6),
                5),
              4),
            3);
          VariantMatcher refmatcher =
            constructMatcher("attributedStmt",
              constructMatcher("allOf",
                constructMatcher("hasAttr", StringRef("attr::MatcherBlock"), 2),
                constructMatcher("hasDescendant",
                  constructMatcher("eachOf",
                    inner_matcher2,
                    constructMatcher("forEachDescendant", inner_matcher2, 4),
                  3),
                2),
              1),
            0);

          dynmatcher = refmatcher.getSingleMatcher();
          if (dynmatcher) {
            finder.addDynamicMatcher(*dynmatcher, &cb);
          }
          else {
            printf("ERROR: bad ref matcher\n");
            return;
          }
        }

        else if (!b.name.empty() || !b.qual_name.empty()) {
          std::string valid_name = b.name.empty() ? b.qual_name : b.name;

          VariantMatcher inner_matcher =
            constructBoundMatcher("namedDecl", "match",
                constructMatcher("hasName", StringRef(valid_name), 4),
            3);
          VariantMatcher declmatcher =
            constructMatcher("attributedStmt",
              constructMatcher("allOf",
                constructMatcher("hasAttr", StringRef("attr::MatcherBlock"), 2),
                constructMatcher("hasDescendant",
                  constructMatcher("eachOf",
                    inner_matcher,
                    constructMatcher("forEachDescendant", inner_matcher, 4),
                  3),
                2),
              1),
            0);

          llvm::Optional<DynTypedMatcher> dynmatcher = declmatcher.getSingleMatcher();
          if (dynmatcher) {
            finder.addDynamicMatcher(*dynmatcher, &cb);
          }
          else {
            printf("ERROR: bad qual decl matcher\n");
            return;
          }

          VariantMatcher inner_matcher2 =
            constructBoundMatcher("declRefExpr", "match",
              constructMatcher("to",
                constructMatcher("namedDecl",
                  constructMatcher("hasName", StringRef(valid_name), 6),
                5),
              4),
            3);

          VariantMatcher refmatcher =
            constructMatcher("attributedStmt",
              constructMatcher("allOf",
                constructMatcher("hasAttr", StringRef("attr::MatcherBlock"), 2),
                constructMatcher("hasDescendant",
                  constructMatcher("eachOf",
                    inner_matcher2,
                    constructMatcher("forEachDescendant", inner_matcher2, 4),
                  3),
                2),
              1),
            0);

          dynmatcher = refmatcher.getSingleMatcher();
          if (dynmatcher) {
            finder.addDynamicMatcher(*dynmatcher, &cb);
          }
          else {
            printf("ERROR: bad qual ref matcher\n");
            return;
          }
        }

        else {
          printf("ERROR: no valid name to look for\n");
          return;
        }
      }
      else if (b.kind == BindingKind::TypeBinding) {
        if (!b.name.empty() && !b.qual_name.empty()) {
          VariantMatcher inner_matcher =
            constructBoundMatcher("expr", "match",
              constructMatcher("hasType",
                constructMatcher("anyOf",
                  constructMatcher("asString", StringRef(b.name), 6),
                  constructMatcher("asString", StringRef(b.qual_name), 6),
                5),
              4),
            3);

          VariantMatcher declmatcher =
            constructMatcher("attributedStmt",
              constructMatcher("allOf",
                constructMatcher("hasAttr", StringRef("attr::MatcherBlock"), 2),
                constructMatcher("hasDescendant",
                  constructMatcher("eachOf",
                    inner_matcher,
                    constructMatcher("forEachDescendant", inner_matcher, 4),
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
        }

        else if (!b.name.empty() || !b.qual_name.empty()) {
          std::string valid_name = b.name.empty() ? b.qual_name : b.name;

          VariantMatcher inner_matcher =
            constructBoundMatcher("expr", "match",
              constructMatcher("hasType",
                constructMatcher("ignoringPointers",
                  constructMatcher("asString", StringRef(valid_name), 6),
                5),
              4),
            3);
          VariantMatcher declmatcher =
            constructMatcher("attributedStmt",
              constructMatcher("allOf",
                constructMatcher("hasAttr", StringRef("attr::MatcherBlock"), 2),
                constructMatcher("hasDescendant",
                  constructMatcher("eachOf",
                    inner_matcher,
                    constructMatcher("forEachDescendant", inner_matcher, 4),
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
        }

        else {
          printf("ERROR: no valid name to look for\n");
          return;
        }
      }


      printf("RUNNING MATCH FINDER\n");
      int retval = binding_tool.run(newFrontendActionFactory(&finder).get());
      if (retval) {
        printf("OH NOES\n");
      }
    }
  }

  void strip_attrs() {
    // strip out attributes now that we're done
    StatementMatcher attr_block_matcher = compoundStmt(allOf(
      optionally(hasAnySubstatement(declStmt(
        containsAnyDeclaration(varDecl(hasAttr(attr::RewriteSetup)))
      ).bind("setup"))),
      hasAnySubstatement(attributedStmt(allOf(
        hasAttr(attr::MatcherBlock),
        hasSubStmt(compoundStmt(anything()))
      )).bind("body"))
    )).bind("match");

    MatchFinder attr_stripper;
    AttrStripperCallback attr_strip_cb;

    attr_stripper.addMatcher(attr_block_matcher, &attr_strip_cb);

    ClangTool process_temp(Tool->getCompilationDatabase(), {"clang_rewrite_temp_source.cpp.bind_final.cpp"});

    int retval = process_temp.run(newFrontendActionFactory(&attr_stripper).get());

    if (retval) {
      printf("OH NOES\n");
    }
  }
};

// template <class T> Rewriter RewriteCallback<T>::file_rw;

}
}// namespaces

#endif //CLANG_REWRITE_CALLBACK_H
