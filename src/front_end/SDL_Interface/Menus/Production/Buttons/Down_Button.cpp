//
// Created by darius on 25/05/17.
//

#include "Down_Button.h"

Down_Button::Down_Button(Window *window, const SDL_Rect &rect) {
  this->window = window;
  this->renderQuad = rect;
  this->load_texture_up(path_up);
  this->load_texture_down(path_down);
}
void Down_Button::button_launch() {
  //TODO implementar logica de boton abajo: mostrar otra unidad seleccionable para la producción.
}
