//
// Created by darius on 22/05/17.
//

#include <iostream>
#include "Menu_Button.h"
/**
 * Constructor
 * @param window : Ventana sobre la que se aplica el renderizado
 */
Menu_Button::Menu_Button(Window *window) {
  this->window = window;
  this->set_rectangle(coordX, coordY, width, length);
  this->load_texture_up(path_up);
  this->load_texture_down(path_down);
}
/**
 * button_launch
 */
void Menu_Button::button_launch() {
  std::cout << "boton apretado\n";
}
