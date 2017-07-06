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

#include "method_statement.h"

namespace HPHP {

class FunctionStatement : public MethodStatement {
  public:
    FunctionStatement(const Location::Range& r,
                    ModifierExpressionPtr modifiers, bool ref,
                    const std::string &name, ExpressionListPtr params,
                    Tap::TapType* retTypeAnnotation,
                    StatementListPtr stmt, int attr,
                    const std::string &docComment,
                    ExpressionListPtr attrList) :
        MethodStatement(r, modifiers, ref, name, params, retTypeAnnotation,
          stmt, attr, docComment, attrList, false) {}
    
    SIMPLE_VISIT_METHOD
    
    void accept(Tap::AstVisitor& v) override;
};

}