#include "Close_Exception.h"
#include <cstdio>

Close_Exception::Close_Exception(const char *msg, ...) noexcept {
  va_list args;
  va_start(args, msg);
  vsnprintf(&this->msg_error[0], BUF_LEN, msg, args);
  va_end(args);
  msg_error[BUF_LEN - 1] = '\0';
}

const char *Close_Exception::what() const noexcept {
  return &this->msg_error[0];
}