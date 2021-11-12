#ifndef CLANG_CONSTRUCT_MATCHERS_H
#define CLANG_CONSTRUCT_MATCHERS_H

#include "clang/ASTMatchers/Dynamic/VariantValue.h"

#include <string>

using namespace clang::ast_matchers::dynamic;

enum class MatcherType {
  compoundStmt,
  returnStmt,
  hasReturnValue,
  declRefExpr,
};

class Node {
public:
  MatcherType matcher_type;
  std::string matcher_string; // for debug/dumping purposes
  bool bound = false;
  std::string bound_name;
  bool has_type = false;
  std::string type;
  bool ignore_casts = false;
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

VariantMatcher make_matcher(Node* root);

#endif // CLANG_CONSTRUCT_MATCHERS_H
