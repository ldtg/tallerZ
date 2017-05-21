//
// Created by darius on 23/04/17.
//

#ifndef TALLER_Z_FRONT_END_EXCEPTIONS_H
#define TALLER_Z_FRONT_END_EXCEPTIONS_H

#include <exception>
#include <string>
#include <cstring>
#include <errno.h>
#include <cstdarg>

#define BUF_LEN 512

class Front_end_exception : public std::exception {
 protected:
  int _errno;

  char msg_error[BUF_LEN];

 public:
  explicit Front_end_exception(const char *msg, ...) noexcept;

  virtual ~Front_end_exception() noexcept {};

  const char *what() const noexcept;
};

#endif //TALLER_Z_FRONT_END_EXCEPTIONS_H
