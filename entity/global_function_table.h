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
#include <unordered_map>
#include "util/error_collector.h"
#include "function.h"

namespace Tap {

class GlobalFunctionTable {
  public:
    static GlobalFunctionTable& getInstance();
    
    bool addPlainFunction(const std::string &name, std::shared_ptr<Function> func, bool ignoreDup = false) {
      if (funcTable.find(name) != funcTable.end()) {
        if (!ignoreDup) {
          ErrorCollector::getInstance().emitError(
            ErrorCollector::E_DUPLICATED_FUNCTION, "duplicaed function", func->getRange());
        }
        return false;
      }
      funcTable.insert(std::make_pair(name, func));
      return true;
    }
  
    std::shared_ptr<Function> getPlainFunction(const std::string& name) const {
      auto itr = funcTable.find(name);
      if (itr != funcTable.end()) {
        return itr->second;
      }
      return nullptr;
    }
    
    bool hasPlainFunction(const std::string& name) const {
      return funcTable.find(name) != funcTable.end();
    }
    
  private:
    GlobalFunctionTable();
    
    std::unordered_map<std::string, std::shared_ptr<Function>> funcTable;
};

}

