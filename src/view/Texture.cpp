//
// Created by darius on 21/05/17.
//

#include <Exceptions/Sdl_Exceptions/Sdl_Exception.h>
#include "Texture.h"

/**
 * load_texture
 * Devuelve una textura a partir de una imagen.
 */
void Texture::load_texture(const std::string &path, SDL_Window *window) {
  SDL_Surface * temporal_surface;

  temporal_surface = load_image(path);
  this->texture = SDL_CreateTextureFromSurface(
      SDL_GetRenderer(window), temporal_surface);
  if (this->texture == NULL){
    throw Sdl_Exception(
        "Error en el metodo load_texture de la clase Texture: No se pudo cargar "
            "la textura: %s", SDL_GetError());
  }
}

/**
 * load_image
 * @param path: Path to image
 * @return SDL_Surface
 */
SDL_Surface *Texture::load_image(const std::string &path) {
  SDL_Surface * _image = IMG_Load(path.c_str());
  if (_image == NULL){
    throw Sdl_Exception(
        "Error en el metodo load_image de la clase Texture: No se pudo cargar "
            "la imagen %s: %s\n", path.c_str(), IMG_GetError());
  }
  return _image;
}

SDL_Texture *Texture::get_texture() const {
  return this->texture;
}

