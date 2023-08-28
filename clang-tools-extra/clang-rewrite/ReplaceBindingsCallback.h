#ifndef REPLACE_BINDINGS_CALLBACK_H
#define REPLACE_BINDINGS_CALLBACK_H

#include "clang/Frontend/FrontendActions.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"

#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/Lex/Lexer.h"
#include "clang/Lex/Token.h"
#include "clang/Rewrite/Core/RewriteBuffer.h"
#include "clang/Rewrite/Core/Rewriter.h"

#include "CodeAction.h"
#include "RewriteCallback.h"
#include "ClangRewriteUtils.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <filesystem>

using namespace clang;
using namespace clang::ast_matchers;

using namespace clang::tooling;
using namespace llvm;

namespace clang {
namespace rewrite_tool {

extern Rewriter binding_rw;
extern std::vector<Binding> create_bindings(const MatchFinder::MatchResult& result, ASTContext* context);

template <typename T>
const T* findFirstChild(const Stmt* stmt) {
  for (auto i = stmt->child_begin(); i != stmt->child_end(); i++) {
    if (const T* node = dyn_cast<T>(*i)) {
      // printf("FOUND IT\n");
      return node;
    }
    return findFirstChild<T>(*i);
  }
  return nullptr;
}



class ReplaceBindingsCallback : public MatchFinder::MatchCallback {
public:
  ASTContext* context;
  CodeAction* action;
  Binding bind;
  std::vector<Binding> all_bindings;
  std::vector<Binding>* current_bindings;
  FileID fid;
  static std::vector<Location> past_matches;
  std::vector<Binding> inner_bindings;
  static int line_delta;
  static int col_delta;

  ReplaceBindingsCallback(CodeAction* action, Binding b, std::vector<Binding>& all_bindings, std::vector<Binding>* current_bindings)
    : action(action), bind(b), all_bindings(all_bindings), current_bindings(current_bindings) {}

  void onStartOfTranslationUnit() override {}

