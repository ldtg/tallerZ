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

/*
 * load_texture
 * Devuelve una textura a partir de una imagen.
 */
SDL_Texture* load_texture(const std::string& path, SDL_Window * window) {
  SDL_Texture * texture;
  SDL_Surface * temporal_surface;

  temporal_surface = load_image(path);
  texture = SDL_CreateTextureFromSurface(
      SDL_GetRenderer(window), temporal_surface);
  if (texture == NULL){
    throw Sdl_Exception(
        "Error en el metodo load_texture de Sdl_Utils: No se pudo cargar "
            "la textura: %s", SDL_GetError());
  }
  return texture;
}
