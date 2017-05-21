//
// Created by darius on 21/05/17.
//

#ifndef TALLERZ_SDL_START_H
#define TALLERZ_SDL_START_H

#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Sdl_Exceptions/Sdl_Exception.h"

class SDL_START {
 public:
  SDL_START();

  ~SDL_START();

  void operator()(){}

  void initialize_SDL();

  void initialize_SDL_image();

};

#endif //TALLERZ_SDL_START_H
