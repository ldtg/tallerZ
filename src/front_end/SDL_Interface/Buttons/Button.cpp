//
// Created by darius on 21/05/17.
//

#include "Button.h"
/**
 * Constructor
 * @param window : ventana sobre la que se realiza el click (generalmente: Main_Window)
 */
Button::Button(Window *window) {
  this->window = window;
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
 * set_rectangle
 * @param x : coordenada x de la ubicacion del boton en la ventana
 * @param y : coordenada y de la ubicacion del boton en la ventana
 * @param width : Ancho de la superficie clickeable
 * @param length : Largo de la superficie clickeable
 */
void Button::set_rectangle(int x, int y, int width, int length) {
  this->renderQuad = {x , y, width, length};
}

/**
 * load_texture_up: Opcional
 * @param path : ruta de archivo de la imagen de boton levantada
 */
void Button::load_texture_up(const std::string &path) {
  this->button_up = new Texture(path, window);
  this->button_up->renderize(window, &renderQuad);
}
/**
 * load_texture_down: Opcional
 * @param path : ruta de archivo de la imagen de boton apretada
 */
void Button::load_texture_down(const std::string &path) {
  this->button_up = new Texture(path, window);
}
/**
 * handle_event
 * @param click: Click ameo.
 */
void Button::handle_event(Click *click) {
  if (click->get_click_data().state == SDL_PRESSED){
    this->on_button_pressed();
  } else {
    this->on_button_released();
  }
}
/**
 * on_button_pressed
 * Lo unico que se realiza al apretar un boton es renderizar la textura
 * de boton apretado.
 */
void Button::on_button_pressed() {
  if (this->button_down != NULL){
    this->button_down->renderize(this->window);
  }
}
/**
 * on_button_released
 * Se dispara el evento asociado al boton
 * Se renderiza la textura de boton sin levantar.
 */
void Button::on_button_released() {
  if (this->button_up != NULL){
    this->button_up->renderize(this->window);
    this->button_launch();
  }
}
