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
  Image(const char *file, int width, int height);
  Image(Image &&other);
  Image& operator=(Image &&other);
  ~Image();
  void set_texture(SDL_Renderer *render);
  void draw(SDL_Renderer *render);
};

#endif //IMAGE_H
