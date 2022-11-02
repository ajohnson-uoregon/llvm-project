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

bool isLine(const Stmt *stmt) {
  if (isa<AsmStmt>(stmt) || isa<NullStmt>(stmt) || isa<ReturnStmt>(stmt) ||
      isa<ValueStmt>(stmt) // exprs
  ) {
    return true;
  } else {
    return false;
  }
}

bool isLine(const Decl* decl) {
  if (isa<AccessSpecDecl>(decl) ||
      isa<BindingDecl>(decl) ||
      isa<EmptyDecl>(decl) ||
      isa<EnumConstantDecl>(decl) ||
      isa<ExportDecl>(decl) ||
      isa<FieldDecl>(decl) ||
      isa<ImportDecl>(decl) ||
      isa<LinkageSpecDecl>(decl) ||
      isa<PragmaCommentDecl>(decl) ||
      isa<PragmaDetectMismatchDecl>(decl) ||
      isa<TypeAliasTemplateDecl>(decl) ||
      isa<TypedefNameDecl>(decl) ||
      isa<VarDecl>(decl) ||
      isa<VarTemplateDecl>(decl)) {
    return true;
  }
  else {
    return false;
  }
}

bool isBlock(const Stmt *stmt) {
  if (isa<CompoundStmt>(stmt) || isa<CoroutineBodyStmt>(stmt) ||
      isa<CXXCatchStmt>(stmt) || isa<CXXForRangeStmt>(stmt) ||
      isa<CXXTryStmt>(stmt) || isa<DoStmt>(stmt) || isa<ForStmt>(stmt) ||
      isa<IfStmt>(stmt) || isa<SwitchCase>(stmt) || isa<SwitchStmt>(stmt) ||
      isa<WhileStmt>(stmt)) {
    return true;
  } else {
    return false;
  }
}

bool isBlock(const Decl* decl) {
  if (isa<BlockDecl>(decl) ||
      isa<ClassScopeFunctionSpecializationDecl>(decl) ||
      isa<ClassTemplateDecl>(decl) ||
      isa<FunctionDecl>(decl) ||
      isa<FunctionTemplateDecl>(decl) ||
      isa<TagDecl>(decl)) {
    return true;
  }
  else {
    return false;
  }
}

// TODO:
// - DeclStmt
// - IndirectGotoStmt
// - CapturedDecl
// - FriendDecl
// - RequiresExprBodyDecl
// - TranslationUnitDecl
// - TemplateParamObjectDecl
static Rewriter binding_rw;

class ReplaceBindingsCallback : public MatchFinder::MatchCallback {
public:
  ASTContext* context;
  CodeAction* action;
  Binding bind;
  Rewriter::RewriteOptions opts;

  ReplaceBindingsCallback(CodeAction* action, Binding b)
    : action(action), bind(b) {
      opts.IncludeInsertsAtBeginOfRange = false;
    }

  ~ReplaceBindingsCallback() {}

  void onStartOfTranslationUnit() override {}

