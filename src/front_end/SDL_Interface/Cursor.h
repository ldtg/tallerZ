//
// Created by darius on 21/05/17.
//

#ifndef TALLERZ_CURSOR_H
#define TALLERZ_CURSOR_H

#include "SDL2/SDL.h"
#include "Front_end_exceptions/Front_end_exception.h"

class Cursor {
 private:
  SDL_Cursor * cursor;

 public:
  Cursor();

  ~Cursor();

  void load_cursor(SDL_SystemCursor id);
};

#endif //TALLERZ_CURSOR_H
