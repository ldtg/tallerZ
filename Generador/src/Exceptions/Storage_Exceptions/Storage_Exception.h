//
// Created by darius on 01/06/17.
//

#ifndef TALLERZ_STORAGE_EXCEPTION_H
#define TALLERZ_STORAGE_EXCEPTION_H

#include <exception>
#include <string>
#include <cstring>
#include <errno.h>
#include <cstdarg>

#define BUF_LEN 512

class Storage_Exception : public std::exception {
 protected:
  int _errno;

  char msg_error[BUF_LEN];

 public:
  explicit Storage_Exception(const char *msg, ...) noexcept;

  virtual ~Storage_Exception() noexcept {};

  const char *what() const noexcept;
};

#endif //TALLERZ_STORAGE_EXCEPTION_H
