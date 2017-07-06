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
#include <unordered_map>
#include "parser/location.h"
#include "util/tap_context.h"
#include <glog/logging.h>
#include <sqlite3.h>

namespace Tap {

struct EnumClassHash
{
    template <typename T>
    std::size_t operator()(T t) const
    {
        return static_cast<std::size_t>(t);
    }
};

class ErrorCollector {
  public:
    enum ErrorCode {
      E_TODO = 100,
      E_INTERNAL_TYPE_CHECK,
      E_RETURN_TYPE,
      E_FUNCTION_ARGUMENT,
      E_TYPE_HINT,
      E_NAME_UNDEFINED,
      E_EXPECTED_TYPE,
      E_MAP_KEY_TYPE,
      E_MAP_VALUE_TYPE,
      E_VECTOR_ELEM_TYPE,
      E_ARRAY_LITERAL,
      E_SWITCH_CASE_TYPE,
      E_TUPLE_OUT_RANGE,
      E_METHOD_NOT_FOUND,
      E_PROPERTY_NOT_FOUND,
      E_CONST_NOT_RESOLVED,
      E_FUNCTION_NOT_FOUND,
      E_CLASS_NOT_FOUND,
      E_PARSING_FAILED,
      E_DUPLICATED_CONST,
      E_DUPLICATED_CLASS,
      E_DUPLICATED_METHOD,
      E_DUPLICATED_PROPERTY,
      E_DUPLICATED_FUNCTION,
      E_STATIC_PROPERTY,
      E_STATIC_METHOD,
      E_STATIC_THIS,
      E_UNION_TYPE_METHOD
    };
    
    enum WarningCode {
      W_NO_PARAM_ANNOTATION = 200,
      W_NO_RETURN_ANNOTATION,
      W_NO_PROPERTY_ANNOTATION,
      W_FAILED_PARSING_ANNOTATION,
      W_IMPOSSIBLE_BRANCH,
      W_INCONSISTENT_ANNOTATION,
      W_TOO_GENERAL,
      W_EMPTY_SWITCH,
      W_EMPTY_IF,
      W_OLD_STYLE_CTOR
    };
    
    static ErrorCollector& getInstance();

    static std::unordered_map<ErrorCode, std::string, EnumClassHash> errorCodeMap;
    
    static std::unordered_map<WarningCode, std::string, EnumClassHash> warningCodeMap;
    
    void emitError(ErrorCode errorCode, const std::string& msg, const HPHP::Location::Range &r);
    
    void emitWarning(WarningCode warningCode, const std::string& msg, const HPHP::Location::Range &r);

    void finalize();

  private:
    ErrorCollector();
    ~ErrorCollector();

    std::unordered_map<std::string, int> m_error_counts;
    std::unordered_map<std::string, int> m_warning_counts;
    
    sqlite3* m_db;
    FILE *m_fp;
};

}

