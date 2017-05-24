//
// Created by darius on 23/05/17.
//

#ifndef TALLERZ_LABEL_H
#define TALLERZ_LABEL_H

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_ttf.h>
#include <view/Texture.h>
#include <Exceptions/Sdl_Exceptions/Sdl_Exception.h>

//TODO poner bien los colores
enum Color {
  COLOR1, COLOR2
};

/**
 * @class Label
 * "Etiqueta". Objeto no clickeable pero que muestra información.
 */
class Label {
 private:
  const std::string font_path = "../src/front_end/fonts/BEBAS.ttf";
 protected:
  Window& window;
  TTF_Font *font = NULL;
  SDL_Surface * surface;
  const SDL_Color color1 = {0xFF, 0xB8, 0x1D, 0x2D};
  const SDL_Color color2 = {0xFF, 0xFF, 0x3C, 0x00};
  SDL_Rect sdl_rect;
  std::string text;
  Texture * texture;
 public:
  Label(Window& window, const std::string &text, const SDL_Rect &rect);

  ~Label();

  void displace_toXY(int coordX, int coordY);

  void modify_text(const std::string& newText, Color color);

  //TODO void swap_text_color();

 private:
  void load_font();

};

#endif //TALLERZ_LABEL_H
