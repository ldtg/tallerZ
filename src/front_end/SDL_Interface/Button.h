//
// Created by darius on 21/05/17.
//

#ifndef TALLERZ_BUTTON_H
#define TALLERZ_BUTTON_H

#include <SDL2/SDL_rect.h>
#include <view/Sprite.h>
#include <model/Events/Pointer/Click.h>
class Button {
 private:
  SDL_Point * position;
  SDL_Event * event;
  Sprite * sprite;

 public:
  Button(){
    this->position->x = 0;
    this->position->y = 0;
  }

  Button(int x, int y){
    this->set_position(x,y);
  }

  void set_position(int x, int y){
    this->position->x = x;
    this->position->y = y;
  }

  void handle_event(const Click* click){

  }

};

#endif //TALLERZ_BUTTON_H
