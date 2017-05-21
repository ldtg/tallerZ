//
// Created by darius on 21/05/17.
//

#ifndef TALLERZ_SDL_UTILS_H
#define TALLERZ_SDL_UTILS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "Sdl_Exceptions/Sdl_Exception.h"

SDL_Surface * load_image(const std::string& path);

SDL_Texture * load_texture(const std::string& path, SDL_Window * window);

#endif //TALLERZ_SDL_UTILS_H
