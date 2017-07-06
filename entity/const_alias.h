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

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "parser/location.h"
#include "ast/ast_decls.h"
#include "visitor/name_table.h"
namespace Tap {

class TapType;

class ConstAlias {
  public:
    static ConstAlias& getInstance() {
      static ConstAlias instance;
      return instance;
    }
    
    // simple case like `const CONST_A = self::CONST_B`
    void addDependency(
      const std::string& lhsName,
      const std::string& rhsName,
      const HPHP::Location::Range& r);
      
    // complicated case like `static $a = array(self::CONST_A, self::CONST_B)`
    void addDependency(
      const std::string& lhsName,
      const std::unordered_set<std::string>& rhsNames,
      HPHP::ExpressionPtr exp,
      const HPHP::Location::Range& r);

    void resolve();
  
  private:
    struct DependencyMapValue {
      std::string name;
      HPHP::Location::Range range;
      DependencyMapValue(const std::string& name,
                         const HPHP::Location::Range &range)
                        : name{name}, range{range} {}
    };
    
    std::unordered_map<std::string, std::vector<std::string>> m_dep;
    std::unordered_map<std::string, HPHP::Location::Range> m_ranges;
    std::unordered_map<std::string, HPHP::ExpressionPtr> m_rhsExps;
    std::vector<std::shared_ptr<NameTable>> m_nameTableStack;
    
    ConstAlias() {}
};

}