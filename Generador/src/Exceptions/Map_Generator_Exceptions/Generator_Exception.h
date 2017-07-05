
#ifndef TALLER_Z_GENERATOR_EXCEPTIONS_H
#define TALLER_Z_GENERATOR_EXCEPTIONS_H

#include <exception>
#include <string>
#include <cstring>
#include <errno.h>
#include <cstdarg>

#define BUF_LEN 512

class Generator_Exception : public std::exception {
 protected:
  int _errno;

  char msg_error[BUF_LEN];

 public:
  explicit Generator_Exception(const char *msg, ...) noexcept;

  virtual ~Generator_Exception() noexcept {};

  const char *what() const noexcept;
};

#endif //TALLER_Z_GENERATOR_EXCEPTIONS_H
