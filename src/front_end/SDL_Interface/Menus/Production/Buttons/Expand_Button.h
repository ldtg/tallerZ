//
// Created by darius on 24/05/17.
//

#ifndef TALLERZ_EXPAND_BUTTON_H
#define TALLERZ_EXPAND_BUTTON_H

#include <view/Window.h>
#include <string>
#include "front_end/SDL_Interface/Buttons/Button.h"
class Expand_Button : public Button{
  const std::string path_up =
      "../src/front_end/Images/Interface/production_gui/plus_small_button.png";
  const std::string path_down =
      "../src/front_end/Images/Interface/production_gui/plus_small_button_pressed.png";

 public:
  Expand_Button(Window * window, const SDL_Rect& rect){
    this->window = window;
    this->renderQuad = rect;
    this->load_texture_up(path_up);
    this->load_texture_down(path_down);
  }

  void button_launch() override ;
};

#endif //TALLERZ_EXPAND_BUTTON_H
