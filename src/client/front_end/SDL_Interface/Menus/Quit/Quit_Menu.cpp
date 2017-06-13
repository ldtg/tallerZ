//
// Created by darius on 23/05/17.
//
#include <client/front_end/SDL_Interface/Menus/Quit/Quit_Menu.h>

Quit_Menu::Quit_Menu(Window &window, View &view) : view(view), window(window) {
  this->renderQuad = {344,270,112,60};
  this->background = new Texture(background_path.c_str(), &window);
  this->background->renderize(&window, &renderQuad);
  this->load_items();
}
void Quit_Menu::load_items() {
  set_absolute_position(_salir_b_rect, this->salir_b_rect);
  this->salir = new Salir_Button(&window, view, salir_b_rect);
}
void Quit_Menu::handle_click(int x, int y) {
  if (salir->inRectangle(x,y)){
    salir->handle_event();
  }
}