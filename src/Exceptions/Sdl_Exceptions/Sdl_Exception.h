#ifndef TALLERZ_SDL_EXCEPTION_H
#define TALLERZ_SDL_EXCEPTION_H

#include <exception>
#include <cstdarg>
#include <errno.h>
#include <cstring>

#define BUF_LEN 512

class Sdl_Exception : public std::exception {
 protected:
  int _errno;

  char msg_error[BUF_LEN];

 public:
  explicit Sdl_Exception(const char *msg, ...) noexcept;

  virtual ~Sdl_Exception() noexcept {};

  const char *what() const noexcept;
};

#endif //TALLERZ_SDL_EXCEPTION_H
