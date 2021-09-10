#ifndef CLANG_MATCHER_GEN_CALLBACK_H
#define CLANG_MATCHER_GEN_CALLBACK_H

#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchersInternal.h"
#include "clang/ASTMatchers/Dynamic/VariantValue.h"
#include "clang/ASTMatchers/Dynamic/Registry.h"
#include "clang/Lex/Lexer.h"
#include "clang/Lex/Token.h"

#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/AST/Type.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/Tooling.h"

#include "CodeAction.h"

#include <string>
#include <vector>
#include <unordered_map>

using namespace clang;
using namespace clang::ast_matchers;
using namespace clang::ast_matchers::dynamic;

using namespace clang::tooling;

using ast_matchers::internal::Matcher;


enum class MatcherType {
  compoundStmt,
  returnStmt,
  hasReturnValue,
  declRefExpr,
};

using MT = MatcherType;
using R = clang::ast_matchers::dynamic::Registry;


class Node {
public:
  MatcherType matcher_type;
  std::string matcher_string; // for debug/dumping purposes
  bool bound;
  std::string bound_name;
  bool has_type;
  std::string type;
  bool ignore_casts;
  std::vector<Node*> children;

  Node(MatcherType m, std::string ms) : matcher_type(m), matcher_string(ms) {}

  void add_child(Node* parent, Node* child) {
    if (parent == nullptr) {
      parent = child;
    }
    else {
      parent->children.push_back(child);
    }
  }

  void dump_help(Node* n, int tab_depth) {
    for (int i = 0; i < tab_depth; i++) {
      printf("  ");
    }
    printf("%s\n", n->matcher_string.c_str());
    for (Node* child : n->children) {
      dump_help(child, tab_depth+1);
    }
  }

  void dump() {
    dump_help(this, 0);
  }

  void clean_tree() {
    for (Node* child : this->children) {
      child->clean_tree();
    }
    delete this;
  }
};

StatementMatcher rettest =
  returnStmt(
    hasReturnValue(
      ignoringParenImpCasts(
        declRefExpr(
          allOf(
            hasType(asString("int")),
            expr().bind("x")
          )
        )
      )
    )
  );

class BuildMatcherVisitor : public RecursiveASTVisitor<BuildMatcherVisitor> {
public:
  explicit BuildMatcherVisitor(ASTContext* context)
    : context(context) {}

    Node* get_matcher() {
      return root;
    }

    bool VisitCompoundStmt(CompoundStmt* comp) {
      update_matcher(MT::compoundStmt, "compountStmt()");
      return true;
    }

    bool VisitReturnStmt(ReturnStmt* ret) {
      update_matcher(MT::returnStmt, "returnStmt()");
      if (ret->getRetValue()) {
        std::string type = ret->getRetValue()->getType().getAsString();
        update_matcher(MT::hasReturnValue, "hasReturnValue()");
        add_type(type);
      }
      return true;
    }

    bool VisitImplicitCastExpr(ImplicitCastExpr* expr) {
      set_ignore_casts(true);
      return true;
    }

    bool VisitDeclRefExpr(DeclRefExpr* ref) {
      ValueDecl* decl = ref->getDecl();
      std::string name = decl->getNameAsString();
      update_matcher(MT::declRefExpr, "declRefExpr()");
      bind_to(name);
      if (decl->getType()->getTypeClass() != clang::Type::TypeClass::Auto) {
        std::string type = decl->getType().getAsString();
        add_type(type);
      }
      return true;
    }

private:
  ASTContext* context;
  std::string matcher = "";
  Node* root = nullptr;
  Node* current = root;
  int insert_point = 0;
  int bind_point = 0;

  void update_matcher(MatcherType sm, std::string code) {
    Node* temp = new Node(sm, code);
    if (root == nullptr) {
      root = temp;
      current = root;
    }
    else {
      current->add_child(current, temp);
      current = temp;
    }
  }

  void set_ignore_casts(bool b) {
    current->ignore_casts = b;
  }

  void bind_to(std::string name) {
    current->bound = true;
    current->bound_name = name;
  }

  void add_type(std::string type) {
    current->has_type = true;
    current->type = type;
  }
};


DeclarationMatcher matcher =
  functionDecl(allOf(
    hasAttr(attr::Matcher),
    hasBody(compoundStmt(
      hasAnySubstatement(compoundStmt(anything()).bind("body"))
    ))
  )).bind("matcher");

// std::unordered_map<std::string, VariantMatcher> stmt_matchers;
std::vector<MatcherWrapper<ast_matchers::internal::DynTypedMatcher> *> user_matchers;

class MatcherGenCallback : public MatchFinder::MatchCallback {
public:
  ASTContext* context;
  std::string matcher_name;

  std::vector<ParserValue> Args() { return std::vector<ParserValue>(); }
  std::vector<ParserValue> Args(const VariantValue &Arg1) {
    std::vector<ParserValue> Out(1);
    Out[0].Value = Arg1;
    return Out;
  }
  std::vector<ParserValue> Args(const VariantValue &Arg1,
                                const VariantValue &Arg2) {
    std::vector<ParserValue> Out(2);
    Out[0].Value = Arg1;
    Out[1].Value = Arg2;
    return Out;
  }
  std::vector<ParserValue> Args(std::vector<VariantValue> args) {
    std::vector<ParserValue> out(args.size());
    for (unsigned int i = 0; i < args.size(); i++) {
      out[i].Value = args[i];
    }
    return out;
  }


  VariantMatcher constructMatcher(StringRef MatcherName,
                                  Diagnostics *Error = nullptr) {
    Diagnostics DummyError;
    if (!Error) {
      Error = &DummyError;
    }
    llvm::Optional<MatcherCtor> Ctor = R::lookupMatcherCtor(MatcherName);
    VariantMatcher Out;
    if (Ctor) {
      Out = R::constructMatcher(*Ctor, {}, Args(), Error);
    }
    printf("made matcher %s\n", MatcherName.str().c_str());
    return Out;
  }

