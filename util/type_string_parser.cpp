/*
Copyright 2017 Houzz, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "type_string_parser.h"

#include <vector>
#include <string>
#include <exception>
#include <glog/logging.h>
#include "type/primitive_tap_type.h"
#include "type/single_tap_type.h"
#include "type/union_tap_type.h"
#include "type/void_tap_type.h"
#include "type/mixed_tap_type.h"
#include "type/any_tap_type.h"
#include "type/custom_tap_type.h"
#include "type/collection_tap_type.h"
#include "parser/parser_exception.h"
using namespace std;

inline static bool isValidNameChar(char ch) {
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9') ||
           ch == '_' || ch == '\\';
}

namespace Tap {

TapType* TypeStringParser::parse() {
  getNextToken();
  if (m_next[0] == '$') {
    LOG(WARNING) << "No type specified, only param name found: {" << m_str << "}";
    m_p -= m_next.length();
    return nullptr;
  }
  TapType *t = parseTokenType();
  if (m_next.size()) {
    if (m_next != "|") {
      m_p -= m_next.length();
      return t;
    }
    std::vector<const SingleTapType*> types;
    auto ut = dynamic_cast<const SingleTapType*>(t);
    if (!ut) {
      string msg = t->toString() + " shouldn't union with others";
      throw ParserException(msg);
    }
    types.push_back(ut);
    while (m_next.size()) {
      // expect("|");
      if (m_next == "|") {
        getNextToken();
      } else {
        m_p -= m_next.length();
        break;
      }

      t = parseTokenType();
      auto ut = dynamic_cast<const SingleTapType*>(t);
      if (!ut) {
        string msg = t->toString() + " shouldn't union with others";
        throw ParserException(msg);
      }
      types.push_back(ut);
    }
    if (types.size() <= 1) {
      LOG(WARNING) << "We think it should be union type, something seems wrong. {" << m_str << "}";
    }
    return new UnionTapType(types);
  } else {
    return t;
  }
}

TapType* TypeStringParser::parseTokenType() {
  // TODO: parse like int[]
  TapType* t = parseSingleTokenType();
  while (m_next == "[") {
    expect("[");
    expect("]");
    t = CollectionTapType::getVectorTypeInstance(t);
  }
  return t;
}

TapType* TypeStringParser::parseSingleTokenType() {
  // TODO: to lower case
  if (m_next == "vector") {
    getNextToken();
    expect("<");
    TapType* t = parseSingleTokenType();
    expect(">");
    return CollectionTapType::getVectorTypeInstance(t);
  } else if (m_next == "map") {
    getNextToken();
    expect("<");
    TapType* keyType = parseSingleTokenType();
    expect(",");
    TapType* valueType = parseSingleTokenType();
    expect(">");
    return CollectionTapType::getMapTypeInstance(keyType, valueType);
  } else if (m_next == "tuple") {
    getNextToken();
    expect("<");
    vector<TapType*> tupleTypes;
    while (true) {
      TapType *t = parseSingleTokenType();
      tupleTypes.push_back(t);
      if (m_next != ",") break;
      expect(",");
    }
    expect(">");
    return CollectionTapType::getTupleTypeInstance(tupleTypes);
  } else if (m_next == "int" || m_next == "integer") {
    getNextToken();
    return PrimitiveTapType::valueOf(PrimitiveTapType::INTEGER_TYPE);
  } else if (m_next == "bool" || m_next == "boolean") {
    getNextToken();
    return PrimitiveTapType::valueOf(PrimitiveTapType::BOOL_TYPE);
  } else if (m_next == "string") {
    getNextToken();
    return PrimitiveTapType::valueOf(PrimitiveTapType::STRING_TYPE);
  } else if (m_next == "float" || m_next == "double") {
    getNextToken();
    return PrimitiveTapType::valueOf(PrimitiveTapType::FLOAT_TYPE);
  } else if (m_next == "null") {
    getNextToken();
    return PrimitiveTapType::valueOf(PrimitiveTapType::NULL_TYPE);
  } else if (m_next == "mixed") {
    getNextToken();
    return MixedTapType::getInstance();
  } else if (m_next == "any") {
    getNextToken();
    return AnyTapType::getInstance();
  } else if (m_next == "void") {
    getNextToken();
    return VoidTapType::getInstance();
  } else if (m_next == "array") {
    getNextToken();
    return CollectionTapType::getArrayTypeInstance();
  } else {
    string token = m_next;
    getNextToken();
    // TODO: how to handle relative namespace?
    return CustomTapType::valueOf(token);
  }
  return nullptr;
}

std::string TypeStringParser::getNextToken() {
  std::string nextToken;
  
  while (m_str[m_p] && (m_str[m_p] == ' ' || m_str[m_p] == '\n'))
    ++m_p;
  
  if (!m_str[m_p]) {m_next = nextToken; return nextToken;}
  char ch = m_str[m_p++];
  
  nextToken.push_back(ch);
  if (isValidNameChar(ch)) {
    while (m_str[m_p] && isValidNameChar(m_str[m_p])) {
      nextToken.push_back(m_str[m_p++]);
    }
  }
  
  m_next = nextToken;
  return nextToken;
}

void TypeStringParser::expect(const std::string &s) {
  if (m_next != s) {
    string msg = "Expect " + s + " but got " + m_next;
    throw ParserException(msg);
  }
  getNextToken();
}

}