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

#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace Tap {

class TapType;

// Immutable
class NameTableValue {
  private:
    const TapType* type;
    bool canUndefined;
  public:
    NameTableValue() : type{nullptr}, canUndefined{false} {}
    NameTableValue(const TapType* type) : type{type}, canUndefined{false} {
    }
    NameTableValue(const TapType* type, bool canUndefined)
      : type{type}, canUndefined{canUndefined} {
      }
    
    const TapType* getType() const {return type;}
    bool canBeUndefined() const {return canUndefined;}
    NameTableValue setCanBeUndefined(bool value) {
      if (canUndefined == value) return *this;
      return NameTableValue{type, value};
    }
    
};

class NameTable {
  public:
    NameTable() {}
    
    NameTableValue queryVariable(const std::string& name);
    int size() {return varTable.size();}
    bool empty() {return varTable.empty();}
    void addVariable(const std::string& name, const TapType* t);
    bool hasVariable(const std::string& name);
    
    void mergeBranch(std::shared_ptr<NameTable> rhs);
    void mergeSequence(const NameTable* rhs);
    void markUndefined();
    void remove(std::shared_ptr<NameTable> rhs);
    void forgetNonLocalVars();
    
    std::string toString();
  private:
    // varTable can contain local variable or object property or static property
    // object property has the format of `$a->prop_x`
    // static property has the format of `ClassA::$static_prop`
    std::unordered_map<std::string, NameTableValue> varTable;
    // We index the non-local variable for faster "forgetting".
    std::unordered_set<std::string> nonLocalVars;
    
};

}
