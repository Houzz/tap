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
#include <vector>
#include <unordered_map>

#include "clazz.h"

namespace Tap {

class ClassRepo {
  public:
    static ClassRepo& getInstance() {
      static ClassRepo instance;
      return instance;
    }
    
    void addClazz(const std::string& name, std::shared_ptr<Clazz> clazz, const std::string& filename = "");
    std::shared_ptr<Clazz> getClazz(const std::string name);
    std::string getFilename(const std::string className);
    void expandClasses();
    
    void addRelation(const std::string& baseClass, const std::string& subClass);
    bool isSubClass(const std::string& class1, const std::string& class2);
    
    /**
     * Used in incremental mode
     * Beside the normal operation of addClazz, we need to expand and resolve as well.
     */
    void addClazzInc(const std::string& name, std::shared_ptr<Clazz> clazz, const std::string& filename = "");
    
    /* Used in incremental mode
     * When class signature is changed, re-expand its subclasses
     */
    void updateClazz(const std::string& name, std::shared_ptr<Clazz> clazz, const std::string& filename = "");
    
    /* Used in incremental mode
     * When class is removed, re-expand its subclasses
     */
    void removeClazz(const std::string& name);
    void removeFile(const std::string& filename);
  private:
    ClassRepo() {}
    void expandSubClasses(const std::string& name);
    
    std::unordered_map<std::string, std::shared_ptr<Clazz>> m_classes;
    std::unordered_map<std::string, std::string> m_filenames;
    
    // Note: m_subClassMap is always consistent with the source file.
    // For example, even when the parent class is absent, the relationship is still here.
    // That's because we may change the class name later to recover the inheritance tree.
    std::unordered_map<std::string, std::vector<std::string>> m_subClassMap;  // class => parentClass
    
};

}

