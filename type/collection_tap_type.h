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

#include <vector>
#include "single_tap_type.h"

namespace Tap {

class CollectionTapType : public SingleTapType {
  public:
    enum CollectionTypeEnum {
      ARRAY,
      VECTOR,
      MAP,
      TUPLE
    };
    
    CollectionTapType(CollectionTypeEnum t) : m_collectionType{t} {}
    
    static CollectionTapType* getArrayTypeInstance() {
      static CollectionTapType arrayTypeInstance{CollectionTapType::ARRAY};
      return &arrayTypeInstance;
    }
    
    // TODO: memory leak
    static CollectionTapType* getVectorTypeInstance(TapType* elemType) {
      CollectionTapType* result = new CollectionTapType{CollectionTapType::VECTOR};
      result->addTypeParam(elemType);
      return result;
    }
    
    // TODO: memory leak
    static CollectionTapType* getMapTypeInstance(TapType* keyType, TapType* valueType) {
      CollectionTapType* result = new CollectionTapType{CollectionTapType::MAP};
      result->addTypeParam(keyType);
      result->addTypeParam(valueType);
      return result;
    }
    
    static CollectionTapType* getTupleTypeInstance(std::vector<TapType*> tupleSubTypes) {
      CollectionTapType* result = new CollectionTapType{CollectionTapType::TUPLE};
      for (auto t : tupleSubTypes)
        result->addTypeParam(t);
      return result;
    }
    
    void addTypeParam(TapType *t) {
      m_typeParams.push_back(t);
    }
    
    std::string toString() const override;
    bool canAccept(const TapType *t) const override;
    bool equals(const TapType *t) const override;
    CollectionTypeEnum getCollectionType() const {
      return m_collectionType;
    }
    TapType* getTypeParam(int idx) {
      return m_typeParams[idx];
    }
    std::vector<TapType*> getTypeParams() {
      return m_typeParams;
    }
    int getTypeParamCount() {
      return m_typeParams.size();
    }
  private:
    CollectionTypeEnum m_collectionType;
    // TODO: shared_ptr?
    std::vector<TapType*> m_typeParams;
};

}

