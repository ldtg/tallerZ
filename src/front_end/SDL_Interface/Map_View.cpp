//
// Created by darius on 22/05/17.
//

#include "Map_View.h"

/**
 * inMapRect
 * @param x : coordenada X
 * @param y : coordenada Y
 * @return : Si las coordenadas estan adentro de la vista del juego
 */
bool Map_View::inMapRect(int x, int y) {
  return (x < map_rect.w && y < map_rect.h);
}

SDL_Rect Map_View::get_map_rect() const {
  return this->map_rect;
}
