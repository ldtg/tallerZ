#ifndef IMAGE_H
#define IMAGE_H

#include <SDL2/SDL.h>
#include "ObjectView.h"

/**
 * @class Image
 * Modela una sola imagen. Se utiliza para encapsular la clase SDL_Texture
 * de SDL haciendo uso del patrón de diseño RAII.
 */
class Image : public ObjectView {
 private:
  SDL_Surface *surface;
  SDL_Texture *texture;

 public:
  Image();
  Image(const char *file);
  virtual ~Image();
  void scale(float scaleW, float scaleH);
  void set_texture(SDL_Renderer *render);
  void draw(SDL_Renderer *render, Camera &camera);
};

#endif //IMAGE_H