  void run(const MatchFinder::MatchResult &result) override {
    // printf("RUNNING THE THING\n");
    printf("found match for binding\n");
    context = result.Context;
    binding_rw.setSourceMgr(context->getSourceManager(), context->getLangOpts());

    const Expr* expr = result.Nodes.getNodeAs<Expr>("match");
    const NamedDecl* decl = result.Nodes.getNodeAs<NamedDecl>("match");

    bool expr_valid = true;
    bool decl_valid = true;

    if (!expr ||
        !context->getSourceManager().isInFileID(expr->getBeginLoc(), action->spec_file))
         {
      // printf("ERROR: invalid expr binding match loc\n");
      expr_valid = false;
    }

    if (!decl ||
        !context->getSourceManager().isInFileID(decl->getBeginLoc(), action->spec_file)) {
      // printf("ERROR: invalid decl binding match loc\n");
      decl_valid = false;
    }

    if (!expr_valid && !decl_valid) {
      printf("ERROR: no valid binding match loc\n");
      return;
    }

    SourceRange match_range;
    if (expr_valid) {
      // printf("expr valid\n");
      match_range = SourceRange(expr->getBeginLoc(), expr->getEndLoc());
    }
    else if (decl_valid) {
      // printf("decl valid\n");
      match_range = SourceRange(decl->getBeginLoc(), decl->getEndLoc());
    }

    printf("action source range\n");
    action->snippet_range.dump(context->getSourceManager());
    printf("match range\n");
    match_range.dump(context->getSourceManager());
    if (!action->snippet_range.fullyContains(match_range)) {
      printf("ERROR: match not in action's snippet\n");
      return;
    }


    FullSourceLoc begin;
    FullSourceLoc end;
    FullSourceLoc match;

    if (expr_valid) {
      if (bind.name == "clang_rewrite::loop_body" ||
          bind.qual_name == "clang_rewrite::loop_body") {
        printf("YAY LOOP BODY\n");
        // auto parentmap = context->getParentMapContext().getParents(*expr);
        DynTypedNodeList Parents = context->getParents(*expr);
        llvm::SmallVector<DynTypedNode, 8> Stack(Parents.begin(), Parents.end());
        while (!Stack.empty()) {
          const auto &CurNode = Stack.back();
          Stack.pop_back();
          if (const CompoundStmt* comp = CurNode.get<CompoundStmt>()) {
            begin = context->getFullLoc(comp->getLBracLoc());
            end = context->getFullLoc(comp->getRBracLoc());
            match = begin;
            break;
          } else {
            llvm::append_range(Stack, context->getParents(CurNode));
          }
        }
      }
      else {
        begin = context->getFullLoc(expr->getBeginLoc());
        end = context->getFullLoc(expr->getEndLoc());
        match = context->getFullLoc(expr->getBeginLoc());
      }
    }
    else if (decl_valid) {
      begin = context->getFullLoc(decl->getBeginLoc());
      end = context->getFullLoc(decl->getEndLoc());
      match = context->getFullLoc(decl->getLocation());
    }

    unsigned int begin_line = begin.getSpellingLineNumber();
    unsigned int begin_col = begin.getSpellingColumnNumber();
    unsigned int end_line = end.getSpellingLineNumber();
    unsigned int end_col = end.getSpellingColumnNumber();

    FileID fid = begin.getFileID();
    unsigned int begin_offset = begin.getFileOffset();
    unsigned int end_offset = end.getFileOffset();
    unsigned int match_offset = match.getFileOffset();

    if (begin_offset == end_offset) {
      printf("one char match, luls\n");
      end_offset += 1;
    }

    printf("FOUND match for binding at %d:%d - %d:%d\n",
           begin_line, begin_col, end_line, end_col);

    llvm::Optional<llvm::MemoryBufferRef> buff =
      context->getSourceManager().getBufferOrNone(fid);

    char* code = new char[end_offset - begin_offset + 1];
    if (buff.has_value()) {
      memcpy(code, &(buff->getBufferStart()[begin_offset]),
             (end_offset - begin_offset + 1) * sizeof(char));
      code[end_offset - begin_offset] = '\0';
      printf("matched range: %s\n", code);
      printf("               ");
      for (unsigned int i = 0; i < match_offset - begin_offset; i++) {
        printf(" ");
      }
      printf("^\n");
    }
    delete[] code;


    if (expr_valid && (bind.name == "clang_rewrite::loop_body" ||
        bind.qual_name == "clang_rewrite::loop_body")) {
      binding_rw.ReplaceText(begin, end_offset - begin_offset + 1, bind.value);
    }
    else if (expr_valid) {
      printf("expr\n");
      expr->dump();

      char* name_c = new char[end_offset - match_offset + 1];
      size_t space;
      if (buff.has_value()) {
        memcpy(name_c, &(buff->getBufferStart()[match_offset]),
               (end_offset - match_offset + 1) * sizeof(char));
        name_c[end_offset - match_offset] = '\0';
        StringRef name(name_c);
        // TODO something clever to figure out which name was used in the og
        // code, use that as the length of stuff to replace
        if (bind.name == bind.qual_name) {
          space = bind.name.size();
        }
        else if (bind.name.empty()) {
          space = bind.qual_name.size();
        }
        else if (bind.qual_name.empty()) {
          space = bind.name.size();
        }
        else if (name.find(" ") != StringRef::npos) {
          space = name.find(" ");
        }
        else {
          space = 1;
        }
        printf("oh noes %lu\n", space);

        expr->getExprLoc().dump(context->getSourceManager());
        binding_rw.ReplaceText(expr->getExprLoc(), space, bind.value);
      }
    }
    else if (decl_valid) {
      printf("decl\n");
      decl->dump();

      char* name_c = new char[end_offset - match_offset + 1];
      size_t space;
      if (buff.has_value()) {
        memcpy(name_c, &(buff->getBufferStart()[match_offset]),
               (end_offset - match_offset + 1) * sizeof(char));
        name_c[end_offset - match_offset] = '\0';
        StringRef name(name_c);
        if (name.find(" ") != StringRef::npos) {
          space = name.find(" ");
        }
        else {
          space = 1;
        }

        binding_rw.ReplaceText(decl->getLocation(), space, bind.value);
      }
      delete[] name_c;
    }
    std::string new_code = binding_rw.getRewrittenText(action->snippet_range);

    printf("new code!!!! %s\n", new_code.c_str());
    action->edited_code_snippet = new_code;
  }

