//===--- ArrayParamAsPtrCheck.cpp - clang-tidy-----------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "ArrayParamAsPtrCheck.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace cppcoreguidelines {

void ArrayParamAsPtrCheck::registerMatchers(MatchFinder *Finder) {   
  Finder->addMatcher(arraySubscriptExpr(hasBase(hasDescendant(
                    declRefExpr(hasDeclaration(
                    parmVarDecl(hasType(pointerType())).bind("parmVarDecl"))))))
                                               .bind("arraySubExp"), this);
}

void ArrayParamAsPtrCheck::check(const MatchFinder::MatchResult &Result) {  
  if ( const auto *MatchedDecl = Result.Nodes.getNodeAs<ParmVarDecl>("parmVarDecl") ){
    diag(MatchedDecl->getLocStart(), "Array is passed as a single pointer") ;    
  }
}

} // namespace cppcoreguidelines
} // namespace tidy
} // namespace clang
