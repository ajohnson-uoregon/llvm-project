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
#include "CodeLiteralsCallback.h"

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

class SetupStripperCallback : public MatchFinder::MatchCallback {
public:
  ASTContext* context;
  FileID fid;
  std::string newfname = temp_file_name;


  void run(const MatchFinder::MatchResult &result) override {
    printf("running SetupStripperCallback\n");

    context = result.Context;
    attr_stripper_rw.setSourceMgr(context->getSourceManager(), context->getLangOpts());

    const DeclStmt* setup = result.Nodes.getNodeAs<DeclStmt>("setup");

    if (!setup) {
      printf("ERROR: invalid setup section match\n");
      return;
    }

    FullSourceLoc full_loc(setup->getBeginLoc(), context->getSourceManager());
    fid = full_loc.getFileID();

    SourceRange setup_range(setup->getBeginLoc(), setup->getEndLoc());
    setup_range.print(llvm::outs(), context->getSourceManager());
    setup->dump();
    attr_stripper_rw.RemoveText(setup_range);

    if (attr_stripper_rw.overwriteChangedFiles())
    {
      printf("FILE NOT SAVED\n");
    }

    const RewriteBuffer* buff = attr_stripper_rw.getRewriteBufferFor(fid);
    std::error_code erc;
    newfname = newfname + ".attr.cpp";

    if (buff) {
      raw_fd_ostream out(newfname, erc);
      buff->write(out);
      out.close();
    }
  }

  void onEndOfTranslationUnit() override {
    attr_stripper_rw.clearAllRewriteBuffers(attr_stripper_rw.getSourceMgr());
  }
};

class AttrStripperCallback : public MatchFinder::MatchCallback {
public:
  ASTContext* context;
  FileID fid;
  std::string newfname = temp_file_name;
  std::string new_text = "";

  void run(const MatchFinder::MatchResult &result) override {
    printf("running AttrStripperCallback\n");

    context = result.Context;
    attr_stripper_rw.setSourceMgr(context->getSourceManager(), context->getLangOpts());

    const CompoundStmt* match = result.Nodes.getNodeAs<CompoundStmt>("match");
    const AttributedStmt* body = result.Nodes.getNodeAs<AttributedStmt>("body");

    // TODO: check if in temp file?
    if (!match && !body) {
      printf("ERROR: invalid attr match\n");
      return;
    }

    FullSourceLoc full_loc(match->getBeginLoc(), context->getSourceManager());
    fid = full_loc.getFileID();

    SourceRange body_range(body->getBeginLoc(), body->getEndLoc());
    body_range.print(llvm::outs(), context->getSourceManager());
    const Stmt* inner = body->getSubStmt();
    SourceRange inner_range(inner->getBeginLoc(), inner->getEndLoc());
    inner_range.print(llvm::outs(), context->getSourceManager());
    attr_stripper_rw.RemoveText(SourceRange(body->getBeginLoc(), inner->getBeginLoc())); // get attr and {
    attr_stripper_rw.RemoveText(body->getEndLoc(), 1); // get close }

    attr_stripper_rw.RemoveText(match->getLBracLoc(), 1); // get compound stmt {
    attr_stripper_rw.RemoveText(match->getRBracLoc(), 1); // get compound stmt }

    if (attr_stripper_rw.overwriteChangedFiles())
    {
      printf("FILE NOT SAVED\n");
    }

    const RewriteBuffer* buff = attr_stripper_rw.getRewriteBufferFor(fid);
    std::error_code erc;
    newfname = newfname + ".attr.cpp";

    if (buff) {
      raw_fd_ostream out(newfname, erc);
      buff->write(out);
      out.close();
    }

    new_text = attr_stripper_rw.getRewrittenText(SourceRange(match->getLBracLoc(), match->getRBracLoc()));
  }

  void onEndOfTranslationUnit() override {
    attr_stripper_rw.clearAllRewriteBuffers(attr_stripper_rw.getSourceMgr());
    // const RewriteBuffer* buff = attr_stripper_rw.getRewriteBufferFor(fid);
    // std::error_code erc;
    // std::string newfname = temp_file_name + ".final";
    //
    // raw_fd_ostream out(newfname, erc);
    // buff->write(out);
    // out.close();
  }
};

