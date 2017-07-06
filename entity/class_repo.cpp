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

#include "class_repo.h"
#include "util/error_collector.h"
#include <queue>
#include <glog/logging.h>

using namespace std;

namespace Tap {

void ClassRepo::addClazz(const std::string& name, std::shared_ptr<Clazz> clazz, const std::string& filename) {
  LOG(INFO) << "Add class " << name << " into repo, clazz:" << clazz;
  if (m_classes.find(name) != m_classes.end()) {
    ErrorCollector::getInstance().emitError(
      ErrorCollector::E_DUPLICATED_CLASS,
      "duplicated class name " + name,
      clazz->getRange()
    );
  } else {
    m_classes.insert(make_pair(name, clazz));
    m_filenames.insert(make_pair(name, filename));
  }
}

std::shared_ptr<Clazz> ClassRepo::getClazz(const std::string name) {
  auto itr = m_classes.find(name);
  return itr != m_classes.end() ? itr->second : nullptr;
}

string ClassRepo::getFilename(const std::string name) {
  auto itr = m_filenames.find(name);
  return itr != m_filenames.end() ? itr->second : nullptr;
}

void ClassRepo::expandClasses() {
  for (auto& item : m_classes) {
    TapContext::getInstance().setCurrentFilename(m_filenames[item.first]);
    item.second->expand();
  }
}

void ClassRepo::addRelation(const string& baseClass, const string& subClass) {
  LOG(INFO) << "add subclass " << subClass << " whose base class is " << baseClass;
  m_subClassMap[subClass].push_back(baseClass);
}

bool ClassRepo::isSubClass(const string& class1, const string& class2) {
  queue<string> q;
  unordered_set<string> visited;
  visited.insert(class1);
  q.push(class1);
  while (!q.empty()) {
    string cur = q.front();
    q.pop();
    if (cur == class2) return true;
    auto itr = m_subClassMap.find(cur);
    if (itr != m_subClassMap.end()) {
      for (auto next : itr->second) {
        if (visited.find(next) != visited.end())
          continue;
        visited.insert(next);
        q.push(next);
      }
    }
  }
  return false;
}

void ClassRepo::addClazzInc(const string& name, shared_ptr<Clazz> clazz, const string& filename) {
  addClazz(name, clazz, filename);
  TapContext::getInstance().setCurrentFilename(filename);
  clazz->expand();
  expandSubClasses(name);
}

void ClassRepo::updateClazz(const string& name, shared_ptr<Clazz> clazz, const string& filename) {
  removeClazz(name);
  addClazzInc(name, clazz, filename);
}

void ClassRepo::removeClazz(const string& name) {
  m_subClassMap.erase(name);
  m_classes.erase(name);
  m_filenames.erase(name);
  expandSubClasses(name); // remove the inherited properties/methods from subclasses
}

void ClassRepo::removeFile(const string& filename) {
  unordered_set<string> classToRemove;
  for (auto item : m_filenames) {
    if (item.second == filename)
      classToRemove.insert(item.first);
  }
  for (auto className : classToRemove) {
    removeClazz(className);
  }
}

void ClassRepo::expandSubClasses(const string& name) {
  queue<string> q;
  unordered_set<string> visited;
  visited.insert(name);
  q.push(name);
  while (!q.empty()) {
    string cur = q.front();
    q.pop();
    auto curClazz = m_classes.find(cur);
    if (curClazz != m_classes.end() && curClazz->second != nullptr) {
      if (cur != name) {
        // don't expand the root class
        TapContext::getInstance().setCurrentFilename(m_filenames[cur]);
        curClazz->second->expand();
      }
    }
    for (auto item : m_subClassMap) {
      string subClassName = item.first;
      for (auto parentName : item.second) {
        if (parentName == cur) {
          if (visited.find(subClassName) != visited.end())
            continue;
          visited.insert(subClassName);
          q.push(subClassName);
        }
      }
    }
  }
  TapContext::getInstance().setCurrentFilename("");
}

}