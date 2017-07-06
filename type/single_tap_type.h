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

#ifndef TAP_TYPE_SINGLE_TAP_TYPE_H
#define TAP_TYPE_SINGLE_TAP_TYPE_H

#include "tap_type.h"

namespace Tap {

class SingleTapType : public TapType {
  public:
    const TapType* unionType(const TapType *t) const override;
    const TapType* substract(const TapType *t) const override;
    const TapType* intersect(const TapType *t) const override;
};

}

#endif