  VariantMatcher constructMatcher(StringRef MatcherName,
                                  const VariantValue &Arg1,
                                  Diagnostics *Error = nullptr) {
    Diagnostics DummyError;
    if (!Error) {
      Error = &DummyError;
    }
    llvm::Optional<MatcherCtor> Ctor = R::lookupMatcherCtor(MatcherName);
    VariantMatcher Out;
    if (Ctor) {
      Out = R::constructMatcher(*Ctor, {}, Args(Arg1), Error);
    }
    printf("made matcher %s\n", MatcherName.str().c_str());
    return Out;
  }

  VariantMatcher constructMatcher(StringRef MatcherName,
                                  const VariantValue &Arg1,
                                  const VariantValue &Arg2,
                                  Diagnostics *Error = nullptr) {
    Diagnostics DummyError;
    if (!Error) {
      Error = &DummyError;
    }
    llvm::Optional<MatcherCtor> Ctor = R::lookupMatcherCtor(MatcherName);
    VariantMatcher Out;
    if (Ctor) {
      Out = R::constructMatcher(*Ctor, {}, Args(Arg1, Arg2), Error);
    }
    printf("made matcher %s\n", MatcherName.str().c_str());
    return Out;
  }

  VariantMatcher constructMatcher(StringRef MatcherName, std::vector<VariantValue> args,
                                  Diagnostics* Error = nullptr) {
    Diagnostics DummyError;
    if (!Error) {
      Error = &DummyError;
    }
    llvm::Optional<MatcherCtor> Ctor = R::lookupMatcherCtor(MatcherName);
    VariantMatcher Out;
    if (Ctor) {
      Out = R::constructMatcher(*Ctor, {}, Args(args), Error);
    }
    printf("made matcher %s\n", MatcherName.str().c_str());
    return Out;
  }

  VariantMatcher make_matcher(Node* root) {
    std::vector<VariantValue> child_matchers;
    switch(root->matcher_type) {
      case MT::compoundStmt:
        child_matchers.clear();
        if (root->children.size() > 1) {
          for (Node* child : root->children) {
            child_matchers.push_back(
              constructMatcher("hasAnySubstatement", make_matcher(child)));
          }
          return constructMatcher("compoundStmt",
                  constructMatcher("allOf", child_matchers)
                 );
        }
        else if (root->children.size() == 1) {
          return constructMatcher("compoundStmt",
                  constructMatcher("hasAnySubstatement", make_matcher(root->children[0])));
        }
        else {
          return constructMatcher("compoundStmt");
        }
        break;
      case MT::returnStmt:
        child_matchers.clear();
        if (root->children.size() > 1) {
          for (Node* child : root->children) {
            child_matchers.push_back(make_matcher(child));
          }
          return constructMatcher("returnStmt", child_matchers);
        }
        else if (root->children.size() == 1) {
          return constructMatcher("returnStmt", make_matcher(root->children[0]));
        }
        else {
          return constructMatcher("returnStmt");
        }
        break;
      default:
        printf("ERROR: unimplemented matcher type\n");
        return VariantMatcher();
        break;
    }
  }

  void run(const MatchFinder::MatchResult& result) override {
    printf("found matcher\n");
    context = result.Context;

    const FunctionDecl* func = result.Nodes.getNodeAs<FunctionDecl>("matcher");

    if (!func || !context->getSourceManager().isWrittenInMainFile(func->getBeginLoc())) {
      printf("ERROR: invalid matcher definition\n");
      return;
    }
    printf("full function\n");
    func->dump();

    FullSourceLoc begin = context->getFullLoc(func->getBeginLoc());
    FullSourceLoc end = context->getFullLoc(func->getEndLoc());
    unsigned int begin_line = begin.getSpellingLineNumber();
    unsigned int begin_col = begin.getSpellingColumnNumber();
    unsigned int end_line = end.getSpellingLineNumber();
    unsigned int end_col = end.getSpellingColumnNumber();

    for (Attr* attr : func->attrs()) {
      if (attr->getKind() == attr::Matcher) {
        StringRef name = cast<MatcherAttr>(attr)->getMatcherName();
        matcher_name = name.str();
      }
    }
    printf("FOUND matcher %s at %d:%d - %d:%d\n", matcher_name.c_str(), begin_line, begin_col, end_line, end_col);

    const CompoundStmt* body = result.Nodes.getNodeAs<CompoundStmt>("body");
    if (!body || !context->getSourceManager().isWrittenInMainFile(body->getBeginLoc())) {
      printf("ERROR: invalid body\n");
      return;
    }
    printf("function body\n");
    body->dump();

    BuildMatcherVisitor visitor(context);

    visitor.TraverseStmt(const_cast<CompoundStmt*>(body));

    Node* matcher = visitor.get_matcher();

    printf("TREE STUFF\n");
    matcher->dump();

    printf("ACTUAL MATCHER\n");
    VariantMatcher varmatcher = make_matcher(matcher);

    llvm::Optional<DynTypedMatcher> dynmatcher = varmatcher.getSingleMatcher();
    if (dynmatcher) {
      MatcherWrapper<DynTypedMatcher>* m = new MatcherWrapper<DynTypedMatcher>(*dynmatcher, matcher_name,
        context->getSourceManager().getFilename(func->getBeginLoc()).str(),
        begin_line, begin_col);
      user_matchers.push_back(m);
    }
    else {
      printf("ERROR: ambiguous matcher\n");
    }
    matcher->clean_tree();
  }
};

#endif
