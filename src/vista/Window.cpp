#include "Window.h"
#include <SDL2/SDL_image.h>
#include <iostream>

#define WIDTH 640
#define HEIGHT 480

Window::Window() : image(), sprite() {
    width = WIDTH;
    height = HEIGHT;
    window = SDL_CreateWindow("SDL Tutorial", 0, 0,
                              width,
                              height,
                              SDL_WINDOW_SHOWN);
    window_render = SDL_CreateRenderer(window, -1,
                    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    SDL_SetRenderDrawColor(window_render, 0xFF, 0xFF, 0xFF, 0xFF);
//    screen_surface = SDL_GetWindowSurface(window);
}

Window::~Window() {
//    for (SDL_Texture *texture : textures) {
//        SDL_DestroyTexture(texture);
//    }

    SDL_DestroyRenderer(window_render);
    SDL_DestroyWindow(window);
}

void Window::load_image(Image image) {
    image.set_texture(window_render);
    this->image = std::move(image);
}

void Window::load_sprite(Sprite *sprite) {
    sprite->set_texture(window_render);
//    this->sprite = std::move(sprite);
    this->sprite = sprite;
}

void Window::draw() {
    SDL_SetRenderDrawColor(window_render, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear(window_render);
//    for (Image image : images) {
//        image.draw(window_render);
//    }

//    image.draw(window_render, width, height);
    sprite->draw(window_render, WIDTH, HEIGHT);
    SDL_RenderPresent(window_render);
 }
