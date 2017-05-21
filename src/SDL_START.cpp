//
// Created by darius on 21/05/17.
//

#include "SDL_START.h"

SDL_START::SDL_START() {
  this->initialize_SDL();
  this->initialize_SDL_image();
}

SDL_START::~SDL_START() {
  IMG_Quit();
  SDL_Quit();
}

/**
 * initialize_SDL
 * Inicialización de SDL
 */
void SDL_START::initialize_SDL() {
  if (SDL_Init(SDL_INIT_VIDEO)!= 0){
    throw Sdl_Exception(
        "Error en el metodo initialize_SDL de SDL_START: no se pudo "
            "inicializar la ventana con SDL_Init: %s\n",SDL_GetError());
  }
}

/**
 * initialize_SDL_image
 * SDL_image permite trabajar con distintos formatos de imágenes
 * con la configuración adecuada.
 */
void SDL_START::initialize_SDL_image() {
  int initted = IMG_Init(IMG_INIT_PNG);
  if ((initted & IMG_INIT_PNG) != IMG_INIT_PNG){
    throw Sdl_Exception(
        "Error en el metodo initialize_SDL_image de SDL_START "
            "al inicializar SDL_Image: %s\n", IMG_GetError());
  }
}





