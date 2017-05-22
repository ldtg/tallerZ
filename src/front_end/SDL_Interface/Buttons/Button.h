//
// Created by darius on 21/05/17.
//

#ifndef TALLERZ_BUTTON_H
#define TALLERZ_BUTTON_H

#include <SDL2/SDL_rect.h>
#include <view/Sprite.h>
#include <model/Events/Pointer/Click.h>
#include <view/Texture.h>

/*
 * TODO: barajar la posibilidad de armar una clase clickable de la que herede button y demas objetos clickeables. Por ahora lo dejo así.
 */

/**
 * Button
 * De button heredan los objetos clickeables que disparan un evento.
 */
class Button {
 private:
  Window * window;

  SDL_Point * position;
  SDL_Event * event;

  Texture * button_up = NULL;
  Texture * button_down = NULL;

  int width;
  int length;

 public:
  Button(int x, int y, int width, int length, Window * window);

  ~Button();

  void set_position(int x, int y);

  void load_texture_up(const std::string &path);

  void load_texture_down(const std::string &path);

  void handle_event(Click* click);

 protected:
  void on_button_pressed();

  void on_button_released();

  virtual void button_launch() = 0;//virtual puro
};

#endif //TALLERZ_BUTTON_H
