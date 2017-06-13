//
// Created by darius on 24/05/17.
//

#include "Build_Button.h"
#include <client/front_end/SDL_Interface/Menus/Production/Production_Menu.h>

void Build_Button::button_launch() {
  this->menu->update_unit_to_build();
}
Build_Button::Build_Button(Window *window, Model *model, Production_Menu *menu, const SDL_Rect &rect) {
  this->window = window;
  this->model = model;
  this->menu = menu;
  this->renderQuad = rect;
  this->load_texture_up(path_up);
  this->load_texture_down(path_down);
}
