//
// Created by darius on 23/05/17.
//

#ifndef TALLERZ_LABEL_H
#define TALLERZ_LABEL_H

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_ttf.h>
#include <client/view/Texture.h>
#include <Exceptions/Sdl_Exceptions/Sdl_Exception.h>
#include <client/view/ObjectMapaVista.h>

/**
 * @class Label
 * "Etiqueta". Objeto no clickeable pero que muestra información.
 * Los labels están diseñados para usar una única fuente situada en el
 * archivo "../src/front_end/fonts/BEBAS.ttf"
 * Label por defecto tiene fondo transparente pero si modificamos el texto
 * se sobreescribe sobre un fondo negro.
 */
class Label : public ObjectMapaVista{
 private:
  //TODO borrar esta linea siguiente cuando la fuente esté inicializada afuera y pasar como parámetro al constructor
 protected:
  Window& window;
  std::string text;
  TTF_Font *font = NULL;
  SDL_Surface * surface;
  SDL_Rect renderQuad;
  Texture * texture;

  const SDL_Color color = {0xFF, 0xFF, 0xFF, 0xFF}; //blanco

 public:
  Label(Window& window, const std::string &text, const SDL_Rect &rect, TTF_Font *font);

  virtual ~Label();

  SDL_Rect get_rectangle();

  void set_rectangle(const SDL_Rect& rect);

  void displace_toXY(int coordX, int coordY);

  void modify_text(const std::string& text);

  void reload();

  void scale(float scaleW, float scaleH){};

  void set_texture(SDL_Renderer *render){};

  void draw(SDL_Renderer *render, Camera &camera){
    SDL_RenderCopy(render, texture->get_texture(), NULL, &renderQuad);
  };
};

#endif //TALLERZ_LABEL_H
