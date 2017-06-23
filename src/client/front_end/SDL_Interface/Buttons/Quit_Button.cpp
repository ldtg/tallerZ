//
// Created by darius on 22/05/17.
//

#include <iostream>
#include "Quit_Button.h"
#include <client/view/View.h>

/**
 * button_launch
 */
void Quit_Button::button_launch() {
  view.load_quit_menu();
}
Quit_Button::Quit_Button(Window *window, View &view) : view(view) {
  renderQuad = {633, 574, 56, 20};
  this->window = window;
  this->load_texture_up(path_up);
  this->load_texture_down(path_down);
}

