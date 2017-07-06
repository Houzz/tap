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

#include "expression.h"

namespace HPHP {

class FunctionCall : public Expression {
  public:
    FunctionCall(const Location::Range& r, ExpressionPtr nameExp,
      const std::string& name, bool hadBackslash,
      ExpressionListPtr params, ExpressionPtr classExp) :
      Expression(r), nameExp{nameExp}, name{name}, hadBackslash{hadBackslash},
      params{params}, classExp{classExp} {}
    
    const std::string& getName() {return name;}
    ExpressionPtr getNameExp() {return nameExp;}
    ExpressionListPtr getParams() {return params;}
    ExpressionPtr getClassExp() {return classExp;}
    
  protected:
    ExpressionPtr nameExp;
    std::string name;
    bool hadBackslash;
    ExpressionListPtr params;
    ExpressionPtr classExp;
};

}