#ifndef TALLERZ_CLIENTE_OK_BUTTON_H
#define TALLERZ_CLIENTE_OK_BUTTON_H

#include <client/front_end/SDL_Interface/Buttons/Button.h>
#include <client/view/View.h>

class Ok_Button : public Button{
 private:
  const std::string path_up =
      "../src/client/front_end/Images/Interface/result_gui/ok_button.png";
  const std::string path_down =
      "../src/client/front_end/Images/Interface/result_gui/ok_button_pressed.png";
  View& view;
 public:
  Ok_Button(MainWindow * window, View& view, const SDL_Rect& rect);

  void button_launch() override ;
};

#endif //TALLERZ_CLIENTE_OK_BUTTON_H
