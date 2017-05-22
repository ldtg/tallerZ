//
// Created by darius on 22/05/17.
//

#ifndef TALLERZ_MENU_BUTTON_H
#define TALLERZ_MENU_BUTTON_H

#include "Button.h"
class Menu_Button : public Button {
 public:
  Menu_Button(Window * window){
    this->window = window;
    this->load_texture_up(
        "../src/front_end/Images/Interface/menu_button_active.bmp");
    this->load_texture_down(
        "../src/front_end/Images/Interface/menu_button_pressed.bmp");
    this->set_position(80,80);
  }

};

#endif //TALLERZ_MENU_BUTTON_H
