#include <SDL2/SDL_image.h>
#include <iostream>
#include "Image.h"

Image::Image() {}

Image::Image(const char *file) {
    surface = IMG_Load(file);
    if (surface == NULL)
        std::cout << file << std::endl;

    width = surface->w;
    height = surface->h;

  texture = nullptr;

//    std::cout << "width: " << width
//              << " height: " << height << std::endl;
}

Image::Image(const char *file, int w, int h) {
    surface = IMG_Load(file);
    this->width = w;
    this->height = h;
}

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

Image::~Image() {
    if (!surface) {
        SDL_FreeSurface(surface);
    }
    if (!texture) {
        SDL_DestroyTexture(texture);
    }
}

void Image::set_texture(SDL_Renderer *render) {
    if (texture != nullptr) {
      SDL_DestroyTexture(texture);
    }
    texture = SDL_CreateTextureFromSurface(render, surface);
}

void Image::draw(SDL_Renderer *render) {

    SDL_Rect renderQuad = { x, y, width, height };

    SDL_RenderCopy(render, texture, NULL, &renderQuad);
}

/*
void Image::draw(SDL_Renderer *render, int window_w, int window_h,
                 int x, int y) {

//    int x_aux = x + (window_w - clip->w)/2;
//    int y_aux = y + (window_h - clip->h)/2;

    SDL_Rect sdl_rect = {x, y, width, height};
    SDL_RenderCopy(render, side_board_texture, NULL, &sdl_rect);
}
*/
