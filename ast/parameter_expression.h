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

#ifndef TAP_PARAMETER_EXPRESSION_H
#define TAP_PARAMETER_EXPRESSION_H

#include <string>
#include "type/tap_type.h"
#include "visitor/ast_visitor.h"

namespace HPHP {

class ParameterExpression : public Expression {
  public:
    ParameterExpression(const Location::Range& r, Tap::TapType *param_type,
      std::string name, bool ref, ExpressionPtr defValue) :
      Expression(r), m_type(param_type), m_name(name),
      m_ref{ref}, m_defValue{defValue} {}
    
    const std::string& getName() {return m_name;}
    const Tap::TapType* getType() {return m_type;}
    ExpressionPtr getDefValue() {return m_defValue;}
    bool isRef() {return m_ref;}
    
    void accept(Tap::AstVisitor& v) {
      if (m_defValue) m_defValue->accept(v);
      v.visit(this);
    }
  private:
    Tap::TapType *m_type;
    std::string m_name;
    bool m_ref;
    ExpressionPtr m_defValue;
    // TODO: modifier
};

}

#endif