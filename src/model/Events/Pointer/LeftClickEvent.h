//
// Created by darius on 21/05/17.
//

#ifndef TALLERZ_CLICK_H
#define TALLERZ_CLICK_H

#include <SDL2/SDL_events.h>
#include <model/Events/Event.h>

class LeftClickEvent : public Event {
 private:
  int x;
  int y;
 public:
  LeftClickEvent(int x, int y);
  void process();
 };

#endif //TALLERZ_CLICK_H
