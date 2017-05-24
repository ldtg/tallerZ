//
// Created by darius on 22/05/17.
//

#include "Clickable.h"
/**
 * Constructor
 * @param window : ventana sobre la que se realiza el click
 */
Clickable::Clickable(Window *window) {
  this->window = window;
}
/**
 * set_rectangle
 * @param x : coordenada x de la ubicacion del boton en la ventana
 * @param y : coordenada y de la ubicacion del boton en la ventana
 * @param width : Ancho de la superficie clickeable
 * @param length : Largo de la superficie clickeable
 */
void Clickable::set_rectangle(int x, int y, int width, int length) {
  this->sdl_rect = {x , y, width, length};
}
/**
 * inRectangle
 * @param x : coordenada x
 * @param y : coordenada y
 * @return : Si las coordenadas indicadas se ubican sobre el botón.
 */
bool Clickable::inRectangle(int x, int y) {
  return ( x > sdl_rect.x
      && x < (sdl_rect.x + sdl_rect.w)
      && y > sdl_rect.y
      && y < (sdl_rect.y + sdl_rect.h));
}
