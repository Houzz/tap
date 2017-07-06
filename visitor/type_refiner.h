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
#include "ast/ast_decls.h"
#include "visitor/name_table.h"
#include "parser/location.h"

namespace Tap {

class TapType;

struct ConditionEntry {
  std::string varName;
  bool positive;  // "should be" or "shouldn't be"
  TapType* type;
  HPHP::Location::Range range;
};

typedef std::shared_ptr<Tap::NameTable> NameTablePtr;
typedef std::shared_ptr<ConditionEntry> ConditionEntryPtr;
    
class TypeRefiner {
  public:    
    TypeRefiner(std::vector<NameTablePtr>& nameTableStack)
      : m_nameTableStack{nameTableStack}, m_canCutoff{true} {}
      
    NameTablePtr tryRefine(HPHP::ExpressionPtr exp);
    bool isCurrentBranchImpossible() {
      return m_isCurBranchImpossible;
    }
    void setHasReturnForCurrentBranch() {
      if (m_nameTableForCurrentBranch && m_nameTableForCurrentBranch->size() > 0)
        m_nameTablesForReturnBranches.push_back(m_nameTableForCurrentBranch);
    }
    
    NameTablePtr getCutTypes();
    
  private:
    std::vector<NameTablePtr> m_nameTableStack;
    std::vector<ConditionEntryPtr> m_conditions;
    bool m_isCurBranchImpossible;
    NameTablePtr m_nameTableForCurrentBranch;
    std::vector<NameTablePtr> m_nameTablesForReturnBranches;
    bool m_canCutoff;
    
    void applyConditionEntry(NameTablePtr nameTable, ConditionEntryPtr conditionEntry, bool isReverse);
};

}