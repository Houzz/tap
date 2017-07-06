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

#include "function_call.h"

namespace HPHP {

class ObjectMethodExpression : public FunctionCall {
  public:
    ObjectMethodExpression(const Location::Range &r, ExpressionPtr object,
      ExpressionPtr method, ExpressionListPtr params, bool nullSafe)
      : FunctionCall(r, method, "", false, params, ExpressionPtr()),
        m_object{object}, m_nullSafe{nullSafe} {}
    
    ExpressionPtr getObject() {return m_object;}
    
    void accept(Tap::AstVisitor &v) {
      if (nameExp) nameExp->accept(v);
      if (params) params->accept(v);
      if (m_object) m_object->accept(v);
      v.visit(this);
    }
  private:
    ExpressionPtr m_object;
    bool m_nullSafe;
};

}