#include "UnableToFindAPathException.h"
UnableToFindAPathException::UnableToFindAPathException(const std::string &msg)
    : msg(msg) {
}
const char *UnableToFindAPathException::what() const throw(){
  return msg.c_str();
}
