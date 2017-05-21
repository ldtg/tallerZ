//
// Created by darius on 21/05/17.
//

#ifndef TALLERZ_SIDE_BOARD_H
#define TALLERZ_SIDE_BOARD_H

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <view/Window.h>
#include "Sdl_Utils.h"

class Side_Board {
 private:
  SDL_Texture * side_board = NULL;
 public:
  Side_Board(Window * window);

  void load_side_board(Window * window);

  SDL_Texture *get_side_board();
};

#endif //TALLERZ_SIDE_BOARD_H
