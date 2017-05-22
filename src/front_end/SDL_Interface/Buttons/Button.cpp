//
// Created by darius on 21/05/17.
//

#include "Button.h"
/**
 * Constructor
 * @param x : Posicion en X
 * @param y : Posicion en Y
 * @param width : Ancho de la superficie clickeable
 * @param length : Largo de la superficie clickeable
 * @param window : Ventana sobre la que se realiza el click (generalmente: Main_Window)
 */
Button::Button(int x, int y, int width, int length, Window * window) {
  this->window = window;
  this->set_position(x,y);
  this->width = width;
  this->length = length;
}

/**
 * Destructor: se eliminan las texturas cargadas.
 */
Button::~Button() {
  if (button_up != NULL){
    delete this->button_up;
  }
  if (button_down != NULL){
    delete this->button_down;
  }
}

/**
 * set_position
 * @param x : coordenada x de la ubicacion del boton en la ventana
 * @param y : coordenada y de la ubicacion del boton en la ventana
 */
void Button::set_position(int x, int y) {
  this->position->x = x;
  this->position->y = y;
}

/**
 * load_texture_up: Opcional
 * @param path : ruta de archivo de la imagen de boton levantada
 */
void Button::load_texture_up(const std::string &path) {
  this->button_up = new Texture(path, window);
}

/**
 * load_texture_down: Opcional
 * @param path : ruta de archivo de la imagen de boton apretada
 */
void Button::load_texture_down(const std::string &path) {
  this->button_up = new Texture(path, window);
}


void Button::handle_event(Click *click) {
  if (click->get_click_data().state == SDL_PRESSED){
    this->on_button_pressed();
  } else {
    this->on_button_released();
  }
}
void Button::on_button_pressed() {
  if (this->button_down != NULL){
    this->button_down->renderize(this->window);
  }
}
void Button::on_button_released() {
  if (this->button_up != NULL){
    this->button_up->renderize(this->window);
    this->button_launch();
  }
}
