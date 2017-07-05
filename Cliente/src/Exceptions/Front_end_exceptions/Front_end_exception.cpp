#include <cstdio>
#include "Generator_Exception.h"

Front_end_exception::Front_end_exception(const char *msg, ...) noexcept {
  va_list args;
  va_start(args, msg);
  vsnprintf(&this->msg_error[0], BUF_LEN, msg, args);
  va_end(args);
  msg_error[BUF_LEN - 1] = '\0';
}

const char *Front_end_exception::what() const noexcept {
  return &this->msg_error[0];
}
