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

#pragma once 

#include "type/tap_type.h"
#include "type/single_tap_type.h"
#include "type/any_tap_type.h"
#include <unordered_map>

namespace Tap {

class PrimitiveTapType : public SingleTapType {
  public:
    enum TypeEnum {
        NULL_TYPE,
        INTEGER_TYPE,
        FLOAT_TYPE,
        STRING_TYPE,
        BOOL_TYPE,
        IMPOSSIBLE_TYPE
    };
    
    static PrimitiveTapType* valueOf(int type) {
      return instances[type];
    }
    
    PrimitiveTapType(int type) : m_type(type) {}
    
    int getType() {return m_type;}
    
    bool equals(const TapType *t) const override {
      const PrimitiveTapType *pt = dynamic_cast<const PrimitiveTapType*>(t);
      return pt && m_type == pt->m_type;
    }
    
    std::string toString() const override {
      switch (m_type) {
        case NULL_TYPE:
          return "null";
        case INTEGER_TYPE:
          return "int";
        case FLOAT_TYPE:
          return "float";
        case STRING_TYPE:
          return "string";
        case BOOL_TYPE:
          return "bool";
        case IMPOSSIBLE_TYPE:
          return "impossible";
      }
      return "error";
    }
    
    bool canAccept(const TapType *t) const override {
      if (dynamic_cast<const AnyTapType*>(t))
        return true;
      const PrimitiveTapType* pt = dynamic_cast<const PrimitiveTapType*>(t);
      if (pt) {
        if (m_type == PrimitiveTapType::FLOAT_TYPE && pt->m_type == PrimitiveTapType::INTEGER_TYPE)
          return true;  // float parameter can accept int
        if (m_type == pt->m_type)
          return true;
      }
      return false;
    }
    
  private:
    int m_type;
    static std::unordered_map<int, PrimitiveTapType*> instances;
};

}
