//
// Created by darius on 22/05/17.
//

#ifndef TALLERZ_MENU_BUTTON_H
#define TALLERZ_MENU_BUTTON_H

#include "Button.h"
class Menu_Button : public Button {
 private:
  const int width = 56;
  const int length = 20;
  const int coordY = 458;
  const int coordX = 481;
  const std::string path_up =
      "../src/front_end/Images/Interface/menu_button_active.bmp";
  const std::string path_down =
      "../src/front_end/Images/Interface/menu_button_pressed.bmp";
 public:
  Menu_Button(Window * window);

 protected:
  void button_launch();
};

#endif //TALLERZ_MENU_BUTTON_H
