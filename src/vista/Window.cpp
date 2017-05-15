#include "Window.h"
#include <SDL2/SDL_image.h>
#include <iostream>

#define WIDTH 1366
#define HEIGHT 768

Window::Window() {
    width = WIDTH;
    height = HEIGHT;

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    window = SDL_CreateWindow("SDL Tutorial", 0, 0,
                              width,
                              height,
                              SDL_WINDOW_SHOWN);
    window_render = SDL_CreateRenderer(window, -1,
                    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(window_render, 0xFF, 0xFF, 0xFF, 0xFF);
}

Window::~Window() {
//    SDL_DestroyRenderer(window_render);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();
}

SDL_Renderer* Window::getRender() const {
    return window_render;
}
