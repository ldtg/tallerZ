//
// Created by darius on 21/05/17.
//

#ifndef TALLERZ_SIDE_BOARD_H
#define TALLERZ_SIDE_BOARD_H

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <client/view/Window.h>
#include <client/view/Texture.h>
#include <client/view/ObjectMapaVista.h>
#include <client/view/Panel.h>
#include <client/front_end/SDL_Interface/Buttons/Quit_Button.h>
#include <client/front_end/SDL_Interface/Buttons/Button.h>
class View;
class Side_Board : public ObjectMapaVista{
 private:
  const std::string path = "../src/client/front_end/Images/Interface/interface.png";
  Window * window;
  View& view;
  Button * menu_button = NULL;
  Texture * side_board_texture = NULL;
  SDL_Rect renderQuad = {0,0,800, 600};
 public:
  Side_Board(Window * window, View& view);

  ~Side_Board();

  void load_side_board(Window * window);

  void load_items();

  Texture *get_side_board();

  bool is_in_menu_button(int x, int y);

  void launch_menu_button(){
    this->menu_button->handle_event();
  }
  void add_to_panel(Panel& panel);

  virtual void set_texture(SDL_Renderer *render){};

  virtual void draw(SDL_Renderer *render, Camera &camera){
    SDL_RenderCopy(render, side_board_texture->get_texture(), NULL, NULL);
  }
};

#endif //TALLERZ_SIDE_BOARD_H
