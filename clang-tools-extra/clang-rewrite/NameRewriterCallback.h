#ifndef CLANG_NAME_REWRITER_CALLBACK_H
#define CLANG_NAME_REWRITER_CALLBACK_H

#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/Lex/Lexer.h"
#include "clang/Lex/Token.h"

#include "FindLiteralsCallback.h"

#include <string>
#include <vector>
#include <filesystem>

using namespace clang;
using namespace clang::ast_matchers;
using namespace clang::tooling;
using namespace llvm;

namespace clang {
namespace rewrite_tool {

Rewriter name_rewriter;

class NameRewriterVisitor : public RecursiveASTVisitor<NameRewriterVisitor> {
public:
  explicit NameRewriterVisitor(ASTContext* context, std::vector<std::string> literals) :
    context(context), literals(literals) {}

  bool is_literal(NamedDecl* decl) {
    // printf("BUT IS IT LITERAL\n");
    DeclContext* con = decl->getDeclContext();
    if (auto ns = dyn_cast<NamespaceDecl>(con)) {
      // printf("NAMESPACE\n");
      // ns->dump();
      if (ns->getNameAsString() == "clang_rewrite_literals" || ns->getNameAsString() == "clang_rewrite") {
        // printf("%s is in literal ns\n", ns->getNameAsString().c_str());
        return true;
      }
    }
    if (std::find(literals.begin(), literals.end(), decl->getNameAsString()) != literals.end() ||
        std::find(literals.begin(), literals.end(), decl->getQualifiedNameAsString()) != literals.end()) {
      // printf("%s is in list of literals\n", decl->getNameAsString().c_str());
      return true;
    }
    return false;
  }

  // TODO: placeholder until we actually figure out literals
  bool is_literal(DeclRefExpr* ref) {
    return is_literal(ref->getDecl());
  }

  bool VisitNamedDecl(NamedDecl* decl) {

    bool is_matcher_replacer = false;
    if (FunctionDecl* func = dyn_cast<FunctionDecl>(decl)) {
      if (decl->hasAttrs()) {
        for (Attr* a : decl->attrs()) {
          if (a->getKind() == attr::Matcher ||
              a->getKind() == attr::ReplaceCode ||
              a->getKind() == attr::InsertCodeBefore ||
              a->getKind() == attr::InsertCodeAfter) {
            is_matcher_replacer = true;
          }
        }
      }
    }
    if (!is_matcher_replacer && !is_literal(decl) &&
        std::find(valid_decls.begin(), valid_decls.end(), decl) == valid_decls.end()) {
      SourceLocation begin = decl->getLocation();
      printf("found decl named %s\n", decl->getNameAsString().c_str());

      size_t length = Lexer::MeasureTokenLength(begin, context->getSourceManager(), context->getLangOpts());

      name_rewriter.ReplaceText(begin, length, "clang_rewrite_" + decl->getNameAsString());
      valid_decls.push_back(decl);
    }
    return true;
  }

  bool VisitDeclStmt(DeclStmt* stmt) {

    return true;
  }

  bool VisitDeclRefExpr(DeclRefExpr* expr) {
    if (!is_literal(expr) &&
        std::find(valid_decls.begin(), valid_decls.end(), expr->getDecl()->getUnderlyingDecl()) != valid_decls.end()) {
      ValueDecl* decl = expr->getDecl();
      SourceLocation begin = expr->getLocation();
      printf("found declrefexpr named %s\n", decl->getNameAsString().c_str());

      size_t length = Lexer::MeasureTokenLength(begin, context->getSourceManager(), context->getLangOpts());

      name_rewriter.ReplaceText(begin, length, "clang_rewrite_" + decl->getNameAsString());
    }
    return true;
  }

  bool VisitCapturedStmt(CapturedStmt* stmt) {
    TraverseDecl(stmt->getCapturedDecl());

    return false;
  }

