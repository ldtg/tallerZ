//
// Created by darius on 23/05/17.
//

#include <model/Position.h>
#include "Menu.h"

/**
 * set_absolute_position
 * @param rect : rectangulo relativo a la esquina superior izquierda del menu
 * Modifica el parametro ingresado SDL_Rect rect de tal modo que la posicion
 * X e Y es la posición relativa a la ventana.
 * @param rect_abs: rectangulo relativo a la esquina superior izquierda de la
 * pantalla.
 */
void Menu::set_absolute_position(SDL_Rect &rect, SDL_Rect& rect_abs) {
  Position _pos = this->get_relative_pos(rect);
  rect_abs.x = _pos.getX();
  rect_abs.y = _pos.getY();
  rect_abs.w = rect.w;
  rect_abs.h = rect.h;
}
/**
 * get_relative_pos
 * @param item_rect : rectangulo de un item del menu
 * @return : devuelve la posicion de ese item en relación a la ventana.
 */
Position Menu::get_relative_pos(const SDL_Rect &item_rect) {
  int x,y;
  x = this->renderQuad.x + item_rect.x;
  y = this->renderQuad.y + item_rect.y;
  return Position(x,y);
}
Menu::Menu() {
  TTF_Init();
  this->load_font();
}
Menu::~Menu() {
  TTF_CloseFont(this->font);
}
void Menu::load_font() {
  try {
    this->font = TTF_OpenFont(font_path.c_str(), 60);
    if (font == NULL){
      throw -1;
    }
  } catch (int e) {
    throw Sdl_Exception(
        "Error en Menu.cpp: load_font. \n\tNo se pudo cargar la fuente"
            " '%s: %s'\n", font_path.c_str(), TTF_GetError());
  }
}
