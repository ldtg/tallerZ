//
// Created by darius on 23/05/17.
//

#ifndef TALLERZ_PRODUCTION_MENU_1_H
#define TALLERZ_PRODUCTION_MENU_1_H

#include <string>
#include <SDL2/SDL_ttf.h>
#include <front_end/SDL_Interface/Buttons/Button.h>
#include <front_end/SDL_Interface/Menus/Menu.h>
#include <front_end/SDL_Interface/Labels/Label.h>
#include "model/Position.h"

class Production_Menu_1 : public Menu {
 private:
  const int width = 111;
  const int length = 79;
  Window &window;
  Texture * background = NULL;
  Label * time = NULL;
  Label *status = NULL;
  Label *health = NULL;
  Label *unit = NULL;
  Label *building_name = NULL;
  Button * ok = NULL;
  Button * expand = NULL;
  Button * cancel = NULL;

  SDL_Rect time_rect;
  SDL_Rect unit_rect;
  SDL_Rect health_rect;
  SDL_Rect status_rect;
  SDL_Rect building_name_rect;
  SDL_Rect expand_b_rect;
  SDL_Rect cancel_b_rect;
  SDL_Rect ok_b_rect;

  const std::string background_path
      = "../src/front_end/Images/Interface/production_gui/base_image.png";

 public:
  //TODO pasarle fabrica y desharcodear
  Production_Menu_1(Window &window, int x, int y);

  void displace_toXY(int x, int y);

  void show_health_level(int health);

  void show_select_status();

  void show_building_status();

  ~Production_Menu_1();

 private:
  void load_items();

  void set_absolute_position(SDL_Rect& rect, SDL_Rect& rect_abs);

};

#endif //TALLERZ_PRODUCTION_MENU_1_H
