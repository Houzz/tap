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

#include <sqlite3.h>
#include <string>

namespace Tap {

class DB {
  public:
    enum ServerStatus {
      STOPPED = 0,
      INIT = 1,
      RUNNING = 2
    };
    
    static DB& getInstance();
    
    DB();
    ~DB();
    
    void runSql(const std::string& sql);

    void clear();
    void clearFileError(const std::string& filename);

    void setServerStatus(ServerStatus status);
    ServerStatus getServerStatus();
    
    void getErrors(const char* filename);
    
  private:
    sqlite3* m_db;
};

}