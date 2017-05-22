//
// Created by darius on 21/05/17.
//

#ifndef TALLERZ_SIDE_BOARD_H
#define TALLERZ_SIDE_BOARD_H

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <view/Window.h>
#include <view/Texture.h>

class Side_Board {
 private:
  Texture * side_board_texture;
 public:
  Side_Board(Window * window);

  ~Side_Board();

  void load_side_board(Window * window);

  Texture *get_side_board();
};

#endif //TALLERZ_SIDE_BOARD_H
