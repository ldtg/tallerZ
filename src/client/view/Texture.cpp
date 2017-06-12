#include <Exceptions/Sdl_Exceptions/Sdl_Exception.h>
#include "Texture.h"

/**
 * Constructor
 * @param window : ventana sobre la que se renderiza
 * Este constructor genera una textura default negra.
 */
Texture::Texture(const Window *window) {
  //TODO cuando definamos el tamaño de la ventana, modificar los valores 500, 500 que están harcodeados y poner el tamaño de la ventana definido.
  SDL_Surface * surface = SDL_CreateRGBSurface(0, 500, 500, 32, 0, 0, 0, 0);
  SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 0, 0));
  this->generate_texture(surface, window->getWindow());
  SDL_FreeSurface(surface);
}
/**
 * Constructor
 * @param path : ruta a la imagen sobre la que se construye la textura
 * @param window : ventana sobre la que se renderiza
 */
Texture::Texture(const std::string &path, const Window *window) {
  this->load_texture(path, window->getWindow());
}
/**
 * Constructor
 * @param surface : Surface a partir de la cual se genera la textura
 * @param window : Ventana sobre la que se renderizará
 */
Texture::Texture(SDL_Surface *surface, const Window *window) {
  this->generate_texture(surface, window->getWindow());
}
/**
 * generate_texture
 * @param surface : Surface a partir de la cual se genera la textura
 * @param window : Ventana sobre la que se renderizará
 */
void Texture::generate_texture(SDL_Surface *surface, SDL_Window * window) {
  this->texture = SDL_CreateTextureFromSurface(SDL_GetRenderer(window),surface);
  if (this->texture == NULL){
    throw Sdl_Exception(
        "Error en el metodo generate_texture de la clase Texture: No se pudo cargar "
            "la textura: %s", SDL_GetError());
  }
}
/**
 * load_texture
 * Devuelve una textura a partir de una imagen.
 */
void Texture::load_texture(const std::string &path, SDL_Window *window) {
  SDL_Surface * temporal_surface;
  temporal_surface = load_image(path);
  this->generate_texture(temporal_surface,window);
  SDL_FreeSurface(temporal_surface);
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
  SDL_RenderCopy(window->getRender(), this->texture, NULL, renderQuad);
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



