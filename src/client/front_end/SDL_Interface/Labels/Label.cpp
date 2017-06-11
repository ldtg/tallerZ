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
Label::Label(Window &window, const std::string &text, const SDL_Rect &rect, TTF_Font *font) : window(window), font(font){
  //TODO: this->font = font Para que cada label no cargue el archivo, se tiene que cargar
  this->font = font;

  this->renderQuad = rect;
  this->text = text;
  this->surface = TTF_RenderText_Solid(this->font, text.c_str(), this->color);
  this->texture = new Texture(surface, &window);
  this->texture->renderize(&window, &this->renderQuad);
}
/**
 * Destructor
 */
Label::~Label() {
  delete this->texture;
}

/**
 * Displace_toXY
 * @param coordX
 * @param coordY
 */
void Label::displace_toXY(int coordX, int coordY) {
  //TODO BUG aca
  this->renderQuad.x += coordX;
  this->renderQuad.y += coordY;
  this->reload();
}

void Label::modify_text(const std::string &text) {
  Texture texture(&window);
  texture.renderize(&window, &this->renderQuad);
  this->text = text;
  *this->texture = Texture(TTF_RenderText_Solid(this->font, text.c_str(), this->color), &window);
  this->reload();
}

SDL_Rect Label::get_rectangle() {
  return this->renderQuad;
}

void Label::set_rectangle(const SDL_Rect& rect) {
  this->renderQuad = rect;
}
void Label::reload() {
  this->texture->renderize(&window, &renderQuad);
}
