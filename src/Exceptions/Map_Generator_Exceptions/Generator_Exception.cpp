//
// Created by darius on 23/04/17.
//

#include <cstdio>
#include "Generator_Exception.h"

Generator_Exception::Generator_Exception(const char *msg, ...) noexcept {
  va_list args;
  va_start(args, msg);
  vsnprintf(&this->msg_error[0], BUF_LEN, msg, args);
  va_end(args);
  msg_error[BUF_LEN - 1] = '\0';
}

const char *Generator_Exception::what() const noexcept {
  return &this->msg_error[0];
}
