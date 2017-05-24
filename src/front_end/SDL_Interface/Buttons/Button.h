//
// Created by darius on 21/05/17.
//

#ifndef TALLERZ_BUTTON_H
#define TALLERZ_BUTTON_H

#include <SDL2/SDL_rect.h>
#include <view/Sprite.h>
#include <model/Events/Pointer/ClickEvent.h>
#include <view/Texture.h>
#include "Front_end_exceptions/Front_end_exception.h"

/*
 * TODO: barajar la posibilidad de armar una clase clickable de la que herede button y demas objetos clickeables. Por ahora lo dejo así.
 */

/**
 * @class Button
 * De button heredan los botones que disparan un evento.
 * Las clases hijas deben implementar button_launch (virtual puro)
 * que es el metodo asociado al evento de clickear sobre el boton.
 */
class Button {
 protected:
  Window * window;
  SDL_Point * position = NULL;
  SDL_Event * event = NULL;
  Texture * button_up = NULL;
  Texture * button_down = NULL;
  SDL_Rect sdl_rect;
 public:
  Button(){}

  Button(Window * window);

  ~Button();

  void set_rectangle(int x, int y, int width, int length);

  bool inRectangle(int x, int y);

  void load_texture_up(const std::string &path);

  void load_texture_down(const std::string &path);

  void handle_event(ClickEvent* click);

 protected:
  void on_button_pressed();

  void on_button_released();

  virtual void button_launch() = 0;//virtual puro
};

#endif //TALLERZ_BUTTON_H
