#ifndef TALLERZ_TEXTURE_H
#define TALLERZ_TEXTURE_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "MainWindow.h"
#include "ObjectView.h"

/**
 * @class Texture:
 * esta pensado para cargar texturas a partir de imagenes o directamente
 * a partir de superficies (util para texto)
 * y encapsular la cuestión de renderizado. Pasándole los parámetros
 * adecuados al constructor y ejecutando una de las dos funciones
 * renderize de manera adecuada debería mostrarse la textura en pantalla.
 * En algún caso extraño se puede posteriormente con load_texture modificar
 * la textura y renderizar de nuevo.
 */
class Texture : public ObjectView{
 private:
  SDL_Texture * texture;
  SDL_Rect renderQuad;
 public:
  Texture(const std::string& path, const MainWindow * window);

  Texture(const std::string& path, const MainWindow * window, const SDL_Rect& rect);

  Texture(SDL_Surface* surface, const MainWindow * window);

  Texture(const MainWindow * window);

  ~Texture();

  void load_texture(const std::string& path, SDL_Window * window);

  void renderize(const MainWindow * window);

  void renderize(const MainWindow * window, const SDL_Rect* renderQuad);

  SDL_Texture * get_texture() const;

  virtual void scale(float scaleW, float scaleH){};
  virtual void set_texture(SDL_Renderer *render){};
  virtual void draw(SDL_Renderer *render, Camera &camera){
    SDL_RenderCopy(render, texture, NULL, &renderQuad);
  };

 private:
  SDL_Surface * load_image(const std::string& path);

  void generate_texture(SDL_Surface * surface, SDL_Window * window);
};

#endif //TALLERZ_TEXTURE_H
