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
#include <vector>

namespace Tap {

class SingleTapType;

class UnionTapType : public TapType {
public:
  UnionTapType(UnionTapType* t) {
    singleTapTypes = t->singleTapTypes;
  }
  
  UnionTapType(std::vector<const SingleTapType*> types) : singleTapTypes(types) {}
  
  const UnionTapType* addType(const SingleTapType* newType) const;
  
  bool hasType(const SingleTapType *typeToCheck) const;
  
public:
  virtual bool canAccept(const TapType* t) const;
  virtual bool equals(const TapType* t) const;
  virtual const TapType* intersect(const TapType* t) const;
  virtual const TapType* substract(const TapType* t) const;
  virtual std::string toString() const;
  virtual const TapType* unionType(const TapType* t) const;
  
private:
  std::vector<const SingleTapType*> singleTapTypes;
};

}

