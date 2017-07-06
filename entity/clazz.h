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

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <glog/logging.h>

#include "entity/function.h"
#include "entity/property.h"
#include "entity/const.h"
#include "parser/location.h"

namespace Tap {

class Clazz {
  public:
    enum Status {
      UNEXPANDED,
      EXPANDING,
      EXPANDED
    };
    
    Clazz(const std::string& name, const HPHP::Location::Range& range)
      : fqName{name}, range{range}, m_status{UNEXPANDED} {}
      
    void addMethod(std::string name, std::shared_ptr<Function> method);
    void addProperty(std::string name, std::shared_ptr<Property> property);
    void addConst(std::string name, std::shared_ptr<Const> constEntity);
    void updatePropertyType(const std::string& name, TapType* type);
    const std::string& getName() {return fqName;}
    const HPHP::Location::Range& getRange() {return range;}
    
    std::shared_ptr<Const> getConst(const std::string& name, const std::string& curClass = "") {
      auto res = consts.find(name);
      if (res != consts.end()) return res->second;
      return nullptr;
    }
    std::shared_ptr<Function> getMethod(const std::string& name, const std::string& curClass = "");
    std::shared_ptr<Property> getProperty(const std::string& name, const std::string& curClass = "");
    
    void addParent(const std::string& parent) {
      parents.insert(parent);
    }
    void setExtends(const std::string& parent) {
      m_extends = parent;
    }
    
    std::string getExtends() {
      return m_extends;
    }
    
    void expand();
  private:
    bool isVisible(VisibilityEnum visibility, const std::string& curClass);
    
    std::string fqName;
    HPHP::Location::Range range;
    std::unordered_map<std::string, std::shared_ptr<Function>> methods;
    std::unordered_map<std::string, std::shared_ptr<Property>> properties;
    std::unordered_map<std::string, std::shared_ptr<Const>> consts;
    
    Status m_status;
    std::unordered_set<std::string> parents;
    
    // php doesn't allow multiple inheritance, that is the single parent
    std::string m_extends;
    
    void inheriteFromParent(std::shared_ptr<Clazz> parentClass);
};

}