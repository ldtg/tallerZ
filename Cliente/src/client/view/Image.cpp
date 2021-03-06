#include <SDL2/SDL_image.h>
#include <iostream>
#include "Image.h"

Image::Image() {}

Image::Image(const char *file) {
  surface = IMG_Load(file);
  if (surface == NULL) {
    std::string file_s(file);
    std::string msj = "Image::Image(const char *file) el path *"
        + file_s + "* es invalido";
    throw std::invalid_argument(msj.c_str());
  }
  width = surface->w;
  height = surface->h;

  texture = nullptr;
}

Image::~Image() {
    if (surface != nullptr) {
        SDL_FreeSurface(surface);
    }
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
}

void Image::scale(float scaleW, float scaleH) {
  width = (int)(width * scaleW);
  height = (int)(height * scaleH);
}

void Image::set_texture(SDL_Renderer *render) {
  if (texture == nullptr) {
    texture = SDL_CreateTextureFromSurface(render, surface);
  }
}

void Image::draw(SDL_Renderer *render, Camera &camera) {
  set_texture(render);

  // Dibujar imagen solo si esta dentro de la camera.
  if (camera.x <= x+width && x <= camera.x+camera.w &&
      camera.y <= y+height && y <= camera.y+camera.h) {

    SDL_Rect rectImage = { (int)x - camera.x, (int)y - camera.y, width, height };

    SDL_RenderCopyEx(render, texture, NULL, &rectImage, rotation, pointRot, SDL_FLIP_NONE);
  }
}
