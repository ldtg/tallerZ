//
// Created by darius on 24/05/17.
//

#ifndef TALLERZ_QUIT_BUTTON_H
#define TALLERZ_QUIT_BUTTON_H

#include <client/front_end/SDL_Interface/Buttons/Button.h>
#include <client/view/View.h>
class Salir_Button : public Button{
 private:
  const std::string path_up =
      "../src/client/front_end/Images/Interface/quit_gui/salir_button.png";
  const std::string path_down =
      "../src/client/front_end/Images/Interface/quit_gui/salir_button_pressed.png";
  View& view;
 public:
  Salir_Button(MainWindow * window, View& view, const SDL_Rect& rect);

  void button_launch() override ;
};

#endif //TALLERZ_QUIT_BUTTON_H
