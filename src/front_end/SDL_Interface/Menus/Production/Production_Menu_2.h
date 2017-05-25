//
// Created by darius on 24/05/17.
//

#ifndef TALLERZ_PRODUCTION_MENU_2_H
#define TALLERZ_PRODUCTION_MENU_2_H

#include <SDL2/SDL_rect.h>
#include <view/Window.h>
#include <front_end/SDL_Interface/Labels/Label.h>
class Production_Menu_2 {
 private:
  const int width = 118;
  const int length = 96;
  Window &window;
  SDL_Rect renderQuad = { 0, 0, width, length};
  Label *unit = NULL;
};

#endif //TALLERZ_PRODUCTION_MENU_2_H
