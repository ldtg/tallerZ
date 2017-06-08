
#include "BuildingNotFoundException.h"
BuildingNotFoundException::BuildingNotFoundException(const std::string &msg)
    : msg(msg) {}
const char *BuildingNotFoundException::what() const throw() {
  return msg.c_str();
}