  void run(const MatchFinder::MatchResult &result) override {
    printf("running ReplaceBindingsCallback\n");

    context = result.Context;
    binding_rw.setSourceMgr(context->getSourceManager(), context->getLangOpts());

    const Expr* exp = result.Nodes.getNodeAs<Expr>("clang_rewrite_match");
    const NamedDecl* decl = result.Nodes.getNodeAs<NamedDecl>("clang_rewrite_match");
    const DeclStmt* stmt = result.Nodes.getNodeAs<DeclStmt>("clang_rewrite_match");

    // TODO: can I condense the two names into one?
    if (!exp && !decl && !stmt) {
      exp = result.Nodes.getNodeAs<Expr>("clang_rewrite_top_level_match");
      decl = result.Nodes.getNodeAs<NamedDecl>("clang_rewrite_top_level_match");
      stmt = result.Nodes.getNodeAs<DeclStmt>("clang_rewrite_top_level_match");
    }

    bool expr_valid = true;
    bool decl_valid = true;
    bool stmt_valid = true;

    if (!exp ||
        !context->getSourceManager().getFilename(exp->getBeginLoc()).endswith("clang_rewrite_temp_source.cpp." + std::to_string(num_bind_files) + ".bind.cpp"))
         {
      if (exp) printf("filename??? %s\n", context->getSourceManager().getFilename(exp->getBeginLoc()).str().c_str());
      printf("ERROR: invalid expr binding match loc\n");
      expr_valid = false;
    }

    if (!decl ||
        !context->getSourceManager().getFilename(decl->getBeginLoc()).endswith("clang_rewrite_temp_source.cpp." + std::to_string(num_bind_files) + ".bind.cpp")) {
      if (decl) printf("filename??? %s\n", context->getSourceManager().getFilename(decl->getBeginLoc()).str().c_str());
      printf("ERROR: invalid decl binding match loc\n");
      decl_valid = false;
    }

    if (!stmt ||
        !context->getSourceManager().getFilename(stmt->getBeginLoc()).endswith("clang_rewrite_temp_source.cpp." + std::to_string(num_bind_files) + ".bind.cpp")) {
      if (stmt) printf("filename??? %s\n", context->getSourceManager().getFilename(stmt->getBeginLoc()).str().c_str());
      printf("ERROR: invalid stmt binding match loc\n");
      stmt_valid = false;
    }

    if (!expr_valid && !decl_valid && !stmt_valid) {
      printf("ERROR: no valid binding match loc\n");
      return;
    }

    SourceRange match_range;
    if (expr_valid) {
      // printf("expr valid\n");
      // printf("file name %s\n", context->getSourceManager().getFilename(expr->getBeginLoc()).str().c_str());
      match_range = SourceRange(exp->getBeginLoc(), exp->getEndLoc());
    }
    else if (decl_valid) {
      // printf("decl valid\n");
      // printf("file name %s\n", context->getSourceManager().getFilename(decl->getBeginLoc()).str().c_str());
      match_range = SourceRange(decl->getBeginLoc(), decl->getEndLoc());
    }
    else if (stmt_valid) {
      match_range = SourceRange(stmt->getBeginLoc(), stmt->getEndLoc());
    }

    FullSourceLoc begin;
    FullSourceLoc end;
    FullSourceLoc match;

    if (expr_valid) {
      begin = context->getFullLoc(exp->getBeginLoc());
      end = context->getFullLoc(exp->getEndLoc());
      match = context->getFullLoc(exp->getBeginLoc());
    }
    else if (decl_valid) {
      begin = context->getFullLoc(decl->getBeginLoc());
      end = context->getFullLoc(decl->getEndLoc());
      match = context->getFullLoc(decl->getLocation());
    }
    else if (stmt_valid) {
      begin = context->getFullLoc(stmt->getBeginLoc());
      end = context->getFullLoc(stmt->getEndLoc());
      match = context->getFullLoc(stmt->getBeginLoc());
    }

    //dump
    unsigned int begin_line = begin.getSpellingLineNumber();
    unsigned int begin_col = begin.getSpellingColumnNumber();
    unsigned int end_line = end.getSpellingLineNumber();
    unsigned int end_col = end.getSpellingColumnNumber();
    printf("FOUND match for binding at %d:%d - %d:%d\n",
           begin_line, begin_col, end_line, end_col);

    if (bind.has_valid_range) {
      if (!locIsInRangeHard(bind.valid_over, begin_line, begin_col, end_line, end_col)) {
        printf("match not in binding's valid range (%d:%d - %d:%d)\n",
          bind.valid_over.begin_line, bind.valid_over.begin_col,
          bind.valid_over.end_line, bind.valid_over.end_col);
        return;
      }
    }

    fid = begin.getFileID();
    unsigned int begin_offset = begin.getFileOffset();
    unsigned int end_offset = end.getFileOffset();
    unsigned int match_offset = match.getFileOffset();

    if (begin_offset == end_offset) {
      printf("one char match, luls\n");
      end_offset += 1;
    }

    if (std::find(past_matches.begin(), past_matches.end(),
        (Location){begin_line, begin_col, end_line, end_col}) != past_matches.end()) {
      printf("duplicate match\n");
      for (Location l : past_matches) {
        printf("\t{%d:%d-%d:%d}\n", l.begin_line, l.begin_col, l.end_line, l.end_col);
      }
      return;
    }
    else {
      past_matches.push_back({begin_line, begin_col, end_line, end_col});
    }

    std::optional<llvm::MemoryBufferRef> buff =
      context->getSourceManager().getBufferOrNone(fid);

    if (expr_valid) {
      printf("expr\n");
      exp->dump();
      if (bind.name == "clang_rewrite::loop_body" ||
          bind.qual_name == "clang_rewrite::loop_body") {
        // go match loop_body in file - might need to rewrite file in between
        // pull matcher/replacer pair
        // run MatcherGenCallback to put matcher into internal_matchers
        StatementMatcher inits_matcher = callExpr(allOf(
          callee(functionDecl(hasName("clang_rewrite::loop_body"))),
          hasArgument(0, cxxBindTemporaryExpr(hasSubExpr(
            cxxConstructExpr(hasArgument(0,
              cxxStdInitializerListExpr(hasSubExpr(materializeTemporaryExpr(hasSubExpr(
                initListExpr(forEachDescendant(
                  cxxConstructExpr(hasArgument(0, expr(anything()).bind("body")))
                ))
              ))))
            ))
          )))
        )).bind("matcher");

        StatementMatcher inits_matcher2 = callExpr(allOf(
          callee(unresolvedLookupExpr(hasAnyDeclaration(namedDecl(hasName("clang_rewrite::loop_body"))))),
          hasArgument(0, initListExpr(forEachDescendant(
            initListExpr(hasInit(0, expr().bind("body")))
          )))
        )).bind("matcher");

        // TODO: only find matches within range?
        MatchFinder inits_finder;
        MatcherGenCallback mgcb(/*is_internal_matcher=*/true, all_bindings);

        inits_finder.addMatcher(inits_matcher, &mgcb);
        inits_finder.addMatcher(inits_matcher2, &mgcb);

        printf("ABOUT TO RUN THE THING\n");
        ClangTool process_temp(Tool->getCompilationDatabase(), {"clang_rewrite_temp_source.cpp.bind_final.cpp"});
        process_temp.run(newFrontendActionFactory(&inits_finder).get());
        // rewrite file with b.value wrapped in internal matcher_block attr
        // to do that we need the callexpr
        DynTypedNodeList Parents = context->getParents(*exp);
        llvm::SmallVector<DynTypedNode, 8> Stack(Parents.begin(), Parents.end());
        const CallExpr* call; // DO NOT try to get the location of this
        std::vector<std::pair<std::string, std::string>> match_and_replace_text;
        while (!Stack.empty()) {
          const auto &CurNode = Stack.back();
          Stack.pop_back();
          if (const CompoundStmt* comp = CurNode.get<CompoundStmt>()) {
            begin = context->getFullLoc(comp->getLBracLoc());
            end = context->getFullLoc(comp->getRBracLoc());
            match = begin;
            break;
          }
          else if (const CallExpr* callexpr = CurNode.get<CallExpr>()) {
            const Expr* callee = callexpr->getCallee();
            // i don't like doing this either but it's the best i got
            bool lookup_is_loopbody = false;
            if (const UnresolvedLookupExpr* lookup = dyn_cast<UnresolvedLookupExpr>(callee)) {
              const Decl* d = *(lookup->decls().begin());
              if (const NamedDecl* decl = dyn_cast<NamedDecl>(d)) {
                if (decl->getQualifiedNameAsString() == "clang_rewrite::loop_body") {
                  lookup_is_loopbody = true;
                }
              }
            }
            if ((callexpr->getDirectCallee() && callexpr->getDirectCallee()->getQualifiedNameAsString() ==
                "clang_rewrite::loop_body") ||
                lookup_is_loopbody) {
              call = callexpr;
              if (callexpr->getNumArgs() > 0) {
                printf("callexpr num args %d\n", callexpr->getNumArgs());
                const Expr* arg = callexpr->getArg(0);
                const InitListExpr* initlist = findFirstChild<InitListExpr>(arg);

                for (int i = 0; i < initlist->getNumInits(); i++) {
                  const Expr* matcher = cast<CXXConstructExpr>(initlist->getInit(i))->getArg(0);
                  const Expr* replacer = cast<CXXConstructExpr>(initlist->getInit(i))->getArg(1);

                  FullSourceLoc m_begin = context->getFullLoc(matcher->getBeginLoc());
                  FullSourceLoc m_end = context->getFullLoc(matcher->getEndLoc());

                  FullSourceLoc r_begin = context->getFullLoc(replacer->getBeginLoc());
                  FullSourceLoc r_end = context->getFullLoc(replacer->getEndLoc());

                  std::string matcher_text = binding_rw.getRewrittenText(SourceRange(m_begin,
                    Lexer::getLocForEndOfToken(m_end, 0, context->getSourceManager(), context->getLangOpts())));
                  std::string replacer_text = binding_rw.getRewrittenText(SourceRange(r_begin,
                    Lexer::getLocForEndOfToken(r_end, 0, context->getSourceManager(), context->getLangOpts())));

                  matcher_text = matcher_text.substr(0, matcher_text.size()-1);
                  replacer_text = replacer_text.substr(0, replacer_text.size()-1);
                  printf("matcher text? %s\n", matcher_text.c_str());
                  printf("replacer text? %s\n", replacer_text.c_str());
                  match_and_replace_text.push_back({matcher_text, replacer_text});
                }

              }
            }
            llvm::append_range(Stack, context->getParents(CurNode));
          }
          else {
            llvm::append_range(Stack, context->getParents(CurNode));
          }
        }

        begin_line = begin.getSpellingLineNumber();
        begin_col = begin.getSpellingColumnNumber();
        end_line = end.getSpellingLineNumber();
        end_col = end.getSpellingColumnNumber();
        printf("TRUE match for binding at %d:%d - %d:%d\n",
               begin_line, begin_col, end_line, end_col);

        begin_offset = begin.getFileOffset();
        end_offset = end.getFileOffset();

        size_t space = end_offset - begin_offset + 1;
        printf("space %lu\n", space);

        binding_rw.ReplaceText(begin, space, bind.value);
        // binding_rw.overwriteChangedFiles();

        int num_lines = std::count(bind.value.begin(), bind.value.end(), '\n');
        printf("num lines = %d\n", num_lines);

        int num_cols = bind.value.size() - bind.value.rfind("\n") + 1;
        printf("num cols = %d\n", num_cols);
        // run some kind of generic finder callback to generate bindings from
        // match itself

        update_bindings(begin_line, begin_col, end_line, end_col, num_cols);

        std::vector<Binding> internal_bindings = create_bindings(result, context);
        printf("internal bindings:\n");
        for (Binding b : internal_bindings) {
          b.has_valid_range = true;
          if (num_lines == 0) {
            b.valid_over = {begin_line+line_delta, begin_col, begin_line+num_lines+line_delta, begin_col+num_cols};
          }
          else {
            b.valid_over = {begin_line+line_delta, begin_col, begin_line+num_lines+line_delta, num_cols};
          }
          dump_binding(b);
        }
        inner_bindings.insert(inner_bindings.begin(), internal_bindings.begin(), internal_bindings.end());
        // generate bindings from matchers we made with mgcb
        // TODO: assumes order of things in internal_matchers is same as in
        // match_and_replace_text; fix or verify always true
        printf("num internal matchers %d\n", internal_matchers.size());
        for (int i = 0; i < internal_matchers.size(); i++) {
          if (locIsInRangeHard(begin_line, begin_col, end_line, end_col,
                internal_matchers[i]->getLine(), internal_matchers[i]->getCol())) {
            Binding b;
            b.matchers = {VariantMatcher::SingleMatcher(internal_matchers[i]->getMatcher())};
            b.name = match_and_replace_text[i].first;
            b.qual_name = match_and_replace_text[i].first;
            b.value = match_and_replace_text[i].second;
            b.kind = BindingKind::VarNameBinding;
            b.has_valid_range = true;
            if (num_lines == 0) {
              b.valid_over = {begin_line+line_delta, begin_col, begin_line+num_lines+line_delta, begin_col+num_cols};
            }
            else {
              b.valid_over = {begin_line+line_delta, begin_col, begin_line+num_lines+line_delta, num_cols};
            }
            inner_bindings.push_back(b);
          }
        }
        printf("inner bindings\n");
        for (Binding b : inner_bindings) {
          dump_binding(b);
        }
        // dump bindings into inner_bindings, hand back to RewriteCallback

        // TODO: this is a hack, do it better
        line_delta += num_lines - (end_line-begin_line);
      }
      else {
        if (isa<DeclRefExpr>(exp)) {

          if (buff.has_value()) {
            size_t space;
            space = Lexer::MeasureTokenLength(exp->getBeginLoc(),
              context->getSourceManager(), context->getLangOpts());
            printf("oh noes %lu\n", space);

            char* name_c = new char[space + 1];

            memcpy(name_c, &(buff->getBufferStart()[match_offset]),
                   (space + 1) * sizeof(char));
            name_c[space] = '\0';
            StringRef name(name_c);

            if (name != StringRef(bind.name) && name != StringRef(bind.qual_name)) {
              printf("%s\n", name_c);
              printf("OH HENLO\n");
              delete[] name_c;
              return;
            }

            exp->getExprLoc().dump(context->getSourceManager());
            binding_rw.ReplaceText(exp->getExprLoc(), space, bind.value);

            int num_cols = bind.value.size() - bind.value.rfind("\n") + 1;
            update_bindings(begin_line, begin_col, end_line, end_col, num_cols);

            delete[] name_c;
          }
        }
        else {
          // get true range
          // we can trust begin and begin_line/_col
          FullSourceLoc true_end = context->getFullLoc(
            Lexer::getLocForEndOfToken(end, 1, context->getSourceManager(), context->getLangOpts()));

          begin_line = begin.getSpellingLineNumber();
          begin_col = begin.getSpellingColumnNumber();
          end_line = true_end.getSpellingLineNumber();
          end_col = true_end.getSpellingColumnNumber();
          printf("TRUE match for binding at %d:%d - %d:%d\n",
                 begin_line, begin_col, end_line, end_col);

          begin_offset = begin.getFileOffset();
          end_offset = true_end.getFileOffset();

          size_t space = end_offset - begin_offset + 1;
          printf("space %lu\n", space);

          // replace true range
          binding_rw.ReplaceText(begin, space, bind.value);

          int num_lines = std::count(bind.value.begin(), bind.value.end(), '\n');
          printf("num lines = %d\n", num_lines);

          int num_cols = bind.value.size() - bind.value.rfind("\n") + 1;
          printf("num cols = %d\n", num_cols);

          update_bindings(begin_line, begin_col, end_line, end_col, num_cols);

          // create bindings from result
          std::vector<Binding> internal_bindings = create_bindings(result, context);
          printf("internal bindings:\n");
          for (Binding& b : internal_bindings) {
            b.has_valid_range = true;
            if (num_lines == 0) {
              b.valid_over = {begin_line+line_delta, begin_col, begin_line+num_lines+line_delta, begin_col+num_cols};
            }
            else {
              b.valid_over = {begin_line+line_delta, begin_col, begin_line+num_lines+line_delta, num_cols};
            }

            dump_binding(b);
          }
          inner_bindings.insert(inner_bindings.begin(), internal_bindings.begin(), internal_bindings.end());
          // hand bindings back to RewriteCallback

          // TODO: this is a hack, do it better
          line_delta += num_lines - (end_line-begin_line);
        }
      }
    }
    else if (decl_valid) {
      printf("decl\n");
      decl->dump();

      if (bind.kind == VarNameBinding) {
        char* name_c = new char[end_offset - match_offset + 1];
        size_t space;
        if (buff.has_value()) {
          // memcpy(name_c, &(buff->getBufferStart()[match_offset]),
          //        (end_offset - match_offset + 1) * sizeof(char));
          // name_c[end_offset - match_offset] = '\0';
          // StringRef name(name_c);
          // if (name.find(" ") != StringRef::npos) {
          //   space = name.find(" ");
          // }
          // else {
          //   space = 1;
          // }

          space = Lexer::MeasureTokenLength(decl->getLocation(),
            context->getSourceManager(), context->getLangOpts());
          printf("oh noes decl %lu\n", space);

          binding_rw.ReplaceText(decl->getLocation(), space, bind.value);

          int num_cols = bind.value.size() - bind.value.rfind("\n") + 1;
          update_bindings(begin_line, begin_col, end_line, end_col, num_cols);
        }
        delete[] name_c;
      }
      else if (bind.kind == TypeBinding) {
        auto tok = Lexer::findNextToken(decl->getBeginLoc(), context->getSourceManager(), context->getLangOpts());
        SourceLocation loc = decl->getBeginLoc();
        loc.dump(context->getSourceManager());
        Lexer::getLocForEndOfToken(loc, 1, context->getSourceManager(), context->getLangOpts()).dump(context->getSourceManager());
        SourceRange rng(loc, Lexer::getLocForEndOfToken(loc, 1, context->getSourceManager(), context->getLangOpts()));
        printf("TOKEN?? %s\n", Lexer::getSourceText(Lexer::getAsCharRange(rng, context->getSourceManager(), context->getLangOpts()),
            context->getSourceManager(), context->getLangOpts()).str().c_str());

        int i = 0;
        while (tok && bind.name != Lexer::getSourceText(Lexer::getAsCharRange(rng, context->getSourceManager(), context->getLangOpts()),
            context->getSourceManager(), context->getLangOpts()) && i < 20) {
          printf("TOKEN?? %s\n", Lexer::getSourceText(Lexer::getAsCharRange(rng, context->getSourceManager(), context->getLangOpts()),
              context->getSourceManager(), context->getLangOpts()).str().c_str());
          loc = Lexer::getLocForEndOfToken(loc, 0, context->getSourceManager(), context->getLangOpts());
          rng = SourceRange(loc, Lexer::getLocForEndOfToken(loc, 1, context->getSourceManager(), context->getLangOpts()));
          tok = Lexer::findNextToken(loc, context->getSourceManager(), context->getLangOpts());
          i++;
        }

        size_t space = Lexer::MeasureTokenLength(loc, context->getSourceManager(), context->getLangOpts());
        printf("oh noes template %lu\n", space);

        binding_rw.ReplaceText(loc, space, bind.value);

        int num_cols = bind.value.size() - bind.value.rfind("\n") + 1;
        update_bindings(begin_line, begin_col, end_line, end_col, num_cols);
      }


    }
    internal_matchers.clear();
  }

