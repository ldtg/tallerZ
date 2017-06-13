//
// Created by darius on 22/05/17.
//

#ifndef TALLERZ_MENU_BUTTON_H
#define TALLERZ_MENU_BUTTON_H

#include "Button.h"
class View;

class Quit_Button : public Button {
 private:
  View& view;
  const std::string path_up =
      "../src/client/front_end/Images/Interface/quit_button_active.bmp";
  const std::string path_down =
      "../src/client/front_end/Images/Interface/quit_button_pressed.bmp";

 public:
  Quit_Button(Window * window, View& view) : view(view){
    renderQuad = {635, 573, 56, 20};
    this->window = window;
    this->load_texture_up(path_up);
    this->load_texture_down(path_down);
  }

  void button_launch() override;
};

#endif //TALLERZ_MENU_BUTTON_H
