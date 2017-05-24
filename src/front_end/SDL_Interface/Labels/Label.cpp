//
// Created by darius on 23/05/17.
//

#include "Label.h"
/**
 * Label
 * @param window: Ventana sobre la que se renderiza
 * @param text : Texto del label
 * @param rect : Posicion y area del label
 */
Label::Label(Window &window, const std::string &text, const SDL_Rect &rect) : window(window){
  this->load_font();
  this->sdl_rect = rect;
  this->text = text;
  this->surface = TTF_RenderText_Solid(this->font, text.c_str(), this->color1);
  this->texture = new Texture(surface, &window);
  this->texture->renderize(&window, &this->sdl_rect);
}
/**
 * Destructor
 */
Label::~Label() {
  delete this->texture;
}
/**
 * load_font: carga una font ("BEBAS.ttf") predeterminada a partir de un archivo.
 */
void Label::load_font() {
  try {
    this->font = TTF_OpenFont(font_path.c_str(), 10);
    if (font == NULL){
      throw -1;
    }
  } catch (int e) {
    throw Sdl_Exception(
        "Error en Label.cpp: load_font. \n\tNo se pudo cargar la fuente"
            " '%s: %s'\n", font_path.c_str(), TTF_GetError());
  }
}

void Label::displace_toXY(int coordX, int coordY) {
  this->sdl_rect.x = coordX;
  this->sdl_rect.y = coordY;
  this->texture->renderize(&window, &this->sdl_rect);
}
void Label::modify_text(const std::string &newText, Color color) {
  this->text = newText;
  *this->texture = Texture(TTF_RenderText_Solid(this->font, text.c_str(), color1), &window);
  this->texture->renderize(&window, &this->sdl_rect);
}
