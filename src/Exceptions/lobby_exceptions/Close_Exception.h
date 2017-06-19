//
// Created by darius on 17/06/17.
//

#ifndef TALLERZ_CLIENTE_CLOSE_EXCEPTION_H
#define TALLERZ_CLIENTE_CLOSE_EXCEPTION_H

#include <exception>
#define BUF_LEN 512

class Close_Exception : public std::exception {
 protected:
  int _errno;
  char msg_error[BUF_LEN];
 public:
  explicit Close_Exception() noexcept;

  virtual ~Close_Exception() noexcept {};

  const char *what() const noexcept;
};

#endif //TALLERZ_CLIENTE_CLOSE_EXCEPTION_H
