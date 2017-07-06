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

#include <vector>
#include "expression.h"

namespace HPHP {
  
class ModifierExpression : public Expression {
  public:
    ModifierExpression(const Location::Range& r)
      : Expression(r) {}
    void add(int modifier) {
      modifiers.push_back(modifier);
    }
    void accept(Tap::AstVisitor& v) override {
      v.visit(this);
    }
    bool isPublic() const;
    bool isProtected() const;
    bool isPrivate() const;
    bool isStatic() const;
    bool hasModifier(int modifier) const;
    // TODO(liang): final, abstract
  private:
    std::vector<int> modifiers;
};

}