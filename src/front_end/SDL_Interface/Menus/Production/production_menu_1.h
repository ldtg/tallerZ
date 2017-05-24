//
// Created by darius on 23/05/17.
//

#ifndef TALLERZ_PRODUCTION_MENU_1_H
#define TALLERZ_PRODUCTION_MENU_1_H

//ok, cancel, porcntaje de vida de la fabrica, barra de tiempo, tiempo, boton + para expandir, sprite de la unidad
//dos situaciones, Building o Select, en building la barrita de arriba de vuelve verde y titila building
//en select esta gris y nada.
#include <string>
#include <front_end/SDL_Interface/Buttons/Button.h>
#include <SDL2/SDL_ttf.h>
#include <front_end/SDL_Interface/Menus/Menu.h>
#include <front_end/SDL_Interface/Labels/Label.h>
class production_menu_1 : public Menu {
 private:
  Window &window;

  const std::string background_path
      = "../src/front_end/Images/Interface/production_gui/base_image.png";
  //Button ok, cancel, expand;
  Texture * background = NULL;
  Label * time = NULL;
  Label *status = NULL;
  Label *health = NULL;
  Label *unit = NULL;
  Label *building_name = NULL;
  bool building_status;

 public:
  //TODO pasarle fabrica y desharcodear
  production_menu_1(Window &window) : window(window) {
    this->background = new Texture(background_path.c_str(), &window);
    this->building_status = false;
    this->time = new Label(window, "01:00", {90,35,16,8});
    this->status = new Label(window, "Select", {90, 35, 16, 8});
    this->health = new Label(window, "100%", {75, 7, 20, 8});
    this->building_name = new Label(window, "Factory", {7, 7, 65, 9});
    this->unit = new Label(window, "Robot", {7, 61, 41, 9});
  }

  ~production_menu_1(){
    delete this->time;
    delete this->status;
    delete this->health;
    delete this->unit;
    delete this->background;
    delete this->building_name;
  }
};

#endif //TALLERZ_PRODUCTION_MENU_1_H
