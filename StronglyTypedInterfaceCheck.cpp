//===--- StronglyTypedInterfaceCheck.cpp - clang-tidy----------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "StronglyTypedInterfaceCheck.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace cppcoreguidelines {

void StronglyTypedInterfaceCheck::registerMatchers(MatchFinder *Finder) {  
    auto voidPtr = pointerType(pointee(voidType())) ;
    Finder->addMatcher(functionDecl(anyOf(returns(voidPtr), hasAnyParameter(
          hasType(hasCanonicalType(voidPtr))))).bind("funcDecl"), this);
}

void StronglyTypedInterfaceCheck::check(const MatchFinder::MatchResult &Result) {  
  if ( const auto *MatchedDecl = Result.Nodes.getNodeAs<FunctionDecl>("funcDecl") ){
    diag(MatchedDecl->getLocation(), "Function is weakly typed");
  } 
  
}

} // namespace cppcoreguidelines
} // namespace tidy
} // namespace clang
