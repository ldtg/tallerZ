//
// Created by darius on 18/06/17.
//

#include "Ok_Button.h"
Ok_Button::Ok_Button(Window *window, View &view, const SDL_Rect &rect) : view(view){
  this->window = window;
  this->renderQuad = rect;
  this->load_texture_up(path_up);
  this->load_texture_down(path_down);
}
void Ok_Button::button_launch() {
  this->view.free_menu();
}
