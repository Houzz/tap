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

#include "const_alias.h"
#include "util/error_collector.h"
#include "type/tap_type.h"
#include "type/any_tap_type.h"
#include "type/unresolved_type.h"
#include "type/type_utils.h"
#include "entity/class_repo.h"
#include "visitor/expression_visitor.h"
#include "ast/expression.h"
#include <folly/String.h>
#include <glog/logging.h>
#include <vector>
#include <cassert>
using namespace std;

namespace Tap {

void ConstAlias::addDependency(const string& lhsName,
  const string& rhsName, const HPHP::Location::Range& range) {
  
  if (m_dep.find(lhsName) != m_dep.end()) {
    ErrorCollector::getInstance().emitError(
      ErrorCollector::E_DUPLICATED_CONST,
      folly::stringPrintf("const %s already exists", lhsName.c_str()),
      range
    );
  }
  // m_dep.insert(make_pair(lhsName, DependencyMapValue{rhsName, range}));
  m_dep[lhsName].push_back(rhsName);
  m_ranges[lhsName] = range;
}

void ConstAlias::addDependency(const string& lhsName,
  const unordered_set<string>& rhsNames,
  HPHP::ExpressionPtr exp,
  const HPHP::Location::Range &range) {
  
  if (m_dep.find(lhsName) != m_dep.end()) {
    ErrorCollector::getInstance().emitError(
      ErrorCollector::E_DUPLICATED_CONST,
      folly::stringPrintf("const %s already exists", lhsName.c_str()),
      range
    );
  }
  
  for (auto rhsName : rhsNames) {
    LOG(INFO) << "add dependency lhs:" << lhsName << " rhs:" << rhsName;
    m_dep[lhsName].push_back(rhsName);
    // m_dep.insert(make_pair(lhsName, DependencyMapValue{rhsName, range}));
  }
  m_rhsExps.insert(make_pair(lhsName, exp));
  m_ranges[lhsName] = range;
}

static void addType(const string fullName, TapType *type, HPHP::Location::Range &r) {
  vector<string> v;
  folly::split("::", fullName, v);
  CHECK(v.size() == 2);
  string className = v[0];
  string entityName = v[1];
  auto clazzPtr = ClassRepo::getInstance().getClazz(className);
  CHECK(clazzPtr);
  if (entityName[0] == '$') {
    LOG(INFO) << "Trying to update static propery " << entityName << " of class " << className;
    clazzPtr->updatePropertyType(entityName.substr(1), type);
    LOG(INFO) << "Static property " << entityName << " of class " << className << " update to type " << type->toString();
  } else {
    auto constEntity = make_shared<Const>(entityName, type, r);
    clazzPtr->addConst(entityName, constEntity);
    LOG(INFO) << "Const " << entityName << " got type " << type->toString();
  }
}

static string getClassName(const string& fullName) {
  vector<string> v;
  folly::split("::", fullName, v);
  CHECK(v.size() == 2);
  return v[0];
}

inline static string getFilenameFromClassName(const string& className) {
  return ClassRepo::getInstance().getFilename(className);
}

void ConstAlias::resolve() {
  LOG(INFO) << "Start resolve alias";
  auto expVisitor = make_unique<ExpressionVisitor>(m_nameTableStack);
  while (true) {
    unordered_set<string> toRemove;
    
    for (auto item : m_dep) {
      bool flg = true;
      for (auto rhsName : item.second) {
        if (m_dep.find(rhsName) != m_dep.end()) {
          flg = false;
          break;
        }
      }
      if (flg) {
        string lhsName = item.first;
        LOG(INFO) << "All dependency of " << lhsName << " resolved, trying to resolve it";
        CHECK(m_rhsExps.find(lhsName) != m_rhsExps.end());
        auto exp = m_rhsExps[lhsName];
        string className = getClassName(lhsName);
        TapContext::getInstance().setCurrentClass(className);
        TapContext::getInstance().setCurrentFilename(getFilenameFromClassName(className));
        exp->accept(*expVisitor);
        TapType *type = exp->getType();
        if (TypeUtils::isUnresolved(type)) {
          ErrorCollector::getInstance().emitError(
            ErrorCollector::E_CONST_NOT_RESOLVED,
            "Const " + lhsName + " cannot be resolved",
            m_ranges[lhsName]);
          type = AnyTapType::getInstance();
        } else {
          addType(lhsName, type, m_ranges[lhsName]);
        }
        toRemove.insert(lhsName);
      }
    }
    
    if (toRemove.empty()) {
      break;
    }
    for (auto name : toRemove)
      m_dep.erase(name);
  }
  
  for (auto item : m_dep) {
    ErrorCollector::getInstance().emitError(
      ErrorCollector::E_CONST_NOT_RESOLVED,
      "Const " + item.first + " cannot be resolved",
      m_ranges[item.first]
    );
    addType(item.first, AnyTapType::getInstance(), m_ranges[item.first]);
  }
  
  LOG(INFO) << "Finish resolve alias";
}

}