  void onEndOfTranslationUnit() override {}
};

// Rewriter ReplaceBindingsCallback::binding_rw;

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

template <class T>
class RewriteCallback : public MatchFinder::MatchCallback {
public:
  static Rewriter file_rw;
  ASTContext *context;
  static int num_matched;
  static std::vector<FileID> files_changed;
  MatcherWrapper<T> *matcher;
  static bool verbose;
  static bool rewrite_file;

  std::vector<Binding> bound_code;

  RewriteCallback(MatcherWrapper<T> *matcher) : matcher(matcher) {}

  ~RewriteCallback() {}

  void onStartOfTranslationUnit() override {}

  template <class S>
  void runActions(const MatchFinder::MatchResult &result, const S *match) {
    for (CodeAction *action : matcher->actions) {
      switch (action->kind) {
      case InsertPrematch:
        addBeforeCode(match, result, action);
        break;
      case InsertPostmatch:
        addAfterCode(match, result, action);
        break;
      case Replace:
        replaceCode(match, result, action);
        break;
      default:
        printf("ERROR: unknown action kind for %s\n",
               action->action_name.c_str());
      }
    }
  }

  template <class S>
  void run_helper(const MatchFinder::MatchResult &result, S* match) {
    FullSourceLoc begin = context->getFullLoc(match->getBeginLoc());
    FullSourceLoc end = context->getFullLoc(match->getEndLoc());
    unsigned int begin_line = begin.getSpellingLineNumber();
    unsigned int begin_col = begin.getSpellingColumnNumber();
    unsigned int end_line = end.getSpellingLineNumber();
    unsigned int end_col = end.getSpellingColumnNumber();

    // if (verbose) {
      printf("FOUND match for %s at %d:%d - %d:%d\n",
             matcher->getName().c_str(), begin_line, begin_col, end_line,
             end_col);
    // }
    if (file_rw.isRewritable(match->getBeginLoc()) &&
        file_rw.isRewritable(match->getEndLoc())) {

      runActions(result, match);

      const RewriteBuffer *buff = file_rw.getRewriteBufferFor(
          file_rw.getSourceMgr().getFileID(match->getBeginLoc()));
      if (buff) {
        std::error_code erc;
        std::string newfname =
            file_rw.getSourceMgr().getFilename(match->getBeginLoc()).str();
        if (newfname.rfind(".") != std::string::npos) {
          std::string temp = ".test";
          temp.append(std::to_string(num_matched));
          newfname.insert(newfname.rfind("."), temp);
        } else {
          newfname.append(".test").append(std::to_string(num_matched));
        }

        if (verbose) {
          printf("%s\n", newfname.c_str());
        }
        raw_fd_ostream out(newfname, erc);
        buff->write(out);
        out.close();
        files_changed.push_back(
            file_rw.getSourceMgr().getFileID(match->getBeginLoc()));
        num_matched++;
      }
    }
  }

