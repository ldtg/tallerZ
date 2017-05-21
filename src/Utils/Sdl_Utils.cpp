//
// Created by darius on 21/05/17.
//

#include "Sdl_Utils.h"

SDL_Surface *load_image(const std::string &path) {
  SDL_Surface * _image = IMG_Load(path.c_str());
  if (_image == NULL){
    throw Sdl_Exception(
        "Error en el metodo load_image de SDL_Utils: No se pudo cargar "
            "la imagen %s: %s\n", path.c_str(), IMG_GetError());
  }
  return _image;
}