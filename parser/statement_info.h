#pragma once

#include "visitor/name_table.h"

namespace Tap {

class StatementInfo {
  private:
    std::shared_ptr<NameTable> nameTable;
    bool hasReturn;
  
  public:
    StatementInfo(std::shared_ptr<NameTable> nameTable)
      : nameTable{nameTable} {}
    StatementInfo(std::shared_ptr<NameTable> nameTable, bool hasReturn)
      : nameTable{nameTable}, hasReturn{hasReturn} {}
    
    std::shared_ptr<NameTable> getNameTable() {return nameTable;}
    bool hasReturnStatement() {return hasReturn;}
    
    static StatementInfo& getDummyInstance() {
      static StatementInfo dummyInstance{nullptr, false};
      return dummyInstance;
    }
};

}