  void run(const MatchFinder::MatchResult &result) override {

    // printf("HALLO WE RUN\n");
    // printf("FOUND match for %s\n", matcher->getName().c_str());

    context = result.Context;
    file_rw.setSourceMgr(context->getSourceManager(), context->getLangOpts());

    const Stmt *smatch = result.Nodes.getNodeAs<Stmt>("clang_rewrite_top_level_match");
    const Decl *dmatch = result.Nodes.getNodeAs<Decl>("clang_rewrite_top_level_match");
    // const Type *tmatch = result.Nodes.getNodeAs<Type>

    if ((!smatch ||
         !isInOneOfFileIDs(smatch->getBeginLoc(), source_file_entries,
                           context->getSourceManager()))
    && (!dmatch ||
        !isInOneOfFileIDs(dmatch->getBeginLoc(), source_file_entries,
                          context->getSourceManager()))) {
      // if (verbose) {
       // printf("no match or invalid type\n");
      // }
      return;
    }

    // std::map<DynTypedNode, std::vector<std::string>> reverse_Nodes;
    for (std::pair<std::string, DynTypedNode> n : result.Nodes.getMap()) {
      // if not found, add it
    //   auto search = reverse_Nodes.find(n.second);
    //   if (search == reverse_Nodes.end()) {
    //     reverse_Nodes.insert({n.second, {n.first}});
    //   }
    //   else {
    //     search->second.push_back(n.first);
    //   }
    // }
    //
    // for (auto n : reverse_Nodes) {
      // for (auto s : n.second) {
      //   llvm::outs() << s << ",";
      // }
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

    for (CodeAction *action : matcher->actions) {
      replace_bound_code(action, bound_code);
      action->dump_bindings(bound_code);
      printf("FINAL RESULT\n %s\n", action->edited_code_snippet.c_str());
      binding_rw.resetAllRewriteBuffers(binding_rw.getSourceMgr());
      bound_code.clear();
    }


    if (smatch) {
      // run stmt version
      run_helper(result, smatch);
    }
    else if (dmatch) {
      // run decl version
      run_helper(result, dmatch);
    }


  }

  void onEndOfTranslationUnit() override {
    // clear out duplicates
    std::sort(files_changed.begin(), files_changed.end());
    auto new_end = std::unique(files_changed.begin(), files_changed.end());
    files_changed.erase(new_end, files_changed.end());

    for (FileID f : files_changed) {
      const RewriteBuffer *buff = file_rw.getRewriteBufferFor(f);
      std::error_code erc;
      std::string newfname =
          file_rw.getSourceMgr().getFileEntryForID(f)->getName().str();
      if (newfname.rfind(".") != std::string::npos) {
        std::string temp = ".test_final";
        newfname.insert(newfname.rfind("."), temp);
      } else {
        newfname.append(".test_final");
      }

      if (verbose) {
        printf("%s\n", newfname.c_str());
      }
      raw_fd_ostream out(newfname, erc);
      buff->write(out);
      out.close();
    }

    files_changed.clear();
  }

  void replace_bound_code(CodeAction* action, std::vector<Binding> bindings) {
    printf("REPLACE BOUND CODE\n");

    for (Binding b: bindings) {
      MatchFinder finder;
      ReplaceBindingsCallback cb(action, b);
      printf("LOOKING for things named %s or %s\n", b.name.c_str(), b.qual_name.c_str());

      //TODO: if BindingKind is VarName or Type
      if (b.kind == BindingKind::VarNameBinding) {
        if (!b.name.empty() && !b.qual_name.empty()) {
          VariantMatcher declmatcher =
            constructBoundMatcher("namedDecl", "match",
              constructMatcher("anyOf",
                constructMatcher("hasName", StringRef(b.name), 2),
                constructMatcher("hasName", StringRef(b.qual_name), 2),
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

          VariantMatcher refmatcher =
            constructBoundMatcher("declRefExpr", "match",
              constructMatcher("to",
                constructMatcher("namedDecl",
                  constructMatcher("anyOf",
                    constructMatcher("hasName", StringRef(b.name), 4),
                    constructMatcher("hasName", StringRef(b.qual_name), 4),
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

          VariantMatcher declmatcher =
            constructBoundMatcher("namedDecl", "match",
              constructMatcher("hasName",
                StringRef(valid_name),
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

          VariantMatcher refmatcher =
            constructBoundMatcher("declRefExpr", "match",
              constructMatcher("to",
                constructMatcher("namedDecl",
                  constructMatcher("hasName",
                    StringRef(valid_name),
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
          VariantMatcher declmatcher =
            constructBoundMatcher("expr", "match",
              constructMatcher("hasType",
                constructMatcher("anyOf",
                  constructMatcher("asString", StringRef(b.name), 3),
                  constructMatcher("asString", StringRef(b.qual_name), 3),
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

          VariantMatcher declmatcher =
            constructBoundMatcher("expr", "match",
              constructMatcher("hasType",
                constructMatcher("ignoringPointers",
                  constructMatcher("asString", StringRef(valid_name), 3),
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
      // finder.matchAST(*context);
      int retval = Tool->run(newFrontendActionFactory(&finder).get());
      if (retval) {
        printf("OH NOES\n");
      }
    }
  }

private:
  void checkedInsertTextAfterToken(const MatchFinder::MatchResult &result,
                                   SourceLocation loc, CodeAction *act,
                                   bool isBeforeCode = false) {
    std::string text = act->edited_code_snippet;
    if ((isBeforeCode && locValidForCodeInsertBefore(result)) ||
        (!isBeforeCode && locValidForCodeInsertAfter(result))) {
      file_rw.InsertTextAfterToken(loc, text.c_str());
    } else {
      FullSourceLoc full_loc = context->getFullLoc(loc);
      unsigned int line = full_loc.getSpellingLineNumber();
      unsigned int col = full_loc.getSpellingColumnNumber();
      if (verbose) {
        printf("WARNING: location %d:%d not valid for action %s, skipping\n",
               line, col, act->action_name.c_str());
      }
    }
  }

  void checkedInsertTextBefore(const MatchFinder::MatchResult &result,
                               SourceLocation loc, CodeAction *act,
                               bool isBeforeCode = false) {
    std::string text = act->edited_code_snippet;
    if ((isBeforeCode && locValidForCodeInsertBefore(result)) ||
        (!isBeforeCode && locValidForCodeInsertAfter(result))) {
      file_rw.InsertTextBefore(loc, text.c_str());
    } else {
      FullSourceLoc full_loc = context->getFullLoc(loc);
      unsigned int line = full_loc.getSpellingLineNumber();
      unsigned int col = full_loc.getSpellingColumnNumber();
      if (verbose) {
        printf("WARNING: location %d:%d not valid for action %s, skipping\n",
               line, col, act->action_name.c_str());
      }
    }
  }

  void addBeforeCode(const Stmt *match, const MatchFinder::MatchResult &result,
                     CodeAction *act) {

    if (auto *comp = dyn_cast<CompoundStmt>(match)) {
      checkedInsertTextAfterToken(result, comp->getLBracLoc(), act, true);
    } else {
      checkedInsertTextBefore(result, match->getBeginLoc(), act, true);
    }
  }

  void addBeforeCode(const Decl *match, const MatchFinder::MatchResult &result,
                     CodeAction *act) {

    // TODO feex
    // if (auto *comp = dyn_cast<CompoundStmt>(match)) {
    //   checkedInsertTextAfterToken(result, comp->getLBracLoc(), act, true);
    // } else {
      checkedInsertTextBefore(result, match->getBeginLoc(), act, true);
    // }
  }

  void addAfterCode(const Stmt *match, const MatchFinder::MatchResult &result,
                    CodeAction *act) {

    if (isBlock(match)) {
      if (auto *comp = dyn_cast<CompoundStmt>(match)) {
        checkedInsertTextBefore(result, comp->getRBracLoc(), act);
      } else {
        checkedInsertTextAfterToken(result, match->getEndLoc(), act);
      }
    } else if (isLine(match)) {
      // go to end of line
      SourceLocation eol = Lexer::getLocForEndOfToken(
          match->getBeginLoc(), 0, context->getSourceManager(),
          context->getLangOpts());
      Optional<Token> tok = Lexer::findNextToken(
          eol, context->getSourceManager(), context->getLangOpts());
      while (tok.has_value() && tok->isNot(clang::tok::semi)) {
        tok = Lexer::findNextToken(eol, context->getSourceManager(),
                                   context->getLangOpts());
        eol = tok->getLocation();
      }
      // insert call after that
      checkedInsertTextAfterToken(result, eol, act);
    } else {
      if (verbose) {
        printf("WARNING: unhandled location type for action %s, treating as "
               "block\n",
               act->action_name.c_str());
      }
      checkedInsertTextAfterToken(result, match->getEndLoc(), act);
    }
  }

  void addAfterCode(const Decl *match, const MatchFinder::MatchResult &result,
                    CodeAction *act) {

    if (isBlock(match)) {
      // TODO: feex
      // if (auto *comp = dyn_cast<CompoundStmt>(match)) {
      //   checkedInsertTextBefore(result, comp->getRBracLoc(), act);
      // } else {
        checkedInsertTextAfterToken(result, match->getEndLoc(), act);
      // }
    } else if (isLine(match)) {
      // go to end of line
      SourceLocation eol = Lexer::getLocForEndOfToken(
          match->getBeginLoc(), 0, context->getSourceManager(),
          context->getLangOpts());
      Optional<Token> tok = Lexer::findNextToken(
          eol, context->getSourceManager(), context->getLangOpts());
      while (tok.has_value() && tok->isNot(clang::tok::semi)) {
        tok = Lexer::findNextToken(eol, context->getSourceManager(),
                                   context->getLangOpts());
        eol = tok->getLocation();
      }
      // insert call after that
      checkedInsertTextAfterToken(result, eol, act);
    } else {
      if (verbose) {
        printf("WARNING: unhandled location type for action %s, treating as "
               "block\n",
               act->action_name.c_str());
      }
      checkedInsertTextAfterToken(result, match->getEndLoc(), act);
    }
  }

  void replaceCode(const Stmt *match, const MatchFinder::MatchResult &result,
                   CodeAction *act) {
    std::string replacetxt = act->edited_code_snippet;

    // TODO: verify all things for blocks
    Rewriter::RewriteOptions opts;
    opts.IncludeInsertsAtBeginOfRange = false;
    if (isBlock(match)) {
      if (auto *comp = dyn_cast<CompoundStmt>(match)) {
        file_rw.ReplaceText(SourceRange(comp->getLBracLoc(), comp->getRBracLoc()),
                       replacetxt, opts);
      } else {
        // TODO: verify, it can't be this simple
        file_rw.ReplaceText(SourceRange(match->getBeginLoc(), match->getEndLoc()),
                       replacetxt, opts);
      }
    } else if (isLine(match)) {
      file_rw.ReplaceText(CharSourceRange::getTokenRange(match->getBeginLoc(),
                                                    match->getEndLoc()),
                     replacetxt, opts);
    } else {
      if (verbose) {
        printf("WARNING: unhandled location type for action %s, treating as "
               "block\n",
               act->action_name.c_str());
      }
      file_rw.ReplaceText(SourceRange(match->getBeginLoc(), match->getEndLoc()),
                     replacetxt, opts);
    }
  }

  void replaceCode(const Decl *match, const MatchFinder::MatchResult &result,
                   CodeAction *act) {
    std::string replacetxt = act->edited_code_snippet;

    // TODO: verify all things for blocks
    Rewriter::RewriteOptions opts;
    opts.IncludeInsertsAtBeginOfRange = false;
    if (isBlock(match)) {
      // TODO: feex
      // if (auto *comp = dyn_cast<CompoundStmt>(match)) {
      //   file_rw.ReplaceText(SourceRange(comp->getLBracLoc(), comp->getRBracLoc()),
      //                  replacetxt, opts);
      // } else {
        // TODO: verify, it can't be this simple
        file_rw.ReplaceText(SourceRange(match->getBeginLoc(), match->getEndLoc()),
                       replacetxt, opts);
      // }
    } else if (isLine(match)) {
      file_rw.ReplaceText(CharSourceRange::getTokenRange(match->getBeginLoc(),
                                                    match->getEndLoc()),
                     replacetxt, opts);
    } else {
      if (verbose) {
        printf("WARNING: unhandled location type for action %s, treating as "
               "block\n",
               act->action_name.c_str());
      }
      file_rw.ReplaceText(SourceRange(match->getBeginLoc(), match->getEndLoc()),
                     replacetxt, opts);
    }
  }

  template <class S>
  bool locValidForCodeInsertBeforeHelp(const MatchFinder::MatchResult &result, const S* match, const Stmt* root) {
    // check if is inside conditional (for, if, elseif, while, etc)
    SourceRange insert_point(match->getBeginLoc(), match->getEndLoc());

    if (auto *w = dyn_cast<DoStmt>(root)) {
      SourceRange while_cond(w->getCond()->getBeginLoc(),
                             w->getCond()->getEndLoc());

      if (while_cond.fullyContains(insert_point)) {
        return false;
      }
    } else if (auto *f = dyn_cast<ForStmt>(root)) {
      SourceRange for_start(f->getInit()->getBeginLoc(),
                            f->getInc()->getBeginLoc());

      if (for_start.fullyContains(insert_point)) {
        return false;
      }
    } else if (auto *i = dyn_cast<IfStmt>(root)) {
      SourceRange if_cond(i->getCond()->getBeginLoc(),
                          i->getCond()->getEndLoc());

      if (if_cond.fullyContains(insert_point)) {
        return false;
      }
    } else if (auto *s = dyn_cast<SwitchStmt>(root)) {
      SourceRange switch_cond(s->getCond()->getBeginLoc(),
                              s->getCond()->getEndLoc());

      if (switch_cond.fullyContains(insert_point)) {
        return false;
      }
    } else if (auto *w = dyn_cast<WhileStmt>(root)) {
      SourceRange while_cond(w->getCond()->getBeginLoc(),
                             w->getCond()->getEndLoc());

      if (while_cond.fullyContains(insert_point)) {
        return false;
      }
    }

    return true;
  }

  template <class S>
  bool locValidForCodeInsertBeforeHelp(const MatchFinder::MatchResult &result, const S* match, const Decl* root) {
    // check if is inside conditional (for, if, elseif, while, etc)
    SourceRange insert_point(match->getBeginLoc(), match->getEndLoc());

    // TODO: do stuff like this for decls
    // if (auto *w = dyn_cast<DoStmt>(root)) {
    //   SourceRange while_cond(w->getCond()->getBeginLoc(),
    //                          w->getCond()->getEndLoc());
    //
    //   if (while_cond.fullyContains(insert_point)) {
    //     return false;
    //   }

    return true;
  }

  bool locValidForCodeInsertBefore(const MatchFinder::MatchResult &result) {
    const Stmt *smatch = result.Nodes.getNodeAs<Stmt>("clang_rewrite_top_level_match");

    const Decl *dmatch = result.Nodes.getNodeAs<Decl>("clang_rewrite_top_level_match");

    // sometimes the outermost part of the matcher *is* the match so we have no
    // root and need to make one

    if (smatch) {
      return locValidForCodeInsertBeforeHelp(result, smatch, smatch);
    }
    else if (dmatch) {
      return locValidForCodeInsertBeforeHelp(result, dmatch, dmatch);
    }
    else {
      printf("ERROR in locValidForCodeInsertBefore\n");
      return false;
    }
  }

  bool locValidForCodeInsertAfter(const MatchFinder::MatchResult &result) {
    const Stmt *smatch = result.Nodes.getNodeAs<Stmt>("clang_rewrite_top_level_match");
    const Decl *dmatch = result.Nodes.getNodeAs<Decl>("clang_rewrite_top_level_match");
    // check if will obviously be dead code (after return, break, continue)
    // anything more difficult left for future work/integration with unused code
    // pass
    if (smatch) {
      if (isa<BreakStmt>(smatch) || isa<ContinueStmt>(smatch) ||
          isa<CoreturnStmt>(smatch) || isa<GotoStmt>(smatch) ||
          isa<ReturnStmt>(smatch)) {
        return false;
      }
    }
    else if (dmatch) {
      // TODO do this for decls
      // if (isa<BreakStmt>(dmatch) || isa<ContinueStmt>(dmatch) ||
      //     isa<CoreturnStmt>(dmatch) || isa<GotoStmt>(dmatch) ||
      //     isa<ReturnStmt>(dmatch)) {
      //   return false;
      // }
    }
    else {
      printf("ERROR in locValidForCodeInsertAfter\n");
      return false;
    }
    // check if is inside conditional (for, if, elseif, while, etc)
    return locValidForCodeInsertBefore(result);
  }

  bool locValidForCodeInsert(const MatchFinder::MatchResult &result) {
    return locValidForCodeInsertBefore(result) &&
           locValidForCodeInsertAfter(result);
  }
};

template <class T> Rewriter RewriteCallback<T>::file_rw;
template <class T> std::vector<FileID> RewriteCallback<T>::files_changed;
template <class T> int RewriteCallback<T>::num_matched = 0;
template <class T> bool RewriteCallback<T>::verbose = false;
template <class T> bool RewriteCallback<T>::rewrite_file = true;

}
}// namespaces

#endif //CLANG_REWRITE_CALLBACK_H
