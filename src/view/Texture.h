//
// Created by darius on 21/05/17.
//

#ifndef TALLERZ_TEXTURE_H
#define TALLERZ_TEXTURE_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Window.h"
class Texture {
 private:
  SDL_Texture * texture;

 public:
  Texture(const std::string& path, const Window * window);

  void load_texture(const std::string& path, SDL_Window * window);

  void renderize(const Window * window);
  void renderize(const Window * window, const SDL_Rect* renderQuad);

  SDL_Texture * get_texture() const;

 private:
  SDL_Surface * load_image(const std::string& path);
};

#endif //TALLERZ_TEXTURE_H
