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

#include "internal_const.h"
#include "type/primitive_tap_type.h"
#include <string>
#include <glog/logging.h>

using namespace std;

namespace Tap {

void InternalConst::addConst(const string& name, const string& type) {
  TapType *t;
  if (type == "int") {
    t = PrimitiveTapType::valueOf(PrimitiveTapType::INTEGER_TYPE);
  } else if (type == "string") {
    t = PrimitiveTapType::valueOf(PrimitiveTapType::STRING_TYPE);
  } else if (type == "float") {
    t = PrimitiveTapType::valueOf(PrimitiveTapType::FLOAT_TYPE);
  } else if (type == "bool") {
    t = PrimitiveTapType::valueOf(PrimitiveTapType::BOOL_TYPE);
  } else if (type == "null") {
    t = PrimitiveTapType::valueOf(PrimitiveTapType::NULL_TYPE);
  } else {
    LOG(FATAL) << "Unknown predefine const type " << type;
  }
  m_consts.insert(make_pair(name, t));
}

TapType* InternalConst::getStringConst(const string& name) {
  auto itr = m_consts.find(name);
  if (itr != m_consts.end())
    return itr->second;
  return nullptr;
}

void InternalConst::init() {
  addConst("PHP_VERSION", "string");
  addConst("PHP_MAJOR_VERSION", "int");
  addConst("PHP_MINOR_VERSION", "int");
  addConst("PHP_RELEASE_VERSION", "int");
  addConst("PHP_VERSION_ID", "int");
  addConst("PHP_EXTRA_VERSION", "string");
  addConst("PHP_ZTS", "int");
  addConst("PHP_DEBUG", "int");
  addConst("PHP_MAXPATHLEN", "int");
  addConst("PHP_OS", "string");
  addConst("PHP_SAPI", "string");
  addConst("PHP_EOL", "string");
  addConst("PHP_INT_MAX", "int");
  addConst("PHP_INT_MIN", "int");
  addConst("PHP_INT_SIZE", "int");
  addConst("PHP_FLOAT_DIG", "int");
  addConst("PHP_FLOAT_EPSILON", "float");
  addConst("PHP_FLOAT_MIN", "float");
  addConst("PHP_FLOAT_MAX", "float");
  addConst("DEFAULT_INCLUDE_PATH", "string");
  addConst("PEAR_INSTALL_DIR", "string");
  addConst("PEAR_EXTENSION_DIR", "string");
  addConst("PHP_EXTENSION_DIR", "string");
  addConst("PHP_PREFIX", "string");
  addConst("PHP_BINDIR", "string");
  addConst("PHP_BINARY", "string");
  addConst("PHP_MANDIR", "string");
  addConst("PHP_LIBDIR", "string");
  addConst("PHP_DATADIR", "string");
  addConst("PHP_SYSCONFDIR", "string");
  addConst("PHP_LOCALSTATEDIR", "string");
  addConst("PHP_CONFIG_FILE_PATH", "string");
  addConst("PHP_CONFIG_FILE_SCAN_DIR", "string");
  addConst("PHP_SHLIB_SUFFIX", "string");
  addConst("PHP_FD_SETSIZE", "string");
  addConst("E_ERROR", "int");
  addConst("E_WARNING", "int");
  addConst("E_PARSE", "int");
  addConst("E_NOTICE", "int");
  addConst("E_CORE_ERROR", "int");
  addConst("E_CORE_WARNING", "int");
  addConst("E_COMPILE_ERROR", "int");
  addConst("E_COMPILE_WARNING", "int");
  addConst("E_USER_ERROR", "int");
  addConst("E_USER_WARNING", "int");
  addConst("E_USER_NOTICE", "int");
  addConst("E_DEPRECATED", "int");
  addConst("E_USER_DEPRECATED", "int");
  addConst("E_ALL", "int");
  addConst("E_STRICT", "int");
  addConst("__COMPILER_HALT_OFFSET__", "int");
  addConst("TRUE",  "bool");
  addConst("FALSE", "bool");
  addConst("NULL", "null");
}

}