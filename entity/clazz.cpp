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

#include "entity/clazz.h"
#include "entity/function.h"
#include "entity/property.h"
#include "entity/class_repo.h"
#include "entity/visibility.h"
#include "type/tap_type.h"
#include "util/error_collector.h"
#include <glog/logging.h>
#include <queue>
using namespace std;

namespace Tap {

void Clazz::addMethod(std::string name, shared_ptr<Function> method) {
  if (methods.find(name) != methods.end()) {
    if (m_status != Status::EXPANDING) {
      ErrorCollector::getInstance().emitError(
        ErrorCollector::E_DUPLICATED_METHOD,
        "Duplicated method " + name,
        method->getRange()
      );
    }
  } else {
    LOG(INFO) << "Add method " + name + " into class " + fqName;
    methods.insert(std::make_pair(name, method));
  }
}

void Clazz::addProperty(std::string name, shared_ptr<Property> property) {
  if (properties.find(name) != properties.end()) {
    if (m_status != Status::EXPANDING) {
      ErrorCollector::getInstance().emitError(
        ErrorCollector::E_DUPLICATED_PROPERTY,
        "Duplicated property " + name,
        property->getRange()
      );
    }
  } else {
    LOG(INFO) << "property->type:" << property->type;
    LOG(INFO) << "Add property " << name << " with type " << 
      property->type->toString() << " into class " << fqName;
    properties.insert(std::make_pair(name, property));
  }
}

void Clazz::addConst(std::string name, shared_ptr<Const> cnst) {
  if (consts.find(name) != consts.end()) {
    if (m_status != Status::EXPANDING) {
      ErrorCollector::getInstance().emitError(
        ErrorCollector::E_DUPLICATED_CONST,
        "Duplicated const " + name,
        cnst->getRange()
      );
    }
  } else {
    LOG(INFO) << "cnst->type:" << cnst->type;
    LOG(INFO) << "Add const " << name << " with type " << 
      cnst->type->toString() << " into class " << fqName;
    consts.insert(std::make_pair(name, cnst));
  }
}
         
void Clazz::expand() {
  LOG(INFO) << "Start expanding class " << fqName;
  m_status = Status::EXPANDING;
  queue<string> q;
  unordered_set<string> visited;
  q.push(fqName);
  visited.insert(fqName);
  while (!q.empty()) {
    string curClassName = q.front();
    q.pop();
    auto curClass = ClassRepo::getInstance().getClazz(curClassName);
    if (!curClass) {
      // LOG(ERROR) << "When expanding, failed to find class " + curClassName;
      ErrorCollector::getInstance().emitError(ErrorCollector::E_CLASS_NOT_FOUND,
        "When expanding, failed to find class " + curClassName,
        range);
      continue;
    }
    
    if (curClass->fqName != fqName) {
      inheriteFromParent(curClass);
    }

    for (auto& parentName : curClass->parents) {
      if (visited.find(parentName) != visited.end())
        continue;
      visited.insert(parentName);
      q.push(parentName);
    }
  }
  m_status = Status::EXPANDED;
}

void Clazz::inheriteFromParent(shared_ptr<Clazz> parentClass) {
  for (auto& item : parentClass->consts) {
    // TODO(liang): check visibility
    addConst(item.first, item.second);
  }
  for (auto& item : parentClass->properties) {
    if (item.second->visibility != VisibilityEnum::T_PRIVATE)
      addProperty(item.first, item.second);
  }
  for (auto& item : parentClass->methods) {
    if (item.first == "__construct")
      continue; // don't inherit ctor
    if (item.second->visibility != VisibilityEnum::T_PRIVATE)
      addMethod(item.first, item.second);
  }
}

bool Clazz::isVisible(VisibilityEnum visibility, const string& curClass) {
  string cc = curClass.empty() ? TapContext::getInstance().getCurrentClass() : curClass;
  switch (visibility) {
    case VisibilityEnum::T_PUBIC:
      return true;
    case VisibilityEnum::T_PROTECTED:
      return ClassRepo::getInstance().isSubClass(cc, fqName);
    case VisibilityEnum::T_PRIVATE:
      return (fqName == cc);
  }
  return false;
}

shared_ptr<Function> Clazz::getMethod(const string& name, const string& curClass) {
  auto res = methods.find(name);
  if (res != methods.end()) {
    if (isVisible(res->second->visibility, curClass))
      return res->second;
  }
  return nullptr; 
}

shared_ptr<Property> Clazz::getProperty(const string& name, const string& curClass) {
  auto res = properties.find(name);
  if (res != properties.end()) {
    if (isVisible(res->second->visibility, curClass))
      return res->second;
  }
  return nullptr;
}

void Clazz::updatePropertyType(const string& name, TapType *type) {
  auto res = properties.find(name);
  if (res != properties.end()) {
    res->second->type = type;
  } else {
    LOG(ERROR) << "Supposed to update property: " << name << ", but it doesn't exist";
  }
}

}