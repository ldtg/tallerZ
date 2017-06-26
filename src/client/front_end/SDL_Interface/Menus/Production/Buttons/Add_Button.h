//
// Created by darius on 25/05/17.
//

#ifndef TALLERZ_ADD_BUTTON_H
#define TALLERZ_ADD_BUTTON_H

#include <client/front_end/SDL_Interface/Buttons/Button.h>
class Production_Menu;
/**
 * @class Add_Button: boton de añadir unidad a producir en el menu expandido de producción.
 */
class Add_Button : public Button{
 private:
  const std::string path_up =
      "../src/client/front_end/Images/Interface/production_gui/queue_button.png";
  const std::string path_down =
      "../src/client/front_end/Images/Interface/production_gui/queue_button_pressed.png";
  Production_Menu * menu;
 public:
  Add_Button(MainWindow * window, Model * model, Production_Menu * menu, const SDL_Rect& rect){
    this->window = window;
    this->model = model;
    this->menu = menu;
    this->renderQuad = rect;
    this->load_texture_up(path_up);
    this->load_texture_down(path_down);
  }

  void button_launch() override ;
};
#endif //TALLERZ_ADD_BUTTON_H
