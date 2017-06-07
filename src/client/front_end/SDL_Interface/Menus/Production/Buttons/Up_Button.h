//
// Created by darius on 25/05/17.
//

#ifndef TALLERZ_UP_BUTTON_H
#define TALLERZ_UP_BUTTON_H

#include <client/front_end/SDL_Interface/Buttons/Button.h>
/**
 * @class Up_Button : boton arriba para la seleccion de unidades en el menu
 * de produccion expandido.
 */
class Up_Button : public Button {
  const std::string path_up =
      "../src/front_end/Images/Interface/production_gui/up_button.png";
  const std::string path_down =
      "../src/front_end/Images/Interface/production_gui/up_button_pressed.png";

 public:
  Up_Button(Window * window, const SDL_Rect& rect){
    this->window = window;
    this->renderQuad = rect;
    this->load_texture_up(path_up);
    this->load_texture_down(path_down);
  }

  void button_launch() override ;
};

#endif //TALLERZ_UP_BUTTON_H
