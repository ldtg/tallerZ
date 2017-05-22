//
// Created by darius on 21/05/17.
//

#include <Exceptions/Sdl_Exceptions/Sdl_Exception.h>
#include "Texture.h"

Texture::Texture(const std::string &path, const Window *window) {
  this->load_texture(path, window->getWindow());
}

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

/**
 * getTexture
 * @return : SDL_Texture*
 */
SDL_Texture *Texture::get_texture() const {
  return this->texture;
}

/**
 * renderize: renderiza la textura de modo que se carga en la window
 * @param window : ventana sobre la que se renderiza
 * @param renderQuad : cuadrado sobre el que se renderiza
 */
void Texture::renderize(const Window * window, const SDL_Rect* renderQuad) {
  SDL_RenderClear(window->getRender());
  SDL_RenderCopy(window->getRender(), this->texture, NULL, NULL);
  SDL_RenderPresent( window->getRender());
}

/**
 * renderize: renderiza la textura de modo que se carga en la window
 * pero sobre toda la ventana
 * @param window
 */
void Texture::renderize(const Window *window) {
  this->renderize(window, NULL);
}

