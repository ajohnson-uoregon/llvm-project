#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchersInternal.h"

#include "clang/ASTMatchers/Dynamic/Registry.h"

#include "ConstructMatchers.h"
#include "LocalASTMatchers.h"

#include <vector>
#include <string>

using namespace clang;
using namespace clang::ast_matchers;
using namespace clang::ast_matchers::dynamic;

namespace clang {
namespace rewrite_tool {

using ast_matchers::internal::Matcher;

using MT = MatcherType;
using R = clang::ast_matchers::dynamic::Registry;

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

std::string VariantValue_asString(VariantValue val, bool dump_matcher) {
  if (val.isBoolean()) {
    return "boolean: " + std::to_string(val.getBoolean());
  }
  else if (val.isDouble()) {
     return "double: " + std::to_string(val.getDouble());
  }
  else if (val.isUnsigned()) {
    return "unsigned: " + std::to_string(val.getUnsigned());
  }
  else if (val.isString()) {
    return "string: " + val.getString();
  }
  else if (val.isNodeKind()) {
    return "AST node: " + val.getNodeKind().asStringRef().str();
  }
  else if (val.isMatcher()) {
    if (dump_matcher) {
      return "matcher: " + val.getMatcher().getTypeAsString();
    }
    else {
      return "matcher";
    }
  }
  else {
    return "unknown/bad value";
  }
}

bool is_singleton(MatcherType ty) {
  return std::find(singletons.begin(), singletons.end(), ty) != singletons.end();
}


// make matchers for non-bound nodes
VariantMatcher constructMatcher(StringRef MatcherName, int tab,
                                Diagnostics *Error) {
  Diagnostics DummyError;
  if (!Error) {
    Error = &DummyError;
  }
  std::optional<MatcherCtor> Ctor = R::lookupMatcherCtor(MatcherName);
  VariantMatcher Out;
  if (Ctor) {
    Out = R::constructMatcher(*Ctor, {}, Args(), Error);
  }
  else {
    printf("ERROR: could not find matcher %s in registry\n", MatcherName.str().c_str());
    return Out;
  }
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("made matcher (1) %s\n", MatcherName.str().c_str());
  return Out;
}

VariantMatcher constructMatcher(StringRef MatcherName,
                                const VariantValue &Arg1,
                                int tab,
                                Diagnostics *Error) {
  Diagnostics DummyError;
  if (!Error) {
    Error = &DummyError;
  }
  std::optional<MatcherCtor> Ctor = R::lookupMatcherCtor(MatcherName);
  VariantMatcher Out;
  if (Ctor) {
    Out = R::constructMatcher(*Ctor, {}, Args(Arg1), Error);
  }
  else {
    printf("ERROR: could not find matcher %s in registry\n", MatcherName.str().c_str());
    return Out;
  }
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("  with arg %s\n", VariantValue_asString(Arg1, false).c_str());
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("made matcher (2) %s\n", MatcherName.str().c_str());
  return Out;
}

VariantMatcher constructMatcher(StringRef MatcherName,
                                const VariantValue &Arg1,
                                const VariantValue &Arg2,
                                int tab,
                                Diagnostics *Error) {
  Diagnostics DummyError;
  if (!Error) {
    Error = &DummyError;
  }
  std::optional<MatcherCtor> Ctor = R::lookupMatcherCtor(MatcherName);
  VariantMatcher Out;
  if (Ctor) {
    Out = R::constructMatcher(*Ctor, {}, Args(Arg1, Arg2), Error);
  }
  else {
    printf("ERROR: could not find matcher %s in registry\n", MatcherName.str().c_str());
    return Out;
  }
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("  with arg %s\n", VariantValue_asString(Arg1, false).c_str());
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("  with arg %s\n", VariantValue_asString(Arg2, false).c_str());
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("made matcher (3) %s\n", MatcherName.str().c_str());
  return Out;
}

VariantMatcher constructMatcher(StringRef MatcherName,
                                std::vector<VariantValue> args,
                                int tab,
                                Diagnostics* Error) {
  Diagnostics DummyError;
  if (!Error) {
    Error = &DummyError;
  }
  std::optional<MatcherCtor> Ctor = R::lookupMatcherCtor(MatcherName);
  VariantMatcher Out;
  if (Ctor) {
    Out = R::constructMatcher(*Ctor, {}, Args(args), Error);
  }
  else {
    printf("ERROR: could not find matcher %s in registry\n", MatcherName.str().c_str());
    return Out;
  }
  for (auto arg : args) {
    for (int i = 0; i < tab; i++) {
      printf("  ");
    }
    printf("  with arg %s\n", VariantValue_asString(arg, false).c_str());
  }
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("made matcher (4) %s\n", MatcherName.str().c_str());
  return Out;
}


// make matchers for bound nodes
VariantMatcher constructBoundMatcher(StringRef MatcherName,
                                     StringRef BoundName,
                                     int tab,
                                     Diagnostics *Error) {
  Diagnostics DummyError;
  if (!Error) {
    Error = &DummyError;
  }
  std::optional<MatcherCtor> Ctor = R::lookupMatcherCtor(MatcherName);
  VariantMatcher Out;
  if (Ctor) {
    Out = R::constructBoundMatcher(*Ctor, {}, BoundName, Args(), Error);
  }
  else {
    printf("ERROR: could not find matcher %s in registry\n", MatcherName.str().c_str());
    return Out;
  }
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("made bound matcher (1) %s (%s)\n", MatcherName.str().c_str(), BoundName.str().c_str());
  return Out;
}

VariantMatcher constructBoundMatcher(StringRef MatcherName,
                                     StringRef BoundName,
                                     const VariantValue &Arg1,
                                     int tab,
                                     Diagnostics *Error) {
  Diagnostics DummyError;
  if (!Error) {
    Error = &DummyError;
  }
  std::optional<MatcherCtor> Ctor = R::lookupMatcherCtor(MatcherName);
  VariantMatcher Out;
  if (Ctor) {
    Out = R::constructBoundMatcher(*Ctor, {}, BoundName, Args(Arg1), Error);
  }
  else {
    printf("ERROR: could not find matcher %s in registry\n", MatcherName.str().c_str());
    return Out;
  }
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("  with arg %s\n", VariantValue_asString(Arg1, false).c_str());
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("made bound matcher (2) %s (%s)\n", MatcherName.str().c_str(), BoundName.str().c_str());
  return Out;
}

VariantMatcher constructBoundMatcher(StringRef MatcherName,
                                     StringRef BoundName,
                                     const VariantValue &Arg1,
                                     const VariantValue &Arg2,
                                     int tab,
                                     Diagnostics *Error) {
  Diagnostics DummyError;
  if (!Error) {
    Error = &DummyError;
  }
  std::optional<MatcherCtor> Ctor = R::lookupMatcherCtor(MatcherName);
  VariantMatcher Out;
  if (Ctor) {
    Out = R::constructBoundMatcher(*Ctor, {}, BoundName, Args(Arg1, Arg2), Error);
  }
  else {
    printf("ERROR: could not find matcher %s in registry\n", MatcherName.str().c_str());
    return Out;
  }
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("  with arg %s\n", VariantValue_asString(Arg1, false).c_str());
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("  with arg %s\n", VariantValue_asString(Arg2, false).c_str());
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("made bound matcher (3) %s (%s)\n", MatcherName.str().c_str(), BoundName.str().c_str());
  return Out;
}

VariantMatcher constructBoundMatcher(StringRef MatcherName,
                                     StringRef BoundName,
                                     std::vector<VariantValue> args,
                                     int tab,
                                     Diagnostics* Error) {
  Diagnostics DummyError;
  if (!Error) {
    Error = &DummyError;
  }
  std::optional<MatcherCtor> Ctor = R::lookupMatcherCtor(MatcherName);
  VariantMatcher Out;
  if (Ctor) {
    Out = R::constructBoundMatcher(*Ctor, {}, BoundName, Args(args), Error);
  }
  else {
    printf("ERROR: could not find matcher %s in registry\n", MatcherName.str().c_str());
    return Out;
  }
  for (auto arg : args) {
    for (int i = 0; i < tab; i++) {
      printf("  ");
    }
    printf("  with arg %s\n", VariantValue_asString(arg, false).c_str());
  }
  for (int i = 0; i < tab; i++) {
    printf("  ");
  }
  printf("made matcher (4) %s (%s)\n", MatcherName.str().c_str(), BoundName.str().c_str());
  return Out;
}

VariantMatcher handle_non_bindable_children(Node* root,
    std::vector<VariantValue> child_matchers, StringRef name, int level) {
  if (child_matchers.size() > 1) {
    if (root->ignore_casts) {
      return constructMatcher("ignoringParenCasts",
              constructMatcher(name,
                constructMatcher("allOf", child_matchers, level+3), level+2), level+1);
    }
    else {
      return constructMatcher(name,
              constructMatcher("allOf", child_matchers, level+2), level+1);
    }
  } // child_matchers.size() > 1
  else if (child_matchers.size() == 1) { // child_matchers.size() == 1
    if (root->ignore_casts) {
      return constructMatcher("ignoringParenCasts",
              constructMatcher(name, child_matchers[0], level+2), level+1);
    }
    else {
      return constructMatcher(name, child_matchers[0], level+1);
    }
  }
  else { // child_matchers.size() == 0
    if (root->ignore_casts) {
      return constructMatcher("ignoringParenCasts",
              constructMatcher(name, level+2), level+1);
    }
    else {
      return constructMatcher(name, level+1);
    }
  } // child_matchers.size()
}

VariantMatcher handle_bindable_children(Node* root,
    std::vector<VariantValue> child_matchers, StringRef name, int level) {
  if (child_matchers.size() > 1) {
    if (root->ignore_casts) {
      if (root->bound) {
        return constructMatcher("ignoringParenCasts",
                constructBoundMatcher(name, StringRef(root->bound_name),
                  constructMatcher("allOf", child_matchers, level+3), level+2), level+1);
      }
      else {
        return constructMatcher("ignoringParenCasts",
                constructMatcher(name,
                  constructMatcher("allOf", child_matchers, level+3), level+2), level+1);
      }
    }
    else { // no ignore casts
      if (root->bound) {
        return constructBoundMatcher(name, StringRef(root->bound_name),
                constructMatcher("allOf", child_matchers, level+2), level+1);
      }
      else {
        return constructMatcher(name,
                constructMatcher("allOf", child_matchers, level+2), level+1);
      }
    } // ignore_casts
  }
  else if (child_matchers.size() == 1) { // child_matchers.size() == 1
    if (root->ignore_casts) {
      if (root->bound) {
        return constructMatcher("ignoringParenCasts",
                constructBoundMatcher(name, StringRef(root->bound_name),
                  child_matchers[0], level+2), level+1);
      }
      else {
        return constructMatcher("ignoringParenCasts",
                constructMatcher(name, child_matchers[0], level+2), level+1);
      }
    }
    else { // no ignore casts
      if (root->bound) {
        return constructBoundMatcher(name, StringRef(root->bound_name), child_matchers[0], level+1);
      }
      else {
        return constructMatcher(name, child_matchers[0], level+1);
      }
    } // ignore_casts
  }
  else { // child_matchers.size() ==0
    if (root->ignore_casts) {
      if (root->bound) {
        return constructMatcher("ignoringParenCasts",
                constructBoundMatcher(name, StringRef(root->bound_name),
                  level+2), level+1);
      }
      else {
        return constructMatcher("ignoringParenCasts",
                constructMatcher(name, level+2), level+1);
      }
    }
    else { // no ignore casts
      if (root->bound) {
        return constructBoundMatcher(name, StringRef(root->bound_name), level+1);
      }
      else {
        return constructMatcher(name, level+1);
      }
    } // ignore_casts
  } // child_matchers.size()
}

////////////////////////////////////////////////////

// mostly copy-paste from handle_bindable_node but need to add hasAnySubstatement
VariantMatcher handle_compoundStmt(Node* root, int level) {
  std::vector<VariantValue> child_matchers;
  child_matchers.insert(child_matchers.end(), root->args.begin(), root->args.end());

  // if (root->has_type && root->is_literal) {
  //   child_matchers.push_back(constructMatcher("hasType",
  //       constructMatcher("asString", StringRef(root->type), level+6), level+5));
  // }
  if (root->has_name) {
    child_matchers.push_back(constructMatcher("hasName", StringRef(root->qual_name), level+5));
  }

  if (root->children) {
    for (Node* child = root->children; child != nullptr; child = child->next_sibling) {
      if (child->matcher_type == MT::loopBody) {
        root->bind_to(child->qual_name);
      }
      else {
        child_matchers.push_back(constructMatcher("hasAnySubstatement",
            make_matcher(child, level+6), level+5));
      }
    }
  }
  if (child_matchers.size() < 1) {
    // guarantee child_matchers.size() >= 1 (also required to not make an
    // ambiguous matcher and actually match things)
    child_matchers.push_back(constructMatcher("anything", level+5));
  }

  return handle_bindable_children(root, child_matchers, "compoundStmt", level);
}

VariantMatcher handle_declRefExpr(Node* root, int level) {
  std::vector<VariantValue> child_matchers;
  child_matchers.insert(child_matchers.end(), root->args.begin(), root->args.end());

  std::string name = "expr";

  // if this is a literal node, we want to match the same actual reference,
  // so don't match a generic expr, match the ref
  // if the traversal bound it to a name, we want that to be the actual name
  // drop a warning if we're overwriting a name, which theoretically should
  // never happen but we should always check
  if (root->is_literal) {
    name = "declRefExpr";
    if (root->bound) {
      root->bound = false;
      if (root->has_name) {
        printf("WARNING: renaming node named %s (%s) to %s\n",
            root->short_name.c_str(), root->qual_name.c_str(), root->bound_name.c_str());
      }
      root->has_name = true;
      root->short_name = root->bound_name;
      root->qual_name  = root->bound_name;
    }
  }

  // if (root->has_type && root->is_literal) {
  //   child_matchers.push_back(constructMatcher("hasType",
  //       constructMatcher("asString", StringRef(root->type), level+6), level+5));
  // }
  if (root->has_name) {
    // printf("WARNING: putting hasName inside expr()\n");
    child_matchers.push_back(constructMatcher("hasName", StringRef(root->qual_name), level+5));
  }

  if (root->children) {
    for (Node* child = root->children; child != nullptr; child = child->next_sibling) {
      child_matchers.push_back(make_matcher(child, level+5));
    }
  }
  if (child_matchers.size() < 1) {
    // guarantee child_matchers.size() >= 1 (also required to not make an
    // ambiguous matcher and actually match things)
    child_matchers.push_back(constructMatcher("anything", level+5));
  }

  return handle_bindable_children(root, child_matchers, "declRefExpr", level);
}

VariantMatcher handle_callExpr(Node* root, std::string call_type, int level) {
  std::vector<VariantValue> child_matchers;
  child_matchers.insert(child_matchers.end(), root->args.begin(), root->args.end());

  // if (root->has_type && root->is_literal) {
  //   child_matchers.push_back(constructMatcher("hasType",
  //       constructMatcher("asString", StringRef(root->type), level+6), level+5));
  // }
  if (root->has_name) {
    child_matchers.push_back(constructMatcher("hasName", StringRef(root->qual_name), level+5));
  }

  std::string callee_short_name = "";
  std::string callee_qual_name = "";
  Node* callee = root->get_child_or_null(MT::callee);
  if (callee != nullptr) {        // functionDecl name
    printf("callee not null\n");
    Node* funcdecl = callee->get_child_or_null(MT::functionDecl);
    Node* lookup = callee->get_child_or_null(MT::unresolvedLookupExpr);
    if (funcdecl != nullptr) {
      printf("funcdecl not null\n");
      if (funcdecl->is_named()) {
        callee_short_name = funcdecl->short_name;
        callee_qual_name = funcdecl->qual_name;
      }
      else if (funcdecl->is_bound()) {
        callee_short_name = funcdecl->bound_name;
        callee_qual_name = funcdecl->bound_name;
      }
      else {
        printf("WARNING: callee function has no name\n");
      }
    }
    else if (lookup != nullptr) {
      printf("lookup expr not null\n");
      Node* hasany = lookup->get_child_or_null(MT::hasAnyDeclaration);
      Node* decl = hasany->get_child_or_null(MT::namedDecl);
      if (decl) {
        if (decl->is_named()) {
          callee_short_name = decl->short_name;
          callee_qual_name = decl->qual_name;
        }
        else if (decl->is_bound()) {
          callee_short_name = decl->bound_name;
          callee_qual_name = decl->bound_name;
        }
        else {
          printf("WARNING: callee lookup has no name\n");
        }
      }
      else {
        printf("WARNING: lookup expr has no named child\n");
      }

    }
    else {
      printf("WARNING: callee has no name at all\n");
    }
  }
  printf("callee_name %s (%s)\n", callee_short_name.c_str(), callee_qual_name.c_str());

  if (root->children) {
    int argnum = 0; // SHRUG I guess the order works out?
    for (Node* child = root->children; child != nullptr; child = child->next_sibling) {
      // need to special case for cudaKernelCallExpr so the call to
      // __cudaPushCallConfiguration isn't treated as an argument
      if (root->matcher_type == MT::cudaKernelCallExpr &&
               child->matcher_type == MT::callExpr) {
        Node* cuda_call_conf = child->get_child_or_null(MT::callee);
        if (cuda_call_conf && cuda_call_conf->children->short_name == "__cudaPushCallConfiguration") {
          // tree *should* look like
          // CallExpr <- child
          //  callee <- children[0]
          //    functionDecl  for __cudaPushCallConfiguration
          //  declRefExpr to function <- children[1]
          //  declRefExprs to at least 2 args <- children[2-5]
          Node* temp_child = child->children; // callee
          temp_child = temp_child->next_sibling; // declRefExpr to fxn
          temp_child = temp_child->next_sibling; // first arg
          if (temp_child) {
            child_matchers.push_back(constructMatcher("cudaGridDim",
              make_matcher(temp_child, level+6), level+5));
            temp_child = temp_child->next_sibling; // second arg (guaranteed)
            child_matchers.push_back(constructMatcher("cudaBlockDim",
              make_matcher(temp_child, level+6), level+5));
            temp_child = temp_child->next_sibling; // third arg or null
          }
          if (temp_child) {
            child_matchers.push_back(constructMatcher("cudaSharedMemPerBlock",
              constructMatcher("allOf",
                constructMatcher("unless",
                  constructMatcher("cxxDefaultArgExpr",
                    constructMatcher("anything", level+9),
                  level+8),
                level+7),
                make_matcher(temp_child, level+7),
              level+6),
            level+5));
            temp_child = temp_child->next_sibling; // fourth arg or null
          }
          else {
            child_matchers.push_back(constructMatcher("cudaSharedMemPerBlock",
              constructMatcher("cxxDefaultArgExpr", constructMatcher("anything", level+7), level+6), level+5));
          }
          if (temp_child) {
            child_matchers.push_back(constructMatcher("cudaStream",
              constructMatcher("allOf",
                constructMatcher("unless",
                  constructMatcher("cxxDefaultArgExpr",
                    constructMatcher("anything", level+9),
                  level+8),
                level+7),
                make_matcher(temp_child, level+7),
              level+6),
            level+5));
          }
          else {
            child_matchers.push_back(constructMatcher("cudaStream",
              constructMatcher("cxxDefaultArgExpr", constructMatcher("anything", level+7), level+6), level+5));
          }
        }

        if (child_matchers.size() < 1) {
          child_matchers.push_back(constructMatcher("anything", level+5));
        }
        return handle_bindable_children(root, child_matchers, "cudaKernelCallExpr", level);
      }
      else if (child->matcher_type == MT::callee) {
        child_matchers.push_back(make_matcher(child, level+5));
      }
      else {
        if (!child->self_or_child_bound_to(callee_short_name + ";" + callee_qual_name) &&
            !child->self_or_child_qual_named(callee_qual_name)) {
          child_matchers.push_back(constructMatcher("hasArgument", argnum,
              make_matcher(child, level+6), level+5));
          argnum++;
        }
      }
    }
    child_matchers.push_back(constructMatcher("argumentCountAsWrittenIs", VariantValue(argnum), level+5));
  }
  if (child_matchers.size() < 1) {
    // guarantee child_matchers.size() >= 1 (also required to not make an
    // ambiguous matcher and actually match things)
    child_matchers.push_back(constructMatcher("anything", level+5));
  }

  return handle_bindable_children(root, child_matchers, call_type, level);
}

VariantMatcher handle_binaryOperator(Node* root, int level) {
  std::vector<VariantValue> child_matchers;
  child_matchers.insert(child_matchers.end(), root->args.begin(), root->args.end());

  // if (root->has_type && root->is_literal) {
  //   child_matchers.push_back(constructMatcher("hasType",
  //     constructMatcher("asString", StringRef(root->type), level+6), level+5));
  // }

  if (root->has_name) {
    child_matchers.push_back(constructMatcher("hasName", StringRef(root->qual_name), level+5));
  }

  if (root->children) {
    Node* opname = root->children;
    child_matchers.push_back(make_matcher(opname, level+5));
    //lhs always comes first
    Node* lhs = opname->next_sibling;
    if (lhs == nullptr) {
      printf("ERROR: binop doesn't have operands???\n");
    }
    child_matchers.push_back(constructMatcher("hasLHS", make_matcher(lhs, level+6), level+5));

    Node* rhs = lhs->next_sibling;
    if (rhs == nullptr) {
      printf("ERROR: binop only has one operand???\n");
    }
    child_matchers.push_back(
      constructMatcher("hasRHS",
        constructMatcher("ignoringParenCasts",
          make_matcher(rhs, level+7), level+6), level+5));

    if (rhs->next_sibling) {
      printf("binop has more than two operands???\n");
    }
  }
  if (child_matchers.size() < 1) {
    // guarantee child_matchers.size() >= 1 (also required to not make an
    // ambiguous matcher and actually match things)
    child_matchers.push_back(constructMatcher("anything", level+5));
  }

  return handle_bindable_children(root, child_matchers, "binaryOperator", level);
}

VariantMatcher handle_forStmt(Node* root, int level) {
  std::vector<VariantValue> child_matchers;
  child_matchers.insert(child_matchers.end(), root->args.begin(), root->args.end());

  // if (root->has_type && root->is_literal) {
  //   child_matchers.push_back(constructMatcher("hasType",
  //     constructMatcher("asString", StringRef(root->type), level+6), level+5));
  // }

  if (root->has_type && root->matcher_type == MatcherType::varDecl) {
    child_matchers.push_back(constructMatcher("hasType",
      constructMatcher("asString", StringRef(root->type), level+6), level+5));
  }

  if (root->has_name) {
    child_matchers.push_back(constructMatcher("hasName", StringRef(root->qual_name), level+5));
  }

  if (root->children) {
    // for (Node* child = root->children; child != nullptr; child = child->next_sibling) {
    //   child_matchers.push_back(make_matcher(child, level+5));
    // }
    Node* loopinit = root->children;
    child_matchers.push_back(constructMatcher("hasLoopInit", make_matcher(loopinit, level+6), level+5));

    Node* cond = loopinit->next_sibling;
    if (cond == nullptr) {
      printf("ERROR: loop doesn't have condition???\n");
    }
    child_matchers.push_back(constructMatcher("hasCondition", make_matcher(cond, level+6), level+5));

    Node* inc = cond->next_sibling;
    if (inc == nullptr) {
      printf("ERROR: loop doesn't have increment???\n");
    }
    child_matchers.push_back(constructMatcher("hasIncrement", make_matcher(inc, level+6), level+5));

    Node* body = inc->next_sibling;
    if (body == nullptr) {
      printf("ERROR: loop doesn't have body???\n");
    }
    child_matchers.push_back(constructMatcher("hasBody", make_matcher(body, level+6), level+5));

    if (body->next_sibling) {
      printf("forstmt has extra operands???\n");
    }
  }
  if (child_matchers.size() < 1) {
    // guarantee child_matchers.size() >= 1 (also required to not make an
    // ambiguous matcher and actually match things)
    child_matchers.push_back(constructMatcher("anything", level+5));
  }

  return handle_bindable_children(root, child_matchers, "forStmt", level);
}

VariantMatcher handle_unaryOperator(Node* root, int level) {
  std::vector<VariantValue> child_matchers;
  child_matchers.insert(child_matchers.end(), root->args.begin(), root->args.end());

  // if (root->has_type && root->is_literal) {
  //   child_matchers.push_back(constructMatcher("hasType",
  //     constructMatcher("asString", StringRef(root->type), level+6), level+5));
  // }

  if (root->has_name) {
    child_matchers.push_back(constructMatcher("hasName", StringRef(root->qual_name), level+5));
  }

  if (root->children) {
    Node* opname = root->children;
    child_matchers.push_back(make_matcher(opname, level+5));
    //lhs always comes first
    Node* operand = opname->next_sibling;
    if (operand == nullptr) {
      printf("ERROR: unary op doesn't have operand???\n");
    }
    child_matchers.push_back(constructMatcher("hasUnaryOperand", make_matcher(operand, level+6), level+5));

    if (operand->next_sibling) {
      printf("ERROR: unary op has more than one operand???\n");
    }
  }
  if (child_matchers.size() < 1) {
    // guarantee child_matchers.size() >= 1 (also required to not make an
    // ambiguous matcher and actually match things)
    child_matchers.push_back(constructMatcher("anything", level+5));
  }

  return handle_bindable_children(root, child_matchers, "unaryOperator", level);
}

VariantMatcher handle_declStmt(Node* root, int level) {
  std::vector<VariantValue> child_matchers;
  child_matchers.insert(child_matchers.end(), root->args.begin(), root->args.end());

  // if (root->has_type && root->is_literal) {
  //   child_matchers.push_back(constructMatcher("hasType",
  //     constructMatcher("asString", StringRef(root->type), level+6), level+5));
  // }

  if (root->has_type && root->matcher_type == MatcherType::varDecl) {
    child_matchers.push_back(constructMatcher("hasType",
      constructMatcher("asString", StringRef(root->type), level+6), level+5));
  }

  if (root->has_name) {
    child_matchers.push_back(constructMatcher("hasName", StringRef(root->qual_name), level+5));
  }

  if (root->children) {
    int declnum = 0;
    for (Node* child = root->children; child != nullptr; child = child->next_sibling) {
      child_matchers.push_back(constructMatcher("containsDeclaration", declnum,
        make_matcher(child, level+6), level+5));
      declnum++;
    }
  }
  if (child_matchers.size() < 1) {
    // guarantee child_matchers.size() >= 1 (also required to not make an
    // ambiguous matcher and actually match things)
    child_matchers.push_back(constructMatcher("anything", level+5));
  }

  return handle_bindable_children(root, child_matchers, "declStmt", level);
}

VariantMatcher handle_arraySubscriptExpr(Node* root, int level) {
  std::vector<VariantValue> child_matchers;
  child_matchers.insert(child_matchers.end(), root->args.begin(), root->args.end());

  // if (root->has_type && root->is_literal) {
  //   child_matchers.push_back(constructMatcher("hasType",
  //     constructMatcher("asString", StringRef(root->type), level+6), level+5));
  // }

  if (root->has_type && root->matcher_type == MatcherType::varDecl) {
    child_matchers.push_back(constructMatcher("hasType",
      constructMatcher("asString", StringRef(root->type), level+6), level+5));
  }

  if (root->has_name) {
    child_matchers.push_back(constructMatcher("hasName", StringRef(root->qual_name), level+5));
  }

  if (root->children) {
    Node* array = root->children;
    child_matchers.push_back(constructMatcher("hasBase",
      make_matcher(array, level+6), level+5));

    Node* index = array->next_sibling;
    if (index == nullptr) {
      printf("ERROR: ArraySubscriptExpr doesn't have index\n");
    }
    child_matchers.push_back(constructMatcher("hasIndex",
      make_matcher(index, level+6), level+5));

    if (index->next_sibling != nullptr) {
      printf("ERROR: ArraySubscriptExpr has more than two operands???\n");
    }
  }
  if (child_matchers.size() < 1) {
    // guarantee child_matchers.size() >= 1 (also required to not make an
    // ambiguous matcher and actually match things)
    child_matchers.push_back(constructMatcher("anything", level+5));
  }

  return handle_bindable_children(root, child_matchers, "arraySubscriptExpr", level);
}

VariantMatcher handle_anyOf(Node* root, int level) {
  std::vector<VariantValue> child_matchers;
  child_matchers.insert(child_matchers.end(), root->args.begin(), root->args.end());

  // if (root->has_type && root->is_literal) {
  //   child_matchers.push_back(constructMatcher("hasType",
  //     constructMatcher("asString", StringRef(root->type), level+6), level+5));
  // }
  if (root->has_name) {
    child_matchers.push_back(constructMatcher("hasName", StringRef(root->qual_name), level+5));
  }
  if (root->bound) {
    printf("WARNING: binding on a non bindable node\n");
  }

  if (root->children) {
    for (Node* child = root->children; child != nullptr; child = child->next_sibling) {
      child_matchers.push_back(make_matcher(child, level+5));
    }
  }
  if (child_matchers.size() < 1) {
    // guarantee child_matchers.size() >= 1 (also required to not make an
    // ambiguous matcher and actually match things)
    child_matchers.push_back(constructMatcher("anything", level+5));
  }

  if (child_matchers.size() > 1) {
    if (root->ignore_casts) {
      return constructMatcher("ignoringParenCasts",
                constructMatcher("anyOf", child_matchers, level+2), level+1);
    }
    else {
      return constructMatcher("anyOf", child_matchers, level+1);
    }
  } // child_matchers.size() > 1
  else { // child_matchers.size() == 1
    // if (root->ignore_casts) {
    // TODO make this not always ignore casts, maybe
      return constructMatcher("ignoringParenCasts", child_matchers[0], level+1);
    // }
    // else {
      // return child_matchers[0];
    // }
  } // child_matchers.size()
}

VariantMatcher handle_ifStmt(Node* root, int level) {
  std::vector<VariantValue> child_matchers;
  child_matchers.insert(child_matchers.end(), root->args.begin(), root->args.end());

  // if (root->has_type && root->is_literal) {
  //   child_matchers.push_back(constructMatcher("hasType",
  //     constructMatcher("asString", StringRef(root->type), level+6), level+5));
  // }

  if (root->has_type && root->matcher_type == MatcherType::varDecl) {
    child_matchers.push_back(constructMatcher("hasType",
      constructMatcher("asString", StringRef(root->type), level+6), level+5));
  }

  if (root->has_name) {
    child_matchers.push_back(constructMatcher("hasName", StringRef(root->qual_name), level+5));
  }

  if (root->children) {
    // for (Node* child = root->children; child != nullptr; child = child->next_sibling) {
    //   child_matchers.push_back(make_matcher(child, level+5));
    // }
    Node* cond = root->children;
    child_matchers.push_back(constructMatcher("hasCondition", make_matcher(cond, level+6), level+5));

    Node* thenstmt = cond->next_sibling;
    if (thenstmt == nullptr) {
      printf("ERROR: if stmt doesn't have then code???\n");
    }
    child_matchers.push_back(constructMatcher("hasThen", make_matcher(thenstmt, level+6), level+5));

    Node* elsestmt = thenstmt->next_sibling;
    if (elsestmt != nullptr) {
      child_matchers.push_back(constructMatcher("hasElse", make_matcher(elsestmt, level+6), level+5));
    }

    if (elsestmt && elsestmt->next_sibling) {
      printf("ifstmt has extra operands???\n");
    }
  }
  if (child_matchers.size() < 1) {
    // guarantee child_matchers.size() >= 1 (also required to not make an
    // ambiguous matcher and actually match things)
    child_matchers.push_back(constructMatcher("anything", level+5));
  }

  return handle_bindable_children(root, child_matchers, "ifStmt", level);
}

VariantMatcher handle_openmp_node(Node* root, StringRef name, int level) {
  std::vector<VariantValue> child_matchers;
  child_matchers.insert(child_matchers.end(), root->args.begin(), root->args.end());

  // if (root->has_type && root->is_literal) {
  //   child_matchers.push_back(constructMatcher("hasType",
  //     constructMatcher("asString", StringRef(root->type), level+6), level+5));
  // }

  if (root->has_type && root->matcher_type == MatcherType::varDecl) {
    child_matchers.push_back(constructMatcher("hasType",
      constructMatcher("asString", StringRef(root->type), level+6), level+5));
  }

  if (root->has_name) {
    child_matchers.push_back(constructMatcher("hasName", StringRef(root->qual_name), level+5));
  }

  if (root->children) {
    // for (Node* child = root->children; child != nullptr; child = child->next_sibling) {
    //   child_matchers.push_back(make_matcher(child, level+5));
    // }
    Node* start = root->children;
    if (start->next_sibling == nullptr) {
      child_matchers.push_back(constructMatcher("hasAssociatedStmt", make_matcher(start, level+6), level+5));
      child_matchers.push_back(constructMatcher("hasNoClauses", level+5));
    }
    else if (start->next_sibling != nullptr) {
      //first children will be an arbitrary number of clauses
      while (start->next_sibling) {
        child_matchers.push_back(constructMatcher("hasAnyClause", make_matcher(start, level+6), level+5));
        start = start->next_sibling;
      }

      // last child should be the statement
      if (start) {
        child_matchers.push_back(constructMatcher("hasAssociatedStmt", make_matcher(start, level+6), level+5));
      }
    }
  }
  else {
    printf("omp node has no children???\n");
  }

  if (child_matchers.size() < 1) {
    // guarantee child_matchers.size() >= 1 (also required to not make an
    // ambiguous matcher and actually match things)
    child_matchers.push_back(constructMatcher("anything", level+5));
  }

  return handle_bindable_children(root, child_matchers, name, level);
}



VariantMatcher handle_non_bindable_node(Node* root, StringRef name, int level) {
  std::vector<VariantValue> child_matchers;
  child_matchers.insert(child_matchers.end(), root->args.begin(), root->args.end());

  // if (root->has_type && root->is_literal) {
  //   child_matchers.push_back(constructMatcher("hasType",
  //     constructMatcher("asString", StringRef(root->type), level+6), level+5));
  // }
  if (root->has_name) {
    child_matchers.push_back(constructMatcher("hasName", StringRef(root->qual_name), level+5));
  }
  if (root->bound) {
    printf("WARNING: binding on a non bindable node\n");
  }

  if (root->children) {
    for (Node* child = root->children; child != nullptr; child = child->next_sibling) {
      child_matchers.push_back(make_matcher(child, level+5));
    }
  }
  if (child_matchers.size() < 1 && !is_singleton(root->matcher_type)) {
    // guarantee child_matchers.size() >= 1 (also required to not make an
    // ambiguous matcher and actually match things)
    child_matchers.push_back(constructMatcher("anything", level+5));
  }

  return handle_non_bindable_children(root, child_matchers, name, level);
}

VariantMatcher handle_bindable_node(Node* root, StringRef name, int level) {
  std::vector<VariantValue> child_matchers;
  child_matchers.insert(child_matchers.end(), root->args.begin(), root->args.end());

  // if (root->has_type && root->is_literal) {
  //   child_matchers.push_back(constructMatcher("hasType",
  //     constructMatcher("asString", StringRef(root->type), level+6), level+5));
  // }

  if (root->has_type && root->matcher_type == MatcherType::varDecl) {
    child_matchers.push_back(constructMatcher("hasType",
      constructMatcher("asString", StringRef(root->type), level+6), level+5));
  }

  if (root->has_name) {
    child_matchers.push_back(constructMatcher("hasName", StringRef(root->qual_name), level+5));
  }

  if (root->children) {
    for (Node* child = root->children; child != nullptr; child = child->next_sibling) {
      child_matchers.push_back(make_matcher(child, level+5));
    }
  }
  if (child_matchers.size() < 1 && !is_singleton(root->matcher_type)) {
    // guarantee child_matchers.size() >= 1 (also required to not make an
    // ambiguous matcher and actually match things)
    child_matchers.push_back(constructMatcher("anything", level+5));
  }

  return handle_bindable_children(root, child_matchers, name, level);
}

VariantMatcher make_matcher(Node* root, int level) {
  switch(root->matcher_type) {
    case MT::anyOf:
      return handle_anyOf(root, level);
    case MT::arraySubscriptExpr:
      return handle_arraySubscriptExpr(root, level);
    case MT::binaryOperator:
      return handle_binaryOperator(root, level);
    case MT::callee:
      return handle_non_bindable_node(root, "callee", level);
    case MT::callExpr:
      return handle_callExpr(root, "callExpr", level);
    case MT::capturedStmt:
      return handle_bindable_node(root, "capturedStmt", level);
    case MT::compoundStmt:
      return handle_compoundStmt(root, level);
    case MT::compoundLiteralExpr:
      return handle_bindable_node(root, "compoundLiteralExpr", level);
    case MT::cudaKernelCallExpr:
      return handle_callExpr(root, "cudaKernelCallExpr", level);
    case MT::cxxConstructExpr:
      return handle_bindable_node(root, "cxxConstructExpr", level);
    case MT::cxxDeleteExpr:
      return handle_bindable_node(root, "cxxDeleteExpr", level);
    case MT::cxxMethodDecl:
      return handle_bindable_node(root, "cxxMethodDecl", level);
    case MT::cxxNewExpr:
      return handle_bindable_node(root, "cxxNewExpr", level);
    case MT::cxxOperatorCallExpr:
      return handle_callExpr(root, "cxxOperatorCallExpr", level);
    case MT::cxxThisExpr:
      return handle_bindable_node(root, "cxxThisExpr", level);
    // case MT::cxxDefaultArgExpr:
    //   return handle_non_bindable_node(root, "cxxDefaultArgExpr", level);
    case MT::declRefExpr:
      return handle_declRefExpr(root, level);
    case MT::declStmt:
      return handle_declStmt(root, level);
    case MT::equals:
      return handle_non_bindable_node(root, "equals", level);
    case MT::expr:
      return handle_bindable_node(root, "expr", level);
    case MT::fieldDecl:
      return handle_bindable_node(root, "fieldDecl", level);
    case MT::floatLiteral:
      return handle_bindable_node(root, "floatLiteral", level);
    case MT::forStmt:
      return handle_forStmt(root, level);
    case MT::functionDecl:
      return handle_bindable_node(root, "functionDecl", level);
    case MT::hasAnyBody:
      return handle_non_bindable_node(root, "hasAnyBody", level);
    case MT::hasAnyDeclaration:
      return handle_non_bindable_node(root, "hasAnyDeclaration", level);
    case MT::hasAnyLHSExpr:
      return handle_non_bindable_node(root, "hasAnyLHSExpr", level);
    case MT::hasAnyParameter:
      return handle_non_bindable_node(root, "hasAnyParameter", level);
    case MT::hasAnyReductionOp:
      return handle_non_bindable_node(root, "hasAnyReductionOp", level);
    case MT::hasAnyRHSExpr:
      return handle_non_bindable_node(root, "hasAnyRHSExpr", level);
    case MT::hasAnySubExpr:
      return handle_non_bindable_node(root, "hasAnySubExpr", level);
    case MT::hasArraySize:
      return handle_non_bindable_node(root, "hasArraySize", level);
    case MT::hasAssociatedStmt:
      return handle_non_bindable_node(root, "hasAssociatedStmt", level);
    case MT::hasCallOperator:
      return handle_non_bindable_node(root, "hasCallOperator", level);
    case MT::hasCapturedStmt:
      return handle_non_bindable_node(root, "hasCapturedStmt", level);
    case MT::hasDeleteArg:
      return handle_non_bindable_node(root, "hasDeleteArg", level);
    case MT::hasExpectedReturnType:
      return handle_non_bindable_node(root, "hasExpectedReturnType", level);
    case MT::hasInitializer:
      return handle_non_bindable_node(root, "hasInitializer", level);
    case MT::hasLambdaBody:
      return handle_non_bindable_node(root, "hasLambdaBody", level);
    case MT::hasNewInitializer:
      return handle_non_bindable_node(root, "hasNewInitializer", level);
    case MT::hasObjectExpression:
      return handle_non_bindable_node(root, "hasObjectExpression", level);
    case MT::hasOperatorName:
      return handle_non_bindable_node(root, "hasOperatorName", level);
    case MT::hasParameter:
      return handle_non_bindable_node(root, "hasParameter", level);
    case MT::hasReturnValue:
      return handle_non_bindable_node(root, "hasReturnValue", level);
    case MT::hasSingleArgumentExpr:
      return handle_non_bindable_node(root, "hasSingleArgumentExpr", level);
    case MT::hasSubExpr:
      return handle_non_bindable_node(root, "hasSubExpr", level);
    case MT::hasType:
      return handle_non_bindable_node(root, "hasType", level);
    case MT::ifStmt:
      return handle_ifStmt(root, level);
    case MT::ignoringParenImpCasts:
      return handle_non_bindable_node(root, "ignoringParenImpCasts", level);
    case MT::integerLiteral:
      return handle_bindable_node(root, "integerLiteral", level);
    case MT::isArrayForm:
      return handle_non_bindable_node(root, "isArrayForm", level);
    case MT::isNotArrayForm:
      return handle_non_bindable_node(root, "isNotArrayForm", level);
    case MT::lambdaExpr:
      return handle_bindable_node(root, "lambdaExpr", level);
    case MT::memberExpr:
      return handle_bindable_node(root, "memberExpr", level);
    case MT::member:
      return handle_non_bindable_node(root, "member", level);
    case MT::namedDecl:
      return handle_bindable_node(root, "namedDecl", level);
    case MT::ompAtomicDirective:
        return handle_openmp_node(root, "ompAtomicDirective", level);
    case MT::ompBarrierDirective:
      return handle_openmp_node(root, "ompBarrierDirective", level);
    case MT::ompCancelDirective:
      return handle_openmp_node(root, "ompCancelDirective", level);
    case MT::ompCancellationPointDirective:
      return handle_openmp_node(root, "ompCancellationPointDirective", level);
    case MT::ompCriticalDirective:
      return handle_openmp_node(root, "ompCriticalDirective", level);
    case MT::ompDepobjDirective:
      return handle_openmp_node(root, "ompDepobjDirective", level);
    case MT::ompDispatchDirective:
      return handle_openmp_node(root, "ompDispatchDirective", level);
    case MT::ompErrorDirective:
      return handle_openmp_node(root, "ompErrorDirective", level);
    case MT::ompFlushDirective:
      return handle_openmp_node(root, "ompFlushDirective", level);
    case MT::ompInteropDirective:
      return handle_openmp_node(root, "ompInteropDirective", level);
    case MT::ompMaskedDirective:
      return handle_openmp_node(root, "ompMaskedDirective", level);
    case MT::ompMasterDirective:
      return handle_openmp_node(root, "ompMasterDirective", level);
    case MT::ompMetaDirective:
      return handle_openmp_node(root, "ompMetaDirective", level);
    case MT::ompOrderedDirective:
      return handle_openmp_node(root, "ompOrderedDirective", level);
    case MT::ompParallelDirective:
      return handle_openmp_node(root, "ompParallelDirective", level);
    case MT::ompParallelMaskedDirective:
      return handle_openmp_node(root, "ompParallelMaskedDirective", level);
    case MT::ompParallelMasterDirective:
      return handle_openmp_node(root, "ompParallelMasterDirective", level);
    case MT::ompParallelSectionsDirective:
      return handle_openmp_node(root, "ompParallelSectionsDirective", level);
    case MT::ompScanDirective:
      return handle_openmp_node(root, "ompScanDirective", level);
    case MT::ompSectionDirective:
      return handle_openmp_node(root, "ompSectionDirective", level);
    case MT::ompSectionsDirective:
      return handle_openmp_node(root, "ompSectionsDirective", level);
    case MT::ompSingleDirective:
      return handle_openmp_node(root, "ompSingleDirective", level);
    case MT::ompTargetDataDirective:
      return handle_openmp_node(root, "ompTargetDataDirective", level);
    case MT::ompTargetDirective:
      return handle_openmp_node(root, "ompTargetDirective", level);
    case MT::ompTargetEnterDataDirective:
      return handle_openmp_node(root, "ompTargetEnterDataDirective", level);
    case MT::ompTargetExitDataDirective:
      return handle_openmp_node(root, "ompTargetExitDataDirective", level);
    case MT::ompTargetParallelDirective:
      return handle_openmp_node(root, "ompTargetParallelDirective", level);
    case MT::ompTargetTeamsDirective:
      return handle_openmp_node(root, "ompTargetTeamsDirective", level);
    case MT::ompTargetUpdateDirective:
      return handle_openmp_node(root, "ompTargetUpdateDirective", level);
    case MT::ompTaskDirective:
      return handle_openmp_node(root, "ompTaskDirective", level);
    case MT::ompTaskgroupDirective:
      return handle_openmp_node(root, "ompTaskgroupDirective", level);
    case MT::ompTaskwaitDirective:
      return handle_openmp_node(root, "ompTaskwaitDirective", level);
    case MT::ompTaskyieldDirective:
      return handle_openmp_node(root, "ompTaskyieldDirective", level);
    case MT::ompTeamsDirective:
      return handle_openmp_node(root, "ompTeamsDirective", level);
    case MT::ompDistributeDirective:
      return handle_openmp_node(root, "ompDistributeDirective", level);
    case MT::ompDistributeParallelForDirective:
      return handle_openmp_node(root, "ompDistributeParallelForDirective", level);
    case MT::ompDistributeParallelForSimdDirective:
      return handle_openmp_node(root, "ompDistributeParallelForSimdDirective", level);
    case MT::ompDistributeSimdDirective:
      return handle_openmp_node(root, "ompDistributeSimdDirective", level);
    case MT::ompForDirective:
      return handle_openmp_node(root, "ompForDirective", level);
    case MT::ompForSimdDirective:
      return handle_openmp_node(root, "ompForSimdDirective", level);
    case MT::ompGenericLoopDirective:
      return handle_openmp_node(root, "ompGenericLoopDirective", level);
    case MT::ompMaskedTaskLoopDirective:
      return handle_openmp_node(root, "ompMaskedTaskLoopDirective", level);
    case MT::ompMaskedTaskLoopSimdDirective:
      return handle_openmp_node(root, "ompMaskedTaskLoopSimdDirective", level);
    case MT::ompMasterTaskLoopDirective:
      return handle_openmp_node(root, "ompMasterTaskLoopDirective", level);
    case MT::ompMasterTaskLoopSimdDirective:
      return handle_openmp_node(root, "ompMasterTaskLoopSimdDirective", level);
    case MT::ompParallelForDirective:
      return handle_openmp_node(root, "ompParallelForDirective", level);
    case MT::ompParallelForSimdDirective:
      return handle_openmp_node(root, "ompParallelForSimdDirective", level);
    case MT::ompParallelGenericLoopDirective:
      return handle_openmp_node(root, "ompParallelGenericLoopDirective", level);
    case MT::ompParallelMaskedTaskLoopDirective:
      return handle_openmp_node(root, "ompParallelMaskedTaskLoopDirective", level);
    case MT::ompParallelMaskedTaskLoopSimdDirective:
      return handle_openmp_node(root, "ompParallelMaskedTaskLoopSimdDirective", level);
    case MT::ompParallelMasterTaskLoopDirective:
      return handle_openmp_node(root, "ompParallelMasterTaskLoopDirective", level);
    case MT::ompParallelMasterTaskLoopSimdDirective:
      return handle_openmp_node(root, "ompParallelMasterTaskLoopSimdDirective", level);
    case MT::ompSimdDirective:
      return handle_openmp_node(root, "ompSimdDirective", level);
    case MT::ompTargetParallelForDirective:
      return handle_openmp_node(root, "ompTargetParallelForDirective", level);
    case MT::ompTargetParallelForSimdDirective:
      return handle_openmp_node(root, "ompTargetParallelForSimdDirective", level);
    case MT::ompTargetParallelGenericLoopDirective:
      return handle_openmp_node(root, "ompTargetParallelGenericLoopDirective", level);
    case MT::ompTargetSimdDirective:
      return handle_openmp_node(root, "ompTargetSimdDirective", level);
    case MT::ompTargetTeamsDistributeDirective:
      return handle_openmp_node(root, "ompTargetTeamsDistributeDirective", level);
    case MT::ompTargetTeamsDistributeParallelForDirective:
      return handle_openmp_node(root, "ompTargetTeamsDistributeParallelForDirective", level);
    case MT::ompTargetTeamsDistributeParallelForSimdDirective:
      return handle_openmp_node(root, "ompTargetTeamsDistributeParallelForSimdDirective", level);
    case MT::ompTargetTeamsDistributeSimdDirective:
      return handle_openmp_node(root, "ompTargetTeamsDistributeSimdDirective", level);
    case MT::ompTargetTeamsGenericLoopDirective:
      return handle_openmp_node(root, "ompTargetTeamsGenericLoopDirective", level);
    case MT::ompTaskLoopDirective:
      return handle_openmp_node(root, "ompTaskLoopDirective", level);
    case MT::ompTaskLoopSimdDirective:
      return handle_openmp_node(root, "ompTaskLoopSimdDirective", level);
    case MT::ompTeamsDistributeDirective:
      return handle_openmp_node(root, "ompTeamsDistributeDirective", level);
    case MT::ompTeamsDistributeParallelForDirective:
      return handle_openmp_node(root, "ompTeamsDistributeParallelForDirective", level);
    case MT::ompTeamsDistributeParallelForSimdDirective:
      return handle_openmp_node(root, "ompTeamsDistributeParallelForSimdDirective", level);
    case MT::ompTeamsDistributeSimdDirective:
      return handle_openmp_node(root, "ompTeamsDistributeSimdDirective", level);
    case MT::ompTeamsGenericLoopDirective:
      return handle_openmp_node(root, "ompTeamsGenericLoopDirective", level);
    case MT::ompTileDirective:
      return handle_openmp_node(root, "ompTileDirective", level);
    case MT::ompUnrollDirective:
      return handle_openmp_node(root, "ompUnrollDirective", level);
    case MT::ompReductionClause:
      return handle_bindable_node(root, "ompReductionClause", level);
    case MT::parenExpr:
      return handle_bindable_node(root, "parenExpr", level);
    case MT::parenListExpr:
      return handle_bindable_node(root, "parenListExpr", level);
    case MT::parmVarDecl:
      return handle_bindable_node(root, "parmVarDecl", level);
    case MT::pointerType:
      return handle_bindable_node(root, "pointerType", level);
    case MT::pointee:
      return handle_bindable_node(root, "pointee", level);
    case MT::returnStmt:
      return handle_bindable_node(root, "returnStmt", level);
    case MT::to:
      return handle_non_bindable_node(root, "to", level);
    case MT::type:
      return handle_bindable_node(root, "type", level);
    case MT::unaryExprOrTypeTraitExpr:
      return handle_bindable_node(root, "unaryExprOrTypeTraitExpr", level);
    case MT::unaryOperator:
      return handle_unaryOperator(root, level);
    case MT::unresolvedLookupExpr:
      return handle_bindable_node(root, "unresolvedLookupExpr", level);
    case MT::valueDecl:
      return handle_bindable_node(root, "valueDecl", level);
    case MT::varDecl:
      return handle_bindable_node(root, "varDecl", level);
    default:
      printf("ERROR: unimplemented matcher type %d\n", (int) root->matcher_type);
      return VariantMatcher();
  }
}

}
} //namespaces
