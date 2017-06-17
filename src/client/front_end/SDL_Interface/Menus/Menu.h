//
// Created by darius on 23/05/17.
//

#ifndef TALLERZ_MENU_H
#define TALLERZ_MENU_H

#include <SDL2/SDL_pixels.h>
#include <SDL_ttf.h>
#include <string>
#include <client/view/Texture.h>
#include "Exceptions/Sdl_Exceptions/Sdl_Exception.h"
#include <client/view/ObjectMapaVista.h>
#include <client/view/Panel.h>

/**
 * @class Menu: clase madre (@virtual) de la que heredan los distintos menus del juego.
 */
class Menu : public ObjectMapaVista {
  const std::string font_path = "../src/client/front_end/fonts/BEBAS.ttf";
 protected:
  SDL_Rect renderQuad;
  Texture * background;
  TTF_Font *font = NULL;

 public:
  Menu();
  ~Menu();
  bool isInRectangle(int x, int y){
    return ( x > renderQuad.x
        && x < (renderQuad.x + renderQuad.w)
        && y > renderQuad.y
        && y < (renderQuad.y + renderQuad.h));
  }
  void scale(float scaleW, float scaleH){};
  virtual void handle_click(int x, int y) = 0;
  //virtual void displace_toXY(int coorX, int coordY) = 0;
  virtual void add_to_panel(Panel& panel) = 0;

 protected:
  virtual void set_texture(SDL_Renderer *render){};
  virtual void draw(SDL_Renderer *render, Camera &camera){
    SDL_RenderCopy(render, background->get_texture(), NULL, &renderQuad);
  }

  virtual void load_items() = 0;
  void set_absolute_position(SDL_Rect& rect, SDL_Rect& rect_abs);
  Position get_relative_pos(const SDL_Rect &item_rect);
  void load_font();
};

#endif //TALLERZ_MENU_H
