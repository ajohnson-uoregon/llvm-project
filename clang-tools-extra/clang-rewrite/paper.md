---
title: "MARTINI: The Little Match and Replace Tool for Automatic Code Rewriting"
tags:
  - Clang
  - meteprogramming
  - refactoring
  - AST matchers
authors:
  - name: Alister Johnson
    affiliation: 1
affiliations:
  - name: University of Oregon, Eugene, OR, USA
    index: 1
date: 30 June 2022
bibliography: cite.bib

---

# Summary

Rewriting code for cleanliness, API changes, and new programming models is a
common, yet time-consuming task. Localized or syntax-based changes are often
mechanical and can be automated with text-based rewriting tools, like Unix's
`sed`. However, non-localized or semantic-based changes require specialized
tools that usually come with complex, hard-coded rules that require expertise
in compilers. This means techniques for source rewriting are either too
simple for complex tasks or too complex to be customized by non-expert users;
in either case, developers are often forced to manually update their code
instead.

This work presents MARTINI, a new approach to code rewriting built on the
Clang compiler, which exposes complex and semantic-driven rewrite capabilities
to users in a simple and natural way. Rewrite rules are expressed as a pair
of parameterized "before-and-after" snippets in the source language, one
to describe what to match and one to describe what the replacement looks like.
Through this novel and user-friendly interface, programmers can automate
and customize complex code changes which require a deep understanding of
the language without any knowledge of compiler internals.

---

# Statement of Need

---

# References
