//
// Created by darius on 23/05/17.
//

#ifndef TALLERZ_MAIN_MENU_H
#define TALLERZ_MAIN_MENU_H

#include <string>
#include <client/front_end/SDL_Interface/Menus/Menu.h>
#include <client/front_end/SDL_Interface/Buttons/Button.h>
#include <client/view/View.h>
#include <client/front_end/SDL_Interface/Menus/Quit/Buttons/Salir_Button.h>

class Quit_Menu : public Menu {
 private:
  MainWindow &window;
  View& view;
  Button * salir = NULL;

  SDL_Rect salir_b_rect;
  SDL_Rect _salir_b_rect = {36,40,38,14};

  const std::string background_path
      = "../src/client/front_end/Images/Interface/quit_gui/quit_menu.png";

 public:
  Quit_Menu(MainWindow& window, View& view);

  void handle_click(int x, int y);

  void draw(SDL_Renderer *render, Camera &camera);

  virtual ~Quit_Menu();
 private:
  void load_items();
};

#endif //TALLERZ_MAIN_MENU_H
