#include "MainWindow.h"
#include <SDL2/SDL_image.h>
#include <Exceptions/Sdl_Exceptions/Sdl_Exception.h>

MainWindow::MainWindow() {
  width = WINDOWWIDHT;
  height = WINDOWHEIGHT;

  SDL_Init(SDL_INIT_VIDEO);
  IMG_Init(IMG_INIT_PNG);

  window = SDL_CreateWindow("TALLERZ",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            width,
                            height,
                            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

  if (window == NULL) {
    throw Sdl_Exception(
          "Error al crear ventana: no se pudo"
          " crear la ventana con SDL_CreateWindow: %s\n",SDL_GetError());
    }

  window_render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (window_render == NULL) {
    throw Sdl_Exception(
        "Error al crear render de la ventana: no se pudo "
            "crear render con SDL_CreateRenderer: %s\n",SDL_GetError());
  }
  SDL_SetRenderDrawColor(window_render, 0xFF, 0xFF, 0xFF, 0xFF);

  SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "2" );
}

MainWindow::~MainWindow() {
  SDL_DestroyRenderer(window_render);
  SDL_DestroyWindow(window);

  IMG_Quit();
  SDL_Quit();
}

SDL_Renderer* MainWindow::getRender() const {
    return window_render;
}

SDL_Window *MainWindow::getWindow() const {
    return this->window;
}

int MainWindow::getWidth() const {
  return WINDOWWIDHT;
}

int MainWindow::getHeight() const {
  return WINDOWHEIGHT;
}

void MainWindow::update() {
    SDL_UpdateWindowSurface(this->window);
}

