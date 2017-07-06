/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-present Facebook, Inc. (http://www.facebook.com)  |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/
/*
   +------------------------------------------+
   | Type Analyzer for PHP                    |
   | Modified work Copyright 2017 Houzz, Inc  |
   +------------------------------------------+
*/

#pragma once

#include <string>
#include "expression.h"

namespace HPHP {

class ClassConstantExpression : public Expression {
  public:
    ClassConstantExpression(const Location::Range& r,
      ExpressionPtr classExp, const std::string& varName)
      : Expression(r), m_classExp{classExp}, m_varName{varName} {}
    
    const std::string& getVarName() {return m_varName;}
    ExpressionPtr getClassExp() {return m_classExp;}
    
    void accept(Tap::AstVisitor& v) {
      v.visit(this);
    }
  private:
    ExpressionPtr m_classExp;
    std::string m_varName;
};

}
