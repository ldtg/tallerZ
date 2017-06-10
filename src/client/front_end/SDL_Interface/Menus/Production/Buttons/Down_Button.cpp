//
// Created by darius on 25/05/17.
//

#include "Down_Button.h"
#include <client/model/Model.h>

Down_Button::Down_Button(Window *window, Model * model, Production_Menu * menu, const SDL_Rect &rect) {
  this->window = window;
  this->model = model;
  this->menu = menu;
  this->renderQuad = rect;
  this->load_texture_up(path_up);
  this->load_texture_down(path_down);
}
void Down_Button::button_launch() {
  menu->show_next_buildable_unit();
}
