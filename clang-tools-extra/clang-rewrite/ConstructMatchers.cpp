#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchersInternal.h"

#include "clang/ASTMatchers/Dynamic/Registry.h"

#include "ConstructMatchers.h"

#include <vector>

using namespace clang;
using namespace clang::ast_matchers;
using namespace clang::ast_matchers::dynamic;

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


// make matchers for non-bound nodes
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
  printf("made matcher (1) %s\n", MatcherName.str().c_str());
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
  printf("made matcher (2) %s\n", MatcherName.str().c_str());
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
  printf("made matcher (3) %s\n", MatcherName.str().c_str());
  return Out;
}

VariantMatcher constructMatcher(StringRef MatcherName,
                                std::vector<VariantValue> args,
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
  printf("made matcher (4) %s\n", MatcherName.str().c_str());
  return Out;
}


// make matchers for bound nodes
VariantMatcher constructBoundMatcher(StringRef MatcherName,
                                     StringRef BoundName,
                                     Diagnostics *Error = nullptr) {
  Diagnostics DummyError;
  if (!Error) {
    Error = &DummyError;
  }
  llvm::Optional<MatcherCtor> Ctor = R::lookupMatcherCtor(MatcherName);
  VariantMatcher Out;
  if (Ctor) {
    Out = R::constructBoundMatcher(*Ctor, {}, BoundName, Args(), Error);
  }
  printf("made bound matcher (1) %s (%s)\n", MatcherName.str().c_str(), BoundName.str().c_str());
  return Out;
}

VariantMatcher constructBoundMatcher(StringRef MatcherName,
                                     StringRef BoundName,
                                     const VariantValue &Arg1,
                                     Diagnostics *Error = nullptr) {
  Diagnostics DummyError;
  if (!Error) {
    Error = &DummyError;
  }
  llvm::Optional<MatcherCtor> Ctor = R::lookupMatcherCtor(MatcherName);
  VariantMatcher Out;
  if (Ctor) {
    Out = R::constructBoundMatcher(*Ctor, {}, BoundName, Args(Arg1), Error);
  }
  printf("made bound matcher (2) %s (%s)\n", MatcherName.str().c_str(), BoundName.str().c_str());
  return Out;
}

VariantMatcher constructBoundMatcher(StringRef MatcherName,
                                     StringRef BoundName,
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
    Out = R::constructBoundMatcher(*Ctor, {}, BoundName, Args(Arg1, Arg2), Error);
  }
  printf("made bound matcher (3) %s (%s)\n", MatcherName.str().c_str(), BoundName.str().c_str());
  return Out;
}

VariantMatcher constructBoundMatcher(StringRef MatcherName,
                                     StringRef BoundName,
                                     std::vector<VariantValue> args,
                                     Diagnostics* Error = nullptr) {
  Diagnostics DummyError;
  if (!Error) {
    Error = &DummyError;
  }
  llvm::Optional<MatcherCtor> Ctor = R::lookupMatcherCtor(MatcherName);
  VariantMatcher Out;
  if (Ctor) {
    Out = R::constructBoundMatcher(*Ctor, {}, BoundName, Args(args), Error);
  }
  printf("made matcher (4) %s (%s)\n", MatcherName.str().c_str(), BoundName.str().c_str());
  return Out;
}

// mostly copy-paste from handle_bindable_node but need to add hasAnySubstatement
VariantMatcher handle_compoundStmt(Node* root) {
  std::vector<VariantValue> child_matchers;

  if (root->has_type) {
    child_matchers.push_back(constructMatcher("hasType", constructMatcher("asString", StringRef(root->type))));
  }

  if (root->children.size() > 0) {
    for (Node* child : root->children) {
      child_matchers.push_back(constructMatcher("hasAnySubstatement", make_matcher(child)));
    }
  }
  else {
    // guarantee child_matchers.size() >= 1 (also required to not make an
    // ambiguous matcher and actually match things)
    child_matchers.push_back(constructMatcher("anything"));
  }

  if (child_matchers.size() > 1) {
    if (root->ignore_casts) {
      if (root->bound) {
        return constructBoundMatcher("compoundStmt", StringRef(root->bound_name),
                constructMatcher("ignoringParenImpCasts",
                  constructMatcher("allOf", child_matchers)));
      }
      else {
        return constructMatcher("compoundStmt",
                constructMatcher("ignoringParenImpCasts",
                  constructMatcher("allOf", child_matchers)));
      }
    }
    else { // no ignore casts
      if (root->bound) {
        return constructBoundMatcher("compoundStmt", StringRef(root->bound_name),
                constructMatcher("allOf", child_matchers));
      }
      else {
        return constructMatcher("compoundStmt",
                constructMatcher("allOf", child_matchers));
      }
    } // ignore_casts
  }
  else { // child_matchers.size() == 1
    if (root->ignore_casts) {
      if (root->bound) {
        return constructBoundMatcher("compoundStmt", StringRef(root->bound_name),
                constructMatcher("ignoringParenImpCasts", child_matchers[0]));
      }
      else {
        return constructMatcher("compoundStmt",
                constructMatcher("ignoringParenImpCasts", child_matchers[0]));
      }
    }
    else { // no ignore casts
      if (root->bound) {
        return constructBoundMatcher("compoundStmt", StringRef(root->bound_name), child_matchers[0]);
      }
      else {
        return constructMatcher("compoundStmt", child_matchers[0]);
      }
    } // ignore_casts
  } // child_matchers.size()
}

