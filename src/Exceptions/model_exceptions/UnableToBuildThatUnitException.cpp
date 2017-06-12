#include "UnableToBuildThatUnitException.h"
UnableToBuildThatUnitException::UnableToBuildThatUnitException(const std::string &msg)
    : msg(msg) {
}
const char *UnableToBuildThatUnitException::what() const throw(){
  return msg.c_str();
}