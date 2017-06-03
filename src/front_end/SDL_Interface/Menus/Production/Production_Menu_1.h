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
  Production_Menu_2 * joint_menu = NULL;

  Label * time = NULL;
  Label *status = NULL;
  Label *health = NULL;
  Label *unit = NULL;
  Label *building_name = NULL;
  Button * ok = NULL;
  Button * cancel = NULL;
  Button * up = NULL;
  Button * down = NULL;

  SDL_Rect time_rect;
  SDL_Rect unit_rect;
  SDL_Rect health_rect;
  SDL_Rect status_rect;
  SDL_Rect building_name_rect;
  SDL_Rect cancel_b_rect;
  SDL_Rect ok_b_rect;
  SDL_Rect up_rect;
  SDL_Rect down_rect;

  SDL_Rect _time_rect = {87,33,18,10};
  SDL_Rect _unit_rect = {7, 61, 41, 9};
  SDL_Rect _health_rect = {73, 5, 20, 10};
  SDL_Rect _status_rect = {68, 20, 35, 10};
  SDL_Rect _building_name_rect = {5, 5, 65, 11};
  SDL_Rect _cancel_b_rect = {66, 46, 41, 14};
  SDL_Rect _ok_b_rect = {66, 60, 41, 14};
  SDL_Rect _up_rect = {50, 21, 13, 13};
  SDL_Rect _down_rect = {50, 62, 13, 13};

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

};

#endif //TALLERZ_PRODUCTION_MENU_1_H
