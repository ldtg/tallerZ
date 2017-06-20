#ifndef IMAGE_H
#define IMAGE_H

#include <SDL2/SDL.h>
#include "ObjectMapaVista.h"

class Image : public ObjectMapaVista {
 private:
  SDL_Surface *surface;
  SDL_Texture *texture;

 public:
  Image();
  Image(const char *file);
  ~Image();
  void scale(float scaleW, float scaleH);
  void set_texture(SDL_Renderer *render);
  void draw(SDL_Renderer *render, Camera &camera);
};

#endif //IMAGE_H
