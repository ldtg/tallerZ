//
// Created by darius on 23/05/17.
//

#ifndef TALLERZ_MENU_H
#define TALLERZ_MENU_H

#include <SDL2/SDL_pixels.h>
#include <SDL_ttf.h>
#include <string>
#include <view/Texture.h>
#include "Exceptions/Sdl_Exceptions/Sdl_Exception.h"


/**
 * @class Menu: clase madre (@virtual) de la que heredan los distintos menus del juego.
 */
class Menu {
 protected:
  SDL_Rect renderQuad;
  Texture * background;
 public:
  virtual void displace_toXY(int coorX, int coordY) = 0;

 protected:
  Menu(){}

  virtual void load_items() = 0;

  void set_absolute_position(SDL_Rect& rect, SDL_Rect& rect_abs);

  Position get_relative_pos(const SDL_Rect &item_rect);
};

#endif //TALLERZ_MENU_H
