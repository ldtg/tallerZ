//
// Created by darius on 18/06/17.
//

#ifndef TALLERZ_CLIENTE_DEFEAT_H
#define TALLERZ_CLIENTE_DEFEAT_H

#include <client/view/Window.h>
#include <client/view/View.h>
#include <client/front_end/SDL_Interface/Menus/Result/Buttons/Ok_Button.h>

class Defeat : public Menu {
 private:
  Window &window;
  View& view;
  Button * ok = NULL;
  SDL_Rect ok_b_rect;
  SDL_Rect _ok_b_rect = {94,101,38,14};

  const std::string background_path
      = "../src/client/front_end/Images/Interface/result_gui/you_lose.png";

 public:
  Defeat(Window& window, View& view);

  void handle_click(int x, int y);

  void add_to_panel(Panel& panel) override{
    panel.add(this);
    panel.add(ok);
  }
  virtual ~Defeat();
 private:
  void load_items();
};

#endif //TALLERZ_CLIENTE_DEFEAT_H
