//
// Created by darius on 23/05/17.
//

#ifndef TALLERZ_LABEL_H
#define TALLERZ_LABEL_H

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_ttf.h>
#include <client/view/Texture.h>
#include <Exceptions/Sdl_Exceptions/Sdl_Exception.h>

/**
 * @class Label
 * "Etiqueta". Objeto no clickeable pero que muestra información.
 * Los labels están diseñados para usar una única fuente situada en el
 * archivo "../src/front_end/fonts/BEBAS.ttf"
 * Label por defecto tiene fondo transparente pero si modificamos el texto
 * se sobreescribe sobre un fondo negro.
 */
class Label {
 private:
  //TODO borrar esta linea siguiente cuando la fuente esté inicializada afuera y pasar como parámetro al constructor
  const std::string font_path = "../src/front_end/fonts/BEBAS.ttf";
 protected:
  Window& window;
  std::string text;
  TTF_Font *font = NULL;
  SDL_Surface * surface;
  SDL_Rect renderQuad;
  Texture * texture;

  const SDL_Color color = {0xFF, 0xFF, 0xFF, 0xFF}; //blanco

 public:
  Label(Window& window, const std::string &text, const SDL_Rect &rect);

  ~Label();

  SDL_Rect get_rectangle();

  void set_rectangle(const SDL_Rect& rect);

  void displace_toXY(int coordX, int coordY);

  void modify_text(const std::string& text);

  void reload();
 private:

  void load_font();
};

#endif //TALLERZ_LABEL_H