  void onEndOfTranslationUnit() override {
    // binding_rw.overwriteChangedFiles();

    // std::ofstream temp_file(temp_file_name + ".bind_final.cpp");
    //
    // SourceLocation file_begin = context->getSourceManager().getLocForStartOfFile(fid);
    // SourceLocation file_end = context->getSourceManager().getLocForEndOfFile(fid);

    // Rewriter::buffer_iterator buff_iter = binding_rw.buffer_begin();
    const RewriteBuffer* buff = binding_rw.getRewriteBufferFor(fid);
    // binding_rw.overwriteChangedFiles();
    std::error_code erc;
    // temp_file << binding_rw.getRewrittenText(SourceRange(file_begin, file_end));
    if (buff) {
      raw_fd_ostream out(temp_file_name + ".bind_final.cpp", erc);
      buff->write(out);
      out.close();
    }
    // else {
    //   std::filesystem::copy(temp_file_name + "." + std::to_string(num_bind_files) + ".bind.cpp",
    //                         temp_file_name + ".bind_final.cpp",
    //                         std::filesystem::copy_options::overwrite_existing);
    // }

    if (buff) {
      num_bind_files++;
      raw_fd_ostream out_numbered(temp_file_name + "." + std::to_string(num_bind_files) + ".bind.cpp", erc);
      buff->write(out_numbered);
      out_numbered.close();
    }

    // temp_file.close();
    binding_rw.clearAllRewriteBuffers(binding_rw.getSourceMgr());
    line_delta = 0;
    past_matches.clear();
    internal_matchers.clear();
  }

