#ifndef CLANG_CONSTRUCT_MATCHERS_H
#define CLANG_CONSTRUCT_MATCHERS_H

#include "clang/ASTMatchers/Dynamic/VariantValue.h"

#include <string>

using namespace clang::ast_matchers::dynamic;

enum class MatcherType {
  callee,
  callExpr,
  compoundStmt,
  cudaKernelCallExpr,
  cxxConstructExpr,
  cxxFunctionalCastExpr,
  declRefExpr,
  equals,
  functionDecl,
  hasReturnValue,
  integerLiteral,
  returnStmt,
  to,
  valueDecl,
};

class Node {
public:
  MatcherType matcher_type;
  std::string matcher_string; // for debug/dumping purposes
  bool bound = false;
  std::string bound_name; // the name the matcher should be bound to
  bool has_name = false;
  std::string name; // the actual name of the thing, eg function name, var name
  bool has_type = false;
  std::string type;
  bool ignore_casts = false;
  bool is_literal = false;
  std::vector<Node*> children;
  std::vector<VariantValue> args;
  Node* parent = nullptr;

  Node(MatcherType m, std::string ms) : matcher_type(m), matcher_string(ms) {}

  void add_child(Node* parent, Node* child) {
    if (parent == nullptr) {
      parent = child;
    }
    else {
      parent->children.push_back(child);
    }
  }

  Node* get_child_or_null(MatcherType type) {
    for (Node* child : children) {
      if (child->matcher_type == type) {
        return child;
      }
    }
    return nullptr;
  }

  void dump_help(Node* n, int tab_depth) {
    for (int i = 0; i < tab_depth; i++) {
      printf("  ");
    }
    printf("%s;", n->matcher_string.c_str());
    if (n->ignore_casts) {
      printf("  ignore casts;");
    }
    if (n->has_type) {
      printf("  has type %s;", n->type.c_str());
    }
    if (n->bound) {
      printf("  bound to %s;", n->bound_name.c_str());
    }
    if (n->has_name) {
      printf("  named %s;", n->name.c_str());
    }
    if (n->is_literal) {
      printf("  is literal;");
    }
    printf("\n");
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

VariantMatcher make_matcher(Node* root, int level);

#endif // CLANG_CONSTRUCT_MATCHERS_H
