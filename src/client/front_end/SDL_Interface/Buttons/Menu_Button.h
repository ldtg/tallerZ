//
// Created by darius on 22/05/17.
//

#ifndef TALLERZ_MENU_BUTTON_H
#define TALLERZ_MENU_BUTTON_H

#include "Button.h"
class Menu_Button : public Button {
 private:
  const SDL_Rect renderQuad = {481, 458, 56, 20};
  const std::string path_up =
      "../src/client/front_end/Images/Interface/menu_button_active.bmp";
  const std::string path_down =
      "../src/client/front_end/Images/Interface/menu_button_pressed.bmp";
 public:
  Menu_Button(Window * window);

  SDL_Rect get_rect();
 protected:
  void button_launch();
};

#endif //TALLERZ_MENU_BUTTON_H
