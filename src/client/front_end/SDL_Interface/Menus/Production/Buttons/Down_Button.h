//
// Created by darius on 25/05/17.
//

#ifndef TALLERZ_DOWN_BUTTON_H
#define TALLERZ_DOWN_BUTTON_H

#include <client/front_end/SDL_Interface/Buttons/Button.h>
/**
 * @class Down_Button : boton abajo para la seleccion de unidades en el menu
 * de produccion expandido.
 */
class Down_Button : public Button {
  const std::string path_up =
      "../src/client/front_end/Images/Interface/production_gui/down_button.png";
  const std::string path_down =
      "../src/client/front_end/Images/Interface/production_gui/down_button_pressed.png";

 public:
  Down_Button(Window * window, const SDL_Rect& rect);

  void button_launch() override ;
};
#endif //TALLERZ_DOWN_BUTTON_H