  template<typename T>
  bool isInSetup(T* node) {
    DynTypedNodeList Parents = context->getParents(*node);
    llvm::SmallVector<DynTypedNode, 8> Stack(Parents.begin(), Parents.end());
    while (!Stack.empty()) {
      const auto &CurNode = Stack.back();
      Stack.pop_back();
      if (const NamedDecl* decl = CurNode.get<NamedDecl>()) {
        if (decl->hasAttrs()) {
          for (Attr* a : decl->attrs()) {
            if (a->getKind() == attr::RewriteSetup) {
              return true;
            }
          }
        }
      }
      llvm::append_range(Stack, context->getParents(CurNode));
    }

    if (const DeclStmt* decl = dyn_cast<DeclStmt>(node)) {
      for (auto d : decl->decls()) {
        if (d->hasAttrs()) {
          for (Attr* a : d->attrs()) {
            if (a->getKind() == attr::RewriteSetup) {
              return true;
            }
          }
        }
      }
    }
    return false;
  }

  // same as checking whether it starts in the range 0:0 - start of valid_over
  bool startsBefore(int begin_line, int begin_col, Binding b) {
    return locIsInRangeHard(0, 0, b.valid_over.begin_line, b.valid_over.begin_col,
      begin_line, begin_col);
  }

  bool startsInside(int begin_line, int begin_col, Binding b) {
    return locIsInRangeHard(b.valid_over.begin_line, b.valid_over.begin_col,
      b.valid_over.end_line, b.valid_over.end_col, begin_line, begin_col);
  }

  void update_bindings(int begin_line, int begin_col, int end_line, int end_col, int last_line_cols) {
    for (Binding& b : *current_bindings) {
      if (startsBefore(begin_line, begin_col, b)) {
        // move the whole dang thing
        // update valid_over begin_line and begin_col
        b.valid_over.begin_line += end_line - begin_line;
        if (begin_line == end_line) {
          b.valid_over.begin_col += last_line_cols;
        }
        // update valid_over end_line and end_col
        b.valid_over.end_line += end_line - begin_line;
        if (begin_line == end_line) {
          b.valid_over.end_col += last_line_cols;
        }
      }
      else if (startsInside(begin_line, begin_col, b)) {
        // move the end
        // update valid_over end_line and end_col
        b.valid_over.end_line += end_line - begin_line;
        if (begin_line == end_line) {
          b.valid_over.end_col += last_line_cols;
        }
      }
      printf("UPDATING???\n");
      dump_binding(b);
    }
  }



};

std::vector<Location> ReplaceBindingsCallback::past_matches;
int ReplaceBindingsCallback::line_delta = 0;

}
} // namespaces
#endif // REPLACE_BINDINGS_CALLBACK_H
