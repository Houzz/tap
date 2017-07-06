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

namespace Tap {

class Config;

class PathWalker {
  public:
    PathWalker(const Config& config) : m_config{config} {}
    void start();
    
    static void addFile(const std::string& filename);
    static void removeFile(const std::string& filename);
    static void updateFile(const std::string& filename);

    // Mostly used for test and debug
    static void handleSingleFile(const std::string& filename);
    
  private:
    const Config& m_config;
};

}