std::vector<Binding> create_bindings(const MatchFinder::MatchResult &result,
                                     ASTContext* context) {
  printf("making list of bindings\n");
  std::vector<Binding> bindings;
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

      std::optional<llvm::MemoryBufferRef> buff =
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
      if (n.first != "clang_rewrite_top_level_match" && n.first != "clang_rewrite_match") {
        std::pair<StringRef, StringRef> split = StringRef(n.first).split(";");
        b.name = split.first.str();
        b.qual_name = split.second.str();
        VariantMatcher inner_matcher;
        if (!b.name.empty() && !b.qual_name.empty()) {
          inner_matcher =
            constructMatcher("declStmt",
              constructMatcher("containsAnyDeclaration",
                constructBoundMatcher("namedDecl", "clang_rewrite_match",
                  constructMatcher("anyOf",
                    constructMatcher("hasName", StringRef(b.name), 7),
                    constructMatcher("hasName", StringRef(b.qual_name), 7),
                  6),
                5),
              4),
            3);
        }
        else if (!b.name.empty() || !b.qual_name.empty()) {
          std::string valid_name = b.name.empty() ? b.qual_name : b.name;
          inner_matcher =
            constructMatcher("declStmt",
              constructMatcher("containsAnyDeclaration",
                constructBoundMatcher("namedDecl", "clang_rewrite_match",
                  constructMatcher("hasName", StringRef(valid_name), 6), 5),
              4),
            3);
        }
        else {
          printf("ERROR: no valid name\n");
        }
        b.matchers.push_back(inner_matcher);

        VariantMatcher inner_matcher2;
        if (!b.name.empty() && !b.qual_name.empty()) {
          inner_matcher2 =
            constructBoundMatcher("declRefExpr", "clang_rewrite_match",
              constructMatcher("to",
                constructMatcher("namedDecl",
                  constructMatcher("anyOf",
                    constructMatcher("hasName", StringRef(b.name), 7),
                    constructMatcher("hasName", StringRef(b.qual_name), 7),
                  6),
                5),
              4),
            3);
        }
        else if (!b.name.empty() || !b.qual_name.empty()) {
          std::string valid_name = b.name.empty() ? b.qual_name : b.name;
          inner_matcher2 =
            constructBoundMatcher("declRefExpr", "clang_rewrite_match",
              constructMatcher("to",
                constructMatcher("namedDecl",
                    constructMatcher("hasName", StringRef(valid_name), 6),
                5),
              4),
            3);
        }
        else {
          printf("ERROR: no valid name\n");
        }
        b.matchers.push_back(inner_matcher2);

        VariantMatcher inner_matcher3;
        if (!b.name.empty() && !b.qual_name.empty()) {
          inner_matcher3 =
            constructBoundMatcher("parmVarDecl", "clang_rewrite_match",
              constructMatcher("anyOf",
                constructMatcher("hasName", StringRef(b.name), 5),
                constructMatcher("hasName", StringRef(b.qual_name), 5),
            4),
          3);
        }
        else if (!b.name.empty() || !b.qual_name.empty()) {
          std::string valid_name = b.name.empty() ? b.qual_name : b.name;
          inner_matcher3 =
            constructBoundMatcher("parmVarDecl", "clang_rewrite_match",
              constructMatcher("hasName", StringRef(valid_name), 4),
          3);
        }
        else {
          printf("ERROR: no valid name\n");
        }
        b.matchers.push_back(inner_matcher3);

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
      if (n.first != "clang_rewrite_top_level_match" && n.first != "clang_rewrite_match") {
        std::pair<StringRef, StringRef> split = StringRef(n.first).split(";");
        b.name = split.first.str();
        b.qual_name = split.second.str();
        if (!b.name.empty() && !b.qual_name.empty()) {
          VariantMatcher inner_matcher =
            constructMatcher("declStmt",
              constructMatcher("containsAnyDeclaration",
                constructBoundMatcher("namedDecl", "clang_rewrite_match",
                  constructMatcher("anyOf",
                    constructMatcher("hasName", StringRef(b.name), 7),
                    constructMatcher("hasName", StringRef(b.qual_name), 7),
                  6),
                5),
              4),
            3);
          b.matchers.push_back(inner_matcher);
          VariantMatcher inner_matcher2 =
            constructBoundMatcher("declRefExpr", "clang_rewrite_match",
              constructMatcher("to",
                constructMatcher("namedDecl",
                  constructMatcher("anyOf",
                    constructMatcher("hasName", StringRef(b.name), 7),
                    constructMatcher("hasName", StringRef(b.qual_name), 7),
                  6),
                5),
              4),
            3);
          b.matchers.push_back(inner_matcher2);
          b.value = name;
          b.kind = BindingKind::VarNameBinding;
          bindings.push_back(b);
        }
        else if (!b.name.empty() || !b.qual_name.empty()) {
          std::string valid_name = b.name.empty() ? b.qual_name : b.name;
          VariantMatcher inner_matcher =
            constructMatcher("declStmt",
              constructMatcher("containsAnyDeclaration",
                constructBoundMatcher("namedDecl", "clang_rewrite_match",
                  constructMatcher("hasName", StringRef(valid_name), 6), 5),
              4),
            3);
          b.matchers.push_back(inner_matcher);
          VariantMatcher inner_matcher2 =
            constructBoundMatcher("declRefExpr", "clang_rewrite_match",
              constructMatcher("to",
                constructMatcher("namedDecl",
                    constructMatcher("hasName", StringRef(valid_name), 6),
                5),
              4),
            3);
          b.matchers.push_back(inner_matcher2);
          b.value = name;
          b.kind = BindingKind::VarNameBinding;
          bindings.push_back(b);
        }
        else {
          printf("ERROR: no valid name for decl\n");
        }
      }
    }
    else if (type) {
      std::string name = QualType(type, 0).getAsString();
      printf("type name: %s\n", name.c_str());
      // n.second.dump(llvm::outs(), *context);
      llvm::outs() << "\n";

      Binding b;
      if (n.first != "clang_rewrite_top_level_match" && n.first != "clang_rewrite_match") {
        std::pair<StringRef, StringRef> split = StringRef(n.first).split(";");
        b.name = split.first.str();
        b.qual_name = split.second.str();
        if (!b.name.empty() && !b.qual_name.empty()) {
          VariantMatcher inner_matcher =
            constructBoundMatcher("expr", "clang_rewrite_match",
              constructMatcher("hasType",
                constructMatcher("ignoringPointers",
                  constructMatcher("anyOf",
                    constructMatcher("asString", StringRef(b.name), 7),
                    constructMatcher("asString", StringRef(b.qual_name), 7),
                  6),
                5),
              4),
            3);
          b.matchers.push_back(inner_matcher);

          VariantMatcher inner_matcher2 =
            constructBoundMatcher("valueDecl", "clang_rewrite_match",
              constructMatcher("hasType",
                constructMatcher("elaboratedType",
                  constructMatcher("namesType",
                    constructMatcher("templateSpecializationType",
                      constructMatcher("hasAnyTemplateArgument",
                        constructMatcher("templateArgument",
                          constructMatcher("refersToType",
                            constructMatcher("ignoringPointers",
                              constructMatcher("anyOf",
                                constructMatcher("asString", StringRef(b.name), 13),
                                constructMatcher("asString", StringRef(b.qual_name), 13),
                              12),
                            11),
                          10),
                        9),
                      8),
                    7),
                  6),
                5),
              4),
            3);
          b.matchers.push_back(inner_matcher2);
          b.value = name;
          b.kind = BindingKind::TypeBinding;
          bindings.push_back(b);
        }
        else if (!b.name.empty() || !b.qual_name.empty()) {
          std::string valid_name = b.name.empty() ? b.qual_name : b.name;
          VariantMatcher inner_matcher =
            constructBoundMatcher("expr", "clang_rewrite_match",
              constructMatcher("hasType",
                constructMatcher("ignoringPointers",
                  constructMatcher("asString", StringRef(valid_name), 6),
                5),
              4),
            3);
          b.matchers.push_back(inner_matcher);

          VariantMatcher inner_matcher2 =
            constructBoundMatcher("valueDecl", "clang_rewrite_match",
              constructMatcher("hasType",
                constructMatcher("elaboratedType",
                  constructMatcher("namesType",
                    constructMatcher("templateSpecializationType",
                      constructMatcher("hasAnyTemplateArgument",
                        constructMatcher("templateArgument",
                          constructMatcher("refersToType",
                            constructMatcher("ignoringPointers",
                              constructMatcher("asString", StringRef(valid_name), 12),
                            11),
                          10),
                        9),
                      8),
                    7),
                  6),
                5),
              4),
            3);
          b.matchers.push_back(inner_matcher2);
          b.value = name;
          b.kind = BindingKind::TypeBinding;
          bindings.push_back(b);
        }
        else {
          printf("ERROR: no valid name for type\n");
        }
      }
    }
    else {
      printf("ERROR: unknown node kind in NodeMap\n");
    }
  }
  return bindings;
}

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
    bindings = create_bindings(result, context);

    StatementMatcher code_literals = declStmt(containsAnyDeclaration(varDecl(
      hasInitializer(hasDescendant(
        callExpr(callee(unresolvedLookupExpr(
          hasAnyDeclaration(functionTemplateDecl(
            hasName("clang_rewrite::code_literal")
          ))
        ))).bind("code_literal_call")
      ))
    ).bind("code_literal_decl")));

    MatchFinder code_literals_finder;
    CodeLiteralsCallback literals_callback(&bindings);

    code_literals_finder.addMatcher(code_literals, &literals_callback);

    ClangTool process_temp(Tool->getCompilationDatabase(), {"clang_rewrite_temp_source.cpp.rewritten_spec.cpp"});
    process_temp.run(newFrontendActionFactory(&code_literals_finder).get());

    for (Binding& b: bindings) {
      if (b.matchers.empty()) {
        // copy pasta from create_bindings()
        VariantMatcher inner_matcher;
        if (!b.name.empty() && !b.qual_name.empty()) {
          inner_matcher =
            constructMatcher("declStmt",
              constructMatcher("containsAnyDeclaration",
                constructBoundMatcher("namedDecl", "clang_rewrite_match",
                  constructMatcher("anyOf",
                    constructMatcher("hasName", StringRef(b.name), 7),
                    constructMatcher("hasName", StringRef(b.qual_name), 7),
                  6),
                5),
              4),
            3);
        }
        else if (!b.name.empty() || !b.qual_name.empty()) {
          std::string valid_name = b.name.empty() ? b.qual_name : b.name;
          inner_matcher =
            constructMatcher("declStmt",
              constructMatcher("containsAnyDeclaration",
                constructBoundMatcher("namedDecl", "clang_rewrite_match",
                  constructMatcher("hasName", StringRef(valid_name), 6), 5),
              4),
            3);
        }
        else {
          printf("ERROR: no valid name\n");
        }
        b.matchers.push_back(inner_matcher);

        VariantMatcher inner_matcher2;
        if (!b.name.empty() && !b.qual_name.empty()) {
          inner_matcher2 =
            constructBoundMatcher("declRefExpr", "clang_rewrite_match",
              constructMatcher("to",
                constructMatcher("namedDecl",
                  constructMatcher("anyOf",
                    constructMatcher("hasName", StringRef(b.name), 7),
                    constructMatcher("hasName", StringRef(b.qual_name), 7),
                  6),
                5),
              4),
            3);
        }
        else if (!b.name.empty() || !b.qual_name.empty()) {
          std::string valid_name = b.name.empty() ? b.qual_name : b.name;
          inner_matcher2 =
            constructBoundMatcher("declRefExpr", "clang_rewrite_match",
              constructMatcher("to",
                constructMatcher("namedDecl",
                    constructMatcher("hasName", StringRef(valid_name), 6),
                5),
              4),
            3);
        }
        else {
          printf("ERROR: no valid name\n");
        }
        b.matchers.push_back(inner_matcher2);

        VariantMatcher inner_matcher3;
        if (!b.name.empty() && !b.qual_name.empty()) {
          inner_matcher3 =
            constructBoundMatcher("parmVarDecl", "clang_rewrite_match",
              constructMatcher("anyOf",
                constructMatcher("hasName", StringRef(b.name), 5),
                constructMatcher("hasName", StringRef(b.qual_name), 5),
            4),
          3);
        }
        else if (!b.name.empty() || !b.qual_name.empty()) {
          std::string valid_name = b.name.empty() ? b.qual_name : b.name;
          inner_matcher3 =
            constructBoundMatcher("parmVarDecl", "clang_rewrite_match",
              constructMatcher("hasName", StringRef(valid_name), 4),
          3);
        }
        else {
          printf("ERROR: no valid name\n");
        }
        b.matchers.push_back(inner_matcher3);
      }
    }

    SourceRange original_range;
    std::string original_file;

    if (smatch) {
      if (const OMPExecutableDirective* prag = dyn_cast<OMPExecutableDirective>(smatch)) {
        original_range = SourceRange(prag->getBeginLoc(), prag->getAssociatedStmt()->getEndLoc());
      }
      else {
        original_range = SourceRange(smatch->getBeginLoc(), smatch->getEndLoc());
      }
      original_file = context->getSourceManager().getFilename(smatch->getBeginLoc());
    }
    else if (dmatch) {
      original_range = SourceRange(dmatch->getBeginLoc(), dmatch->getEndLoc());
      original_file = context->getSourceManager().getFilename(dmatch->getBeginLoc());
    }

    // std::string binding_file_name = temp_file_name;
    // make temp file
    std::ofstream temp_file(temp_file_name +  "." + std::to_string(num_bind_files) + ".bind.cpp");

    // now to actually do the replacements

    SourceLocation file_begin;
    SourceLocation file_end;
    file_begin = context->getSourceManager().getLocForStartOfFile(context->getFullLoc(original_range.getBegin()).getFileID());
    file_end = context->getSourceManager().getLocForEndOfFile(context->getFullLoc(original_range.getEnd()).getFileID());

    // for (CodeAction* action : matcher->actions) {
    if (matcher->actions.size() == 1) {
      CodeAction* action = matcher->actions[0];

      std::string setup_adjustment = "";
      if (dmatch) {
        printf("DECL\n");
      }
      else if (smatch) {
        printf("STMT\n");
        for (Binding b : bindings) {
          if (b.kind == TypeBinding) {
            setup_adjustment += "class [[clang::rewrite_setup]] " + b.name + " {};\n";
          }
        }
      }
      file_rw.ReplaceText(original_range, "{" +
            action->setup_code_snippet + "\n" +
            setup_adjustment + "\n" +
            action->base_code_snippet + "}");
      // file_rw.overwriteChangedFiles();
      //
      // file_rw.InsertText(file_begin, "#include \"ClangRewriteMacros.h\"\n");
      temp_file << file_rw.getRewrittenText(SourceRange(file_begin, file_end));
      temp_file.close();

      // replace all the bindings
      replace_bound_code(action, bindings);
      // binding_rw.overwriteChangedFiles();

      // std::ofstream bind_file(binding_file_name + ".bind.final");
      //
      // bind_file << binding_rw.getRewrittenText(SourceRange(file_begin, file_end));
      // bind_file.close();

      action->dump_bindings(bindings);
      // file_rw.resetAllRewriteBuffers(file_rw.getSourceMgr());
      bindings.clear();
      // remove the attrs in the replacements now that we're done
    }
    // }
    else {
      printf("WARNING: only one action currently supported\n");
    }

    std::string new_code = strip_attrs();
    file_rw.ReplaceText(original_range, new_code);
    file_rw.overwriteChangedFiles();

    // TODO
    // get rewritten text for range in .attr.cpp
    // copy paste over text in source.cpp
    // repeat
    // copy source.cpp back over og file

    // file_rw.resetAllRewriteBuffers(file_rw.getSourceMgr());
    binding_rw.resetAllRewriteBuffers(binding_rw.getSourceMgr());
    attr_stripper_rw.resetAllRewriteBuffers(attr_stripper_rw.getSourceMgr());

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
      if (StringRef(b.name).startswith("clang_rewrite::") || StringRef(b.qual_name).startswith("clang_rewrite::")) {
        deferred_bindings.push_back(b);
      }
    }

    std::set_difference(all_bindings.begin(), all_bindings.end(),
                        deferred_bindings.begin(), deferred_bindings.end(),
                        std::inserter(current_bindings, current_bindings.begin()),
                        bindings_compare());




    while (!current_bindings.empty()) {
      for (Binding& b : current_bindings) {
        ClangTool binding_tool(Tool->getCompilationDatabase(), {temp_file_name + "." + std::to_string(num_bind_files) + ".bind.cpp"});
        binding_tool.setRestoreWorkingDir(false);
        MatchFinder finder;
        ReplaceBindingsCallback cb(action, b, all_bindings, &current_bindings);
        printf("LOOKING for things named %s or %s in %s\n", b.name.c_str(), b.qual_name.c_str(), std::string(temp_file_name + "." + std::to_string(num_bind_files) + ".bind.cpp").c_str());
        dump_binding(b);

        if (b.kind == BindingKind::VarNameBinding) {
          for (VariantMatcher matcher : b.matchers) {
            VariantMatcher declmatcher =
              constructMatcher("attributedStmt",
                constructMatcher("allOf",
                  constructMatcher("hasAttr", StringRef("attr::MatcherBlock"), 2),
                  constructMatcher("hasDescendant",
                    constructMatcher("eachOf",
                      matcher,
                      constructMatcher("forEachDescendant", matcher, 4),
                    3),
                  2),
                1),
              0);

            std::optional<DynTypedMatcher> dynmatcher = declmatcher.getSingleMatcher();
            if (dynmatcher) {
              finder.addDynamicMatcher(*dynmatcher, &cb);
            }
            else {
              printf("ERROR: bad var name matcher\n");
            }

            VariantMatcher setupmatcher =
              constructBoundMatcher("declStmt", "clang_rewrite_top_level_match",
                constructMatcher("containsAnyDeclaration",
                  constructMatcher("varDecl",
                    constructMatcher("allOf",
                      constructMatcher("hasAttr", StringRef("attr::RewriteSetup"), 4),
                      matcher,
                    3),
                  2),
                1),
              0);

            std::optional<DynTypedMatcher> setupdynmatcher = setupmatcher.getSingleMatcher();
            if (setupdynmatcher) {
              finder.addDynamicMatcher(*setupdynmatcher, &cb);
            }
            else {
              printf("ERROR: bad var name setup matcher\n");
            }
          }

        }
        else if (b.kind == BindingKind::TypeBinding) {
          for (VariantMatcher matcher : b.matchers) {
            VariantMatcher declmatcher =
              constructMatcher("attributedStmt",
                constructMatcher("allOf",
                  constructMatcher("hasAttr", StringRef("attr::MatcherBlock"), 2),
                  constructMatcher("hasDescendant",
                    constructMatcher("eachOf",
                      matcher,
                      constructMatcher("forEachDescendant", matcher, 4),
                    3),
                  2),
                1),
              0);

            std::optional<DynTypedMatcher> dynmatcher = declmatcher.getSingleMatcher();
            if (dynmatcher) {
              finder.addDynamicMatcher(*dynmatcher, &cb);
            }
            else {
              printf("ERROR: bad type binding matcher\n");
            }
          }
        }
        else {
          printf("ERROR: invalid binding kind\n");
        }


        printf("RUNNING MATCH FINDER\n");
        int retval = binding_tool.run(newFrontendActionFactory(&finder).get());
        if (retval) {
          printf("OH NOES\n");
        }
        deferred_bindings.insert(deferred_bindings.begin(), cb.inner_bindings.begin(), cb.inner_bindings.end());
        cb.inner_bindings.clear();
      }

      auto last = std::unique(deferred_bindings.begin(), deferred_bindings.end());
      deferred_bindings.erase(last, deferred_bindings.end());

      printf("DEFERRED BINDINGS\n");
      for (Binding b : deferred_bindings) {
        dump_binding(b);
      }

      current_bindings = deferred_bindings;
      deferred_bindings.clear();
      // binding_rw.overwriteChangedFiles();
    }
  }

  std::string strip_attrs() {
    // strip out attributes now that we're done
    StatementMatcher attr_block_matcher = compoundStmt(
      hasAnySubstatement(attributedStmt(allOf(
        hasAttr(attr::MatcherBlock),
        hasSubStmt(compoundStmt(anything()))
      )).bind("body"))
    ).bind("match");

    StatementMatcher setup_matcher = declStmt(
      containsAnyDeclaration(varDecl(hasAttr(attr::RewriteSetup)))
    ).bind("setup");

    StatementMatcher class_setup_matcher = declStmt(
      containsAnyDeclaration(cxxRecordDecl(hasAttr(attr::RewriteSetup)))
    ).bind("setup");

    MatchFinder setup_stripper;
    SetupStripperCallback setup_strip_cb;

    setup_stripper.addMatcher(setup_matcher, &setup_strip_cb);
    setup_stripper.addMatcher(class_setup_matcher, &setup_strip_cb);

    ClangTool process_setup(Tool->getCompilationDatabase(), {"clang_rewrite_temp_source.cpp.bind_final.cpp"});
    process_setup.setRestoreWorkingDir(false);
    int retval = process_setup.run(newFrontendActionFactory(&setup_stripper).get());

    MatchFinder attr_stripper;
    AttrStripperCallback attr_strip_cb;

    attr_stripper.addMatcher(attr_block_matcher, &attr_strip_cb);
    attr_stripper.addMatcher(setup_matcher, &attr_strip_cb);

    ClangTool process_temp(Tool->getCompilationDatabase(), {"clang_rewrite_temp_source.cpp.bind_final.cpp"});
    process_temp.setRestoreWorkingDir(false);
    retval = process_temp.run(newFrontendActionFactory(&attr_stripper).get());

    printf("OWO???\n%s", attr_strip_cb.new_text.c_str());

    if (retval) {
      printf("OH NOES\n");
    }

    return attr_strip_cb.new_text.c_str();
  }
};

// template <class T> Rewriter RewriteCallback<T>::file_rw;

}
}// namespaces

#endif //CLANG_REWRITE_CALLBACK_H
