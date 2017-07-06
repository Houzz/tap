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
#include <glog/logging.h>
#include "type/tap_type.h"

namespace Tap {

class UnresolvedType : public TapType {
  public:
    UnresolvedType(const std::string &name) : m_name(name) {}
    std::string getName() {return m_name;}
    
    bool equals(const TapType *t) const override {
      if (auto ut = dynamic_cast<const UnresolvedType*>(t)) {
        return ut->m_name == m_name;
      }
      return false;
    }
    
    std::string toString() const override {
      return "UnresolvedType";
    }
    bool canAccept(const TapType *t) const override {
      logError();
      return false;
    }
    const TapType* unionType(const TapType *t) const override {
      logError();
      return nullptr;
    }
    const TapType* substract(const TapType *t) const override {
      logError();
      return nullptr;
    }
    const TapType* intersect(const TapType *t) const override {
      logError();
      return nullptr;
    }
    
  private:
    void logError() const {
      LOG(FATAL) << "Unsupported operations onto unresolved type";
    }
    std::string m_name;
};

}