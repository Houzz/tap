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

#include "modifier_expression.h"
#include "parser/hphp.tab.hpp"

namespace HPHP {

bool ModifierExpression::isPublic() const {
  for (auto t : modifiers) {
    switch (t) {
      case T_PUBLIC:
        return true;
      case T_PRIVATE:
      case T_PROTECTED:
        return false;
      default:
        break;
    }
  }
  return true;  // public by default
}

bool ModifierExpression::hasModifier(int modifier) const {
  for (auto t : modifiers) {
    if (t == modifier) return true;
  }
  return false;
}

bool ModifierExpression::isProtected() const {
  return hasModifier(T_PROTECTED);
}

bool ModifierExpression::isPrivate() const {
  return hasModifier(T_PRIVATE);
}

bool ModifierExpression::isStatic() const {
  return hasModifier(T_STATIC);
}

}