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

#include "statement.h"

namespace Tap {
  class TapType;
}

namespace HPHP {

class MethodStatement : public Statement {
  public:
    MethodStatement(const Location::Range& r, 
                  ModifierExpressionPtr modifiers, bool ref,
                  const std::string &name, ExpressionListPtr params,
                  Tap::TapType* retTypeAnnotation, StatementListPtr stmt,
                  int attr, const std::string &docComment,
                  ExpressionListPtr attrList, bool method = true) :
        Statement(r),
        m_modifiers{modifiers},
        m_ref{false},
        m_originalName{name},
        m_params{params},
        m_retTypeAnnotation{retTypeAnnotation},
        m_stmt{stmt},
        m_docComment{docComment},
        m_attrList{attrList},
        m_method{method} {}
    void accept(Tap::AstVisitor& v) override;
    
    ModifierExpressionPtr getModifiers() const {
      return m_modifiers;
    }
    const std::string& getDocComment() const {
      return m_docComment;
    }
    const std::string& getName() const {
      return m_originalName;
    }
    ExpressionListPtr getParams() const {
      return m_params;
    }
    StatementListPtr getStmt() const {
      return m_stmt;
    }
    
    SIMPLE_VISIT_METHOD
    
  protected:
    bool m_method;
    bool m_ref;
    bool m_mayCallSetFrameMetadata;
    int m_attribute;
    int m_cppLength;
    int m_autoPropCount;
    ModifierExpressionPtr m_modifiers;
    std::string m_originalName;
    std::string m_originalFilename;
    ExpressionListPtr m_params;
    Tap::TapType* m_retTypeAnnotation;
    StatementListPtr m_stmt;
    std::string m_docComment;
    ExpressionListPtr m_attrList;
};

}