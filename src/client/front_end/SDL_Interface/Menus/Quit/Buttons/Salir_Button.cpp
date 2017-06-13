//
// Created by darius on 24/05/17.
//

#include "Salir_Button.h"
void Salir_Button::button_launch() {
  this->view.setQuit();
}

Salir_Button::Salir_Button(Window * window,
                           View& view,
                           const SDL_Rect& rect): view(view){
  this->window = window;
  this->renderQuad = rect;
  this->load_texture_up(path_up);
  this->load_texture_down(path_down);
}
