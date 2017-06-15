#include <SDL2/SDL_image.h>
#include <iostream>
#include "Image.h"

Image::Image() {}

Image::Image(const char *file) {
  surface = IMG_Load(file);
  if (surface == NULL)
    std::cerr << file << std::endl;

  width = surface->w;
  height = surface->h;

  texture = nullptr;
}

Image::Image(const char *file, int w, int h) {
    surface = IMG_Load(file);
    this->width = w;
    this->height = h;
}

/*
Image::Image(Image &&other) {
    this->surface = other.surface;
    this->texture = other.texture;
    this->width = other.width;
    this->height = other.height;

    other.surface = NULL;
    other.texture = NULL;
    other.width = 0;
    other.height = 0;
}

Image& Image::operator=(Image &&other) {
    this->surface = other.surface;
    this->texture = other.texture;
    this->width = other.width;
    this->height = other.height;

    other.surface = NULL;
    other.texture = NULL;
    other.width = 0;
    other.height = 0;

    return *this;
}
*/

Image::~Image() {
    if (surface != nullptr) {
        SDL_FreeSurface(surface);
    }
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
}

void Image::set_texture(SDL_Renderer *render) {
  if (texture != nullptr) {
//      SDL_DestroyTexture(texture);
  } else {
    texture = SDL_CreateTextureFromSurface(render, surface);
  }
}

void Image::draw(SDL_Renderer *render, Camera &camera) {
//  x - camera->x;
//  y - camera->y;

// TODO: dibujar imagen solo si esta dentro de la camera.
  if (camera.x <= x+width && x <= camera.x+camera.w &&
      camera.y <= y+height && y <= camera.y+camera.h) {
    SDL_Rect renderQuad = { (int)x - camera.x, (int)y- camera.y, width, height };

    SDL_RenderCopy(render, texture, NULL, &renderQuad);
  }
}
