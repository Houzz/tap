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

/**
 * Remember to keep it immutable.
 *
 * Class Diagram:
 *
 * abstract TapType
 *      |
 *      |-----------------------------------------------------------------------------
 *      |                          |             |              |          |         |
 * abstract SingleTapType    UnionTapType   MixedTapType  AnyTapType  VoidType   UnresolvedType
 *      |
 *      |-----------------------------------
 *      |                   |              |
 *   PrimitiveTapType   CustomTapType    CollectionTapType
 */

namespace Tap {

class TapType {
  public:
    virtual std::string toString() const = 0;
    virtual bool canAccept(const TapType *t) const = 0;
    virtual const TapType* unionType(const TapType *t) const = 0;
    virtual const TapType* substract(const TapType *t) const = 0;
    virtual const TapType* intersect(const TapType *t) const = 0;
    virtual bool equals(const TapType *t) const = 0;
    virtual ~TapType() {}
};
}
