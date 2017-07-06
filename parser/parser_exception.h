#pragma once

#include <string>

namespace Tap {

class ParserException : public std::exception {
  public:
    ParserException(const std::string& msg) : m_msg{msg} {
    }
    virtual const char* what() const throw() override {
      return m_msg.c_str();
    }
  private:
    std::string m_msg;
};

}