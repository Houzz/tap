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
#include "single_tap_type.h"
#include "any_tap_type.h"

namespace Tap {

class CustomTapType : public SingleTapType {
  public:
    static CustomTapType* valueOf(const std::string& name) {
      auto itr = cache.find(name);
      if (itr != cache.end()) return itr->second;
      return cache[name] = new CustomTapType(name);
    }

    bool equals(const TapType *t) const override {
      return t == this;
    }
    
    bool canAccept(const TapType *t) const override;

    std::string toString() const override {
      return typeName;
    }
    
  private:
    static std::unordered_map<std::string, CustomTapType*> cache;

    CustomTapType(const std::string &name) : typeName(name) {}
    std::string typeName;
};

}

