//
// Created by darius on 22/05/17.
//

#ifndef TALLERZ_CLICKABLE_H
#define TALLERZ_CLICKABLE_H

#include <client/view/Window.h>
#include <model/Events/Pointer/Click.h>
class Clickable {
 protected:
  Window * window;
  SDL_Rect sdl_rect;

 public:
  Clickable(){}

  Clickable(Window * window);

  void set_rectangle(int x, int y, int width, int length);

  bool inRectangle(int x, int y);

  virtual void handle_event(Click* click) = 0;


};

#endif //TALLERZ_CLICKABLE_H
