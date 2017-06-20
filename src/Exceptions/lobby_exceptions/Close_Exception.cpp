//
// Created by darius on 17/06/17.
//

#include "Close_Exception.h"
#include <cstdio>

Close_Exception::Close_Exception() noexcept {
}

const char *Close_Exception::what() const noexcept {
  return "Program Closed";
}