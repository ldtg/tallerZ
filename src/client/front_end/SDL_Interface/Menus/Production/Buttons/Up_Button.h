//
// Created by darius on 25/05/17.
//

#ifndef TALLERZ_UP_BUTTON_H
#define TALLERZ_UP_BUTTON_H

#include <client/front_end/SDL_Interface/Buttons/Button.h>
class Production_Menu;

/**
 * @class Up_Button : boton arriba para la seleccion de unidades en el menu
 * de produccion expandido.
 */
class Up_Button : public Button {
  const std::string path_up =
      "../src/client/front_end/Images/Interface/production_gui/up_button.png";
  const std::string path_down =
      "../src/client/front_end/Images/Interface/production_gui/up_button_pressed.png";
  Production_Menu * menu;
 public:
  Up_Button(Window * window, Model * model, Production_Menu * menu, const SDL_Rect& rect){
    this->window = window;
    this->model = model;
    this->menu = menu;
    this->renderQuad = rect;
    this->load_texture_up(path_up);
    this->load_texture_down(path_down);
  }

  void button_launch() override ;
};

#endif //TALLERZ_UP_BUTTON_H
