#include "Window.h"
#include <SDL2/SDL_image.h>
#include <Exceptions/Sdl_Exceptions/Sdl_Exception.h>
#include <SDL2/SDL_mixer.h>

Window::Window() {
  width = WINDOWWIDHT;
  height = WINDOWHEIGHT;

  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
  IMG_Init(IMG_INIT_PNG);
//  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);

  window = SDL_CreateWindow("TALLERZ",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            width,
                            height,
                            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

//  sdl_window = SDL_CreateWindow("title", 10, 30, window_width, window_height,
//                                SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_FULLSCREEN);
//  SDL_MaximizeWindow(sdl_window);
//  SDL_GetWindowSize(sdl_window, &window_width, &window_height);

  if (window == NULL) {
    throw Sdl_Exception(
          "Error al crear ventana: no se pudo"
          " crear la ventana con SDL_CreateWindow: %s\n",SDL_GetError());
    }

//  window_render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  window_render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (window_render == NULL) {
    throw Sdl_Exception(
        "Error al crear render de la ventana: no se pudo "
            "crear render con SDL_CreateRenderer: %s\n",SDL_GetError());
  }
  SDL_SetRenderDrawColor(window_render, 0xFF, 0xFF, 0xFF, 0xFF);

  SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "2" );

//  SDL_MaximizeWindow(window);
//  cursor = new Cursor();

  // trap cursor
//  SDL_SetWindowGrab(window, SDL_TRUE);
}

Window::~Window() {
  SDL_DestroyRenderer(window_render);
  SDL_DestroyWindow(window);

  IMG_Quit();
  SDL_Quit();
//  Mix_Quit();
}

SDL_Renderer* Window::getRender() const {
    return window_render;
}

SDL_Window *Window::getWindow() const {
    return this->window;
}

int Window::getWidth() const {
  return WINDOWWIDHT;
}

int Window::getHeight() const {
  return WINDOWHEIGHT;
}

void Window::update() {
    SDL_UpdateWindowSurface(this->window);
}

