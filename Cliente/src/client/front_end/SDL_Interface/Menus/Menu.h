#ifndef TALLERZ_MENU_H
#define TALLERZ_MENU_H

#include <SDL2/SDL_pixels.h>
#include <SDL_ttf.h>
#include <string>
#include <client/view/Texture.h>
#include "Exceptions/Sdl_Exceptions/Sdl_Exception.h"
#include <client/view/ObjectView.h>

/**
 * @class Menu: clase madre (@virtual) de la que heredan los distintos menus del juego.
 */
class Menu : public ObjectView {
  const std::string font_path = "../src/client/front_end/fonts/BEBAS.ttf";
 protected:
  SDL_Rect renderQuad;
  Texture *background;
  TTF_Font *font = NULL;

 public:
  Menu();

  virtual ~Menu();

  bool isInRectangle(int x, int y);

  void scale(float scaleW, float scaleH){};

  virtual void handle_click(int x, int y) = 0;

  virtual void draw(SDL_Renderer *render, Camera &camera);

 protected:
  virtual void set_texture(SDL_Renderer *render) {};

  virtual void load_items() = 0;

  void set_absolute_position(SDL_Rect &rect, SDL_Rect &rect_abs);

  Position get_relative_pos(const SDL_Rect &item_rect);

  void load_font();
};

#endif //TALLERZ_MENU_H
