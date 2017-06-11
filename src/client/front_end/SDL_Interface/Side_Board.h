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
#include <client/front_end/SDL_Interface/Buttons/Menu_Button.h>

class Side_Board : public ObjectMapaVista{
 private:
  const std::string path = "../src/client/front_end/Images/Interface/interface.png";

  Menu_Button * menu_button;
  Texture * side_board_texture;

 public:
  Side_Board(Window * window);

  ~Side_Board();

  void load_side_board(Window * window);

  void load_items(){

  }
  Texture *get_side_board();

  void add_to_panel(Panel& panel){
    panel.add(this);
    panel.add(menu_button);
  };

  virtual void set_texture(SDL_Renderer *render){};

  virtual void draw(SDL_Renderer *render, Camera &camera){
    SDL_RenderCopy(render, side_board_texture->get_texture(), NULL, NULL);
  }
};

#endif //TALLERZ_SIDE_BOARD_H
