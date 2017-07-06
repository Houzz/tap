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
#include "visitor/ast_visitor.h"

namespace HPHP {

class ScalarExpression : public Expression {
  public:
    ScalarExpression(const Location::Range& r, int type, const std::string &value, bool quoted = false)
      : Expression(r), scalarType{type}, value{value}, quoted{quoted} {}
    ScalarExpression(const Location::Range& r, int type, const std::string &value,
      const std::string translated, bool quoted = false)
      : Expression(r), scalarType(type), value(value), translated{translated}, quoted{quoted} {}
    const std::string& getString() {return value;}
    int getScalarType() {return scalarType;}
    void accept(Tap::AstVisitor& v) {
      v.visit(this);
    }
  private:
    int scalarType;
    std::string value;
    std::string translated;
    bool quoted;
};

}