VariantMatcher handle_non_bindable_node(Node* root, StringRef name) {
  std::vector<VariantValue> child_matchers;

  if (root->has_type) {
    child_matchers.push_back(constructMatcher("hasType", constructMatcher("asString", StringRef(root->type))));
  }
  if (root->bound) {
    child_matchers.push_back(constructBoundMatcher("expr", StringRef(root->bound_name)));
  }

  if (root->children.size() > 0) {
    for (Node* child : root->children) {
      child_matchers.push_back(make_matcher(child));
    }
  }
  else {
    // guarantee child_matchers.size() >= 1 (also required to not make an
    // ambiguous matcher and actually match things)
    child_matchers.push_back(constructMatcher("anything"));
  }

  if (child_matchers.size() > 1) {
    if (root->ignore_casts) {
      return constructMatcher(name,
              constructMatcher("ignoringParenImpCasts",
                constructMatcher("allOf", child_matchers)));
    }
    else {
      return constructMatcher(name,
              constructMatcher("allOf", child_matchers));
    }
  } // child_matchers.size() > 1
  else { // child_matchers.size() == 1
    if (root->ignore_casts) {
      return constructMatcher(name,
              constructMatcher("ignoringParenImpCasts", child_matchers[0]));
    }
    else {
      return constructMatcher(name, child_matchers[0]);
    }
  } // child_matchers.size()
}

VariantMatcher handle_bindable_node(Node* root, StringRef name) {
  std::vector<VariantValue> child_matchers;

  if (root->has_type) {
    child_matchers.push_back(constructMatcher("hasType", constructMatcher("asString", StringRef(root->type))));
  }

  if (root->children.size() > 0) {
    for (Node* child : root->children) {
      child_matchers.push_back(make_matcher(child));
    }
  }
  else {
    // guarantee child_matchers.size() >= 1 (also required to not make an
    // ambiguous matcher and actually match things)
    child_matchers.push_back(constructMatcher("anything"));
  }

  if (child_matchers.size() > 1) {
    if (root->ignore_casts) {
      if (root->bound) {
        return constructBoundMatcher(name, StringRef(root->bound_name),
                constructMatcher("ignoringParenImpCasts",
                  constructMatcher("allOf", child_matchers)));
      }
      else {
        return constructMatcher(name,
                constructMatcher("ignoringParenImpCasts",
                  constructMatcher("allOf", child_matchers)));
      }
    }
    else { // no ignore casts
      if (root->bound) {
        return constructBoundMatcher(name, StringRef(root->bound_name),
                constructMatcher("allOf", child_matchers));
      }
      else {
        return constructMatcher(name,
                constructMatcher("allOf", child_matchers));
      }
    } // ignore_casts
  }
  else { // child_matchers.size() == 1
    if (root->ignore_casts) {
      if (root->bound) {
        return constructBoundMatcher(name, StringRef(root->bound_name),
                constructMatcher("ignoringParenImpCasts", child_matchers[0]));
      }
      else {
        return constructMatcher(name,
                constructMatcher("ignoringParenImpCasts", child_matchers[0]));
      }
    }
    else { // no ignore casts
      if (root->bound) {
        return constructBoundMatcher(name, StringRef(root->bound_name), child_matchers[0]);
      }
      else {
        return constructMatcher(name, child_matchers[0]);
      }
    } // ignore_casts
  } // child_matchers.size()
}

VariantMatcher make_matcher(Node* root) {
  std::vector<VariantValue> child_matchers;
  switch(root->matcher_type) {
    case MT::compoundStmt:
      return handle_compoundStmt(root);
      break;
    case MT::returnStmt:
      return handle_bindable_node(root, "returnStmt");
      break;
    case MT::hasReturnValue:
      return handle_non_bindable_node(root, "hasReturnValue");
      break;
    // case MT::declRefExpr: //TODO: make to() its own node and figure out literals
    //   child_matchers.clear();
    //   if (root->children.size() > 1) {
    //     for (Node* child : root->children) {
    //       child_matchers.push_back(make_matcher(child));
    //     }
    //     return constructMatcher("declRefExpr",
    //             constructMatcher("allOf", child_matchers));
    //   }
    //   else if (root->children.size() == 1) {
    //     return constructMatcher("declRefExpr", make_matcher(root->children[0]));
    //   }
    //   else {
    //     return constructMatcher("declRefExpr", constructMatcher("anything"));
    //   }
      break;
    default:
      printf("ERROR: unimplemented matcher type %d\n", (int) root->matcher_type);
      return VariantMatcher();
      break;
  }
}
