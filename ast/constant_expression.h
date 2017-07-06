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

class ConstantExpression : public Expression {
  public:
    ConstantExpression(const Location::Range& r,
      const std::string &name, bool hadBackslash,
      const std::string &doc = "") : Expression(r),
      m_name{name}, m_docComment{doc} {
    }
    const std::string& getName() {
      return m_name;
    }
    bool isScalar() const {
      if (m_name == "INF" || m_name == "NAN") return true;
      auto lower = toLower(m_name);
      return lower == "true" || lower == "false" || lower == "null";
    }
    bool isNull() const {
      return toLower(m_name) == "null";
    }
    bool isBoolean() const {
      auto lower = toLower(m_name);
      return lower == "true" || lower == "false";
    }
    bool isDouble() const {
      return m_name == "INF" || m_name == "NAN";
    }
    void accept(Tap::AstVisitor& v) override {
      v.visit(this);
    }
  private:
    std::string m_name;
    std::string m_docComment;
    
    std::string toLower(const std::string &str) const {
      std::string s(str);
      for (int i = 0 ; s[i] ; ++i)
        if (s[i] >= 'A' && s[i] <= 'Z')
          s[i] += 'a' - 'A';
      return s;
    }
};

}