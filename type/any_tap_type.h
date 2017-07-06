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

#include "tap_type.h"
#include <string>

namespace Tap {

/*
Note the difference between "any" and "mixed":
  A function with parameter type AnyTapType can accept any type.
  A function with any parameter type can accept AnyTapType.
  A function with parameter type MixedTapType can accept any type.
  A function with any parameter type except MixedTapType CANNOT accept MixedTapType.
*/

class AnyTapType : public TapType {
  public:
    static AnyTapType* getInstance() {
      static AnyTapType instance;
      return &instance;
    }
    
    ~AnyTapType() {}
    
    std::string toString() const override {
      return "any";
    }
    
    bool canAccept(const TapType *t) const override {
      return true;
    }
    
    const TapType* unionType(const TapType *t) const override {
      return this;
    }

    const TapType* substract(const TapType *t) const override {
      return this;
    }

    const TapType* intersect(const TapType *t) const override {
      return const_cast<TapType*>(t);
    }

    bool equals(const TapType *t) const override {
      return t == this;
    }
  private:
    AnyTapType() {}
};

}

