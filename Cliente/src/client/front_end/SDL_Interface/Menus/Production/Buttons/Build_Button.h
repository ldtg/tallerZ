#ifndef TALLERZ_OK_BUTTON_H
#define TALLERZ_OK_BUTTON_H

class Production_Menu;
#include <client/front_end/SDL_Interface/Buttons/Button.h>
class Build_Button : public Button{
 private:
  const std::string path_up =
      "../src/client/front_end/Images/Interface/production_gui/build_button.png";
  const std::string path_down =
      "../src/client/front_end/Images/Interface/production_gui/build_button_pressed.png";
  Production_Menu * menu;
 public:
  Build_Button(MainWindow * window, Model * model, Production_Menu * menu, const SDL_Rect& rect);

  void button_launch() override ;
};

#endif //TALLERZ_OK_BUTTON_H
