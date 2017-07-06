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

#include <unordered_set>
#include <string>

namespace Tap {

class Config {
  public:
    static Config& getInstance();

    static void setPerdefinedSrcRoot(const std::string& srcRoot) {
      if (srcRoot.size() > 1 && (srcRoot[srcRoot.size()-1] == '/' || srcRoot[srcRoot.size()-1] == '\\')) {
        s_predefinedSrcRoot = srcRoot.substr(0, srcRoot.size()-1);
      } else {
        s_predefinedSrcRoot = srcRoot;
      }
    }
    
    const std::string& getSourceRoot() const {
      return s_predefinedSrcRoot.empty() ? m_srcRoot : s_predefinedSrcRoot;
    }
    bool shouldSkip(const std::string& path) const {
      return m_skipPath.find(path) != m_skipPath.end();
    }
    bool shouldScanOnly(const std::string& path) const {
      return m_scanOnlyPath.find(path) != m_scanOnlyPath.end();
    }
    bool isBatchMode() const {
      return m_isBatchMode;
    }
  private:
    std::string m_srcRoot;
    std::unordered_set<std::string> m_skipPath;
    std::unordered_set<std::string> m_scanOnlyPath;
    bool m_isBatchMode;
    
    Config();
    
    bool findConfigFile(const std::string& currentPath = "");
    bool parseConfigFile(const std::string& filePath);
    
    static std::string s_predefinedSrcRoot;
};

}