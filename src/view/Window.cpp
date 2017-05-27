#include "Window.h"
#include <SDL2/SDL_image.h>
#include <iostream>
#include <Exceptions/Sdl_Exceptions/Sdl_Exception.h>

#define WIDTH 647
#define HEIGHT 484

Window::Window() {
    width = WIDTH;
    height = HEIGHT;

    //Las siguientes dos linas las pongo en SDL_START
    //SDL_Init(SDL_INIT_VIDEO);
    //IMG_Init(IMG_INIT_PNG);

    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    window = SDL_CreateWindow("tallerZ",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              width,
                              height,
                              SDL_WINDOW_SHOWN);
    if (window == NULL) {
      throw Sdl_Exception(
          "Error al crear ventana: no se pudo "
              "crar la ventana con SDL_CreateWindow: %s\n",SDL_GetError());
    }

    window_render = SDL_CreateRenderer(window, -1,
                    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (window_render == NULL) {
    throw Sdl_Exception(
        "Error al crear render de la ventana: no se pudo "
            "crear render con SDL_CreateRenderer: %s\n",SDL_GetError());
  }
    SDL_SetRenderDrawColor(window_render, 0xFF, 0xFF, 0xFF, 0xFF);
}

Window::~Window() {
    SDL_DestroyRenderer(window_render);
    SDL_DestroyWindow(window);

  //Lo mimsmo, las siguientes lineas las pongo en el destructor del SDL_START
    //IMG_Quit();
    //SDL_Quit();
  SDL_DestroyRenderer(window_render);
}

SDL_Renderer* Window::getRender() const {
    return window_render;
}

SDL_Window *Window::getWindow() const {
    return this->window;
}

void Window::update() {
    SDL_UpdateWindowSurface(this->window);
}

