//
// Created by darius on 21/05/17.
//

#include "Cursor.h"
Cursor::Cursor() {
  this->load_cursor(SDL_SYSTEM_CURSOR_HAND);
}
Cursor::~Cursor() {
  SDL_FreeCursor(this->cursor);
}
void Cursor::load_cursor(SDL_SystemCursor id) {
  this->cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
  if (this->cursor == NULL){
    throw Front_end_exception(
        "Error en el metodo load_cursor de la clase Cursor: %s\n",
        SDL_GetError());
  }
  SDL_SetCursor(this->cursor);
}
