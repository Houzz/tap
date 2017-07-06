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

#include "visitor/name_table.h"
#include "type/tap_type.h"
#include <glog/logging.h>
#include <unordered_set>

using namespace std;

namespace Tap {

void NameTable::addVariable(const std::string& name, const TapType *t) {
  LOG(INFO) << "Add name " << name << " as type " << t->toString();
  if (varTable.find(name) != varTable.end()) {
    LOG(WARNING) << "Put duplicated name " << name << " into name table.";
  }
  varTable[name] = NameTableValue{t};
  // varTable.insert(std::make_pair(name, NameTableValue{t}));
  if (name.find("::") != std::string::npos ||
      name.find("->") != std::string::npos)
        nonLocalVars.insert(name);
}

bool NameTable::hasVariable(const std::string& name) {
  return varTable.find(name) != varTable.end();
}

NameTableValue NameTable::queryVariable(const string& name) {
  return varTable.at(name);
}

void NameTable::mergeBranch(shared_ptr<NameTable> rhs) {
  // if name exists at both places, then do type union, and can be undefined if any of branch can be undefined
  // if name appears only on one side, then the type is same as the other side, can be undefined
  if (!rhs) return;
  unordered_set<string> unionKeySet;
  for (auto item : varTable)
    unionKeySet.insert(item.first);
  for (auto item : rhs->varTable)
    unionKeySet.insert(item.first);
  for (auto& key : unionKeySet) {
    auto lhsItr = varTable.find(key);
    auto rhsItr = rhs->varTable.find(key);
    if (lhsItr != varTable.end() && rhsItr != rhs->varTable.end()) {
      NameTableValue lhsValue = lhsItr->second, rhsValue = rhsItr->second;
      const TapType* newType = lhsValue.getType()->unionType(rhsValue.getType());
      lhsItr->second = NameTableValue{newType, lhsValue.canBeUndefined() || rhsValue.canBeUndefined()};
    } else if (lhsItr != varTable.end()) {
      lhsItr->second = lhsItr->second.setCanBeUndefined(true);
    } else {  // rhs->varTable contains key
      varTable.insert(make_pair(key, rhs->varTable.at(key).setCanBeUndefined(true)));
    }
  }
  LOG(INFO) << "#### after merge: " << this->toString();
}

void NameTable::mergeSequence(const NameTable* rhs) {
  // TODO
  // if name exists at both places:
  //      if variable in rhs can be undefined: do union
  //      else: override by variable in rhs
  if (!rhs) return;
  for (auto& itr : rhs->varTable) {
    if (hasVariable(itr.first) && itr.second.canBeUndefined()) {
      // if lhs is defined, the result will be defined
      // otherwise, undefined
      NameTableValue lhsValue = varTable.at(itr.first);
      NameTableValue rhsValue = itr.second;
      const TapType *newType = lhsValue.getType()->unionType(rhsValue.getType());
      // TODO: avoid []
      varTable[itr.first] = NameTableValue{newType, lhsValue.canBeUndefined()};
    } else {
      varTable[itr.first] = itr.second;
    }
  }
}

void NameTable::forgetNonLocalVars() {
  for (auto& name : nonLocalVars)
    varTable.erase(name);
}

void NameTable::markUndefined() {
  for (auto& item : varTable) {
    item.second = item.second.setCanBeUndefined(true);
  }
}

void NameTable::remove(shared_ptr<NameTable> rhs) {
  // if (!rhs) return;
  for (auto& item : rhs->varTable) {
    if (hasVariable(item.first)) {
      NameTableValue lhsValue = varTable.at(item.first);
      NameTableValue rhsValue = item.second;
      const TapType *newType = lhsValue.getType()->substract(rhsValue.getType());
      // TODO: avoid []
      varTable[item.first] = NameTableValue{newType, lhsValue.canBeUndefined()};
      // varTable.insert(make_pair(item.first, NameTableValue{newType, lhsValue.canBeUndefined()}));
    } else {
      // report error?
    }
  }
}

string NameTable::toString() {
  string res;
  for (auto& item : varTable) {
    res += "[" + item.first + "=>" + item.second.getType()->toString() + 
      (item.second.canBeUndefined() ? "U" : "") + "]";
  }
  return res;
}

}
