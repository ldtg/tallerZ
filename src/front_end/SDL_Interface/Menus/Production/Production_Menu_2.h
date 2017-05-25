//
// Created by darius on 24/05/17.
//

#ifndef TALLERZ_PRODUCTION_MENU_2_H
#define TALLERZ_PRODUCTION_MENU_2_H

#include <SDL2/SDL_rect.h>
#include <view/Window.h>
#include <front_end/SDL_Interface/Labels/Label.h>
#include <front_end/SDL_Interface/Buttons/Button.h>
#include <front_end/SDL_Interface/Menus/Menu.h>
#include <front_end/SDL_Interface/Menus/Production/Buttons/Up_Button.h>
#include <front_end/SDL_Interface/Menus/Production/Buttons/Down_Button.h>
#include <front_end/SDL_Interface/Menus/Production/Buttons/Add_Button.h>
class Production_Menu_2 : public Menu {
 private:
  const int width = 118;
  const int length = 96;
  Window &window;

  Label *unit = NULL;
  Button * up = NULL;
  Button * down = NULL;
  Button * add = NULL;

  SDL_Rect _unit_rect = {6, 61, 40, 9};
  SDL_Rect _up_rect = {50, 21, 11, 11};
  SDL_Rect _down_rect = {50, 62, 11, 11};
  SDL_Rect _add_rect = {1, 77, 60, 13};

  SDL_Rect unit_rect;
  SDL_Rect up_rect;
  SDL_Rect down_rect;
  SDL_Rect add_rect;

  const std::string background_path
      = "../src/front_end/Images/Interface/production_gui/base_image_expansion.png";

 public:
  Production_Menu_2(Window &window, int x, int y);

  void displace_toXY(int x, int y);

 private:
  void load_items(){
    set_absolute_position(_unit_rect, unit_rect);
    this->unit = new Label(window, "Grunt", unit_rect);

    set_absolute_position(_up_rect, up_rect);
    this->up = new Up_Button(&window, up_rect);

    set_absolute_position(_down_rect, down_rect);
    this->down = new Down_Button(&window, down_rect);

    set_absolute_position(_add_rect, add_rect);
    this->add = new Add_Button(&window, add_rect);
  }
};

#endif //TALLERZ_PRODUCTION_MENU_2_H