  bool VisitRecoveryExpr(RecoveryExpr* expr) {
    printf("recovery expr\n");
    // for (Expr* e : expr->subExpressions()) {
    //   e->dump();
    //   // TraverseStmt(e);
    // }

    FullSourceLoc begin = context->getFullLoc(expr->getBeginLoc());
    FullSourceLoc end = context->getFullLoc(expr->getEndLoc());

    size_t length = Lexer::MeasureTokenLength(begin, context->getSourceManager(), context->getLangOpts());

    FileID fid = begin.getFileID();
    unsigned int begin_offset = begin.getFileOffset();
    unsigned int end_offset = end.getFileOffset();

    printf("begin offset %u\n", begin_offset);
    printf("end offset   %u\n", end_offset);
    printf("array length %u\n", length);

    std::optional<llvm::MemoryBufferRef> buff =
        context->getSourceManager().getBufferOrNone(fid);

    char *code_c = new char[length + 1];
    if (buff.has_value()) {
      memcpy(code_c, &(buff->getBufferStart()[begin_offset]),
             (length + 1) * sizeof(char));
      code_c[length] =
          '\0'; // force null terminated for Reasons
      printf("body code??? %s\n", code_c);
    } else {
      printf("no buffer :<\n");
    }

    for (NamedDecl* d : valid_decls) {
      if (d->getNameAsString() == std::string(code_c)) {
        printf("recovery expr %s\n", code_c);
        name_rewriter.ReplaceText(begin, length, "clang_rewrite_" + d->getNameAsString());
      }
    }

    delete[] code_c;
    return true;
  }

private:
  ASTContext* context;
  std::vector<std::string> literals;
  std::vector<NamedDecl*> valid_decls;
};

class NameRewriterCallback : public MatchFinder::MatchCallback {
public:
  ASTContext* context;
  FileID fid;
  std::string og_inst_file;

  NameRewriterCallback(std::string inst_file) : og_inst_file(inst_file) {}

  void run(const MatchFinder::MatchResult& result) override {
    printf("running NameRewriterCallback\n");
    context = result.Context;

    const Decl* matcher = result.Nodes.getNodeAs<Decl>("matcher");
    const Decl* insert_before = result.Nodes.getNodeAs<Decl>("insert_before_match");
    const Decl* insert_after = result.Nodes.getNodeAs<Decl>("insert_after_match");
    const Decl* replace = result.Nodes.getNodeAs<Decl>("replace");

    const Decl* valid_decl;

    if (matcher && context->getSourceManager().isWrittenInMainFile(matcher->getBeginLoc())) {
      valid_decl = matcher;
    }
    else if (insert_before && context->getSourceManager().isWrittenInMainFile(insert_before->getBeginLoc())) {
      valid_decl = insert_before;
    }
    else if (insert_after && context->getSourceManager().isWrittenInMainFile(insert_after->getBeginLoc())) {
      valid_decl = insert_after;
    }
    else if (replace && context->getSourceManager().isWrittenInMainFile(replace->getBeginLoc())) {
      valid_decl = replace;
    }
    else {
      valid_decl = nullptr;
    }

    if (!valid_decl) {
      printf("ERROR: no valid declaration for name rewriting\n");
      return;
    }

    name_rewriter.setSourceMgr(context->getSourceManager(), context->getLangOpts());
    NameRewriterVisitor visitor(context, clang_rewrite_literals);

    visitor.TraverseDecl(const_cast<Decl*>(valid_decl));

    fid = context->getFullLoc(valid_decl->getBeginLoc()).getFileID();
  }

  void onEndOfTranslationUnit() override {
    const RewriteBuffer* buff = name_rewriter.getRewriteBufferFor(fid);
    std::error_code erc;

    if (buff) {
      raw_fd_ostream out(temp_file_name + ".rewritten_spec.cpp", erc);
      buff->write(out);
      out.close();
    }
    else {
      std::filesystem::copy(og_inst_file, temp_file_name + ".rewritten_spec.cpp",
          std::filesystem::copy_options::overwrite_existing);
    }

    name_rewriter.clearAllRewriteBuffers(name_rewriter.getSourceMgr());
  }
};

}
} // namespaces

#endif // CLANG_NAME_REWRITER_CALLBACK_H
