#include "UnitNotFoundException.h"
UnitNotFoundException::UnitNotFoundException(const std::string &msg)
    : msg(msg) {}
const char *UnitNotFoundException::what() const throw() {
  return msg.c_str();
}
