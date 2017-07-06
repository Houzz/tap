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
#include <memory>

namespace Tap {

class Function;

class TapContext {
  public:
    enum Mode {
      M_BATCH = 1,
      M_SERVER_INIT,
      M_SERVER_INCREMENTAL,
      M_SINGLE
    };
    
    static TapContext& getInstance() {
      static TapContext instance;
      return instance;
    }
    
    void setCurrentClass(const std::string& curClass) {
      m_curClass = curClass;
    }
    std::string getCurrentClass() {
      return m_curClass;
    }
    void setCurrentMethod(std::shared_ptr<Function> method) {
      m_curMethod = method;
    }
    std::shared_ptr<Function> getCurrentMethod() {
      return m_curMethod;
    }
    void setPassNo(int passNo) {
      m_passNo = passNo;
    }
    int getPassNo() {
      return m_passNo;
    }
    void setCurrentFilename(const std::string& filename) {
      m_curFilename = filename;
    }
    std::string& getCurrentFilename() {
      return m_curFilename;
    }
    void setEmitterEnabled(bool status) {
      m_emit = status;
    }
    bool isEmitterEnabled() {
      return m_emit;
    }
    void setMode(Mode mode) {
      m_mode = mode;
    }
    Mode getMode() {
      return m_mode;
    }
    void setReportFile(const std::string& filename) {
      m_report_file = filename;
    }
    std::string& getReportFile() {
      return m_report_file;
    }
    void setDBFile(const std::string& dbFile) {
      m_db_file = dbFile;
    }
    std::string& getDBFile() {
      return m_db_file;
    }
  private:
    std::string m_curNamespace, m_curClass;
    std::string m_curFilename;
    std::shared_ptr<Function> m_curMethod;
    int m_passNo;
    bool m_emit;
    Mode m_mode;
    std::string m_report_file;
    std::string m_db_file;

    TapContext() : m_emit(true), m_mode(Mode::M_SERVER_INIT), m_db_file("/tmp/tap.db") {}
};

}
