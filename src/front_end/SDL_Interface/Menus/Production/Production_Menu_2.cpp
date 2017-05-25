//
// Created by darius on 24/05/17.
//

#include "Production_Menu_2.h"
/**
 * Constructor
 * @param window : Ventana sobre la que se va a renderizar el menu
 * @param x : coordenada X
 * @param y : coordenada Y
 */
Production_Menu_2::Production_Menu_2(Window &window, int x, int y) : window(window) {
  this->renderQuad = { x, y, width, length};
  this->background = new Texture(background_path.c_str(), &window);
  this->background->renderize(&window, &renderQuad);
  load_items();
}
/**
 * displace_toXY : mueve el menu a las coordenadas x,y
 * @param x : coordenada x
 * @param y : coordenada y
 */
void Production_Menu_2::displace_toXY(int x, int y) {
  this->renderQuad.x = x;
  this->renderQuad.y = y;
  this->background->renderize(&window, &this->renderQuad);

  set_absolute_position(_unit_rect, unit_rect);
  this->unit->set_rectangle(unit_rect);
  this->unit->reload();

  set_absolute_position(_up_rect, up_rect);
  this->up->set_rectangle(up_rect);
  this->up->reload();

  set_absolute_position(_down_rect, down_rect);
  this->down->set_rectangle(down_rect);
  this->down->reload();

  set_absolute_position(_add_rect, add_rect);
  this->add->set_rectangle(add_rect);
  this->add->reload();
}

