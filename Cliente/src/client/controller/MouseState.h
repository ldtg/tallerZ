#ifndef TALLERZ_MOUSESTATE_H
#define TALLERZ_MOUSESTATE_H

#include "Handler.h"

class MouseState : public Handler {
 private:
  int x;
  int y;
 public:
  MouseState();
  void handle(SDL_Event *e, EventHandler &eventHandler);
};

#endif //TALLERZ_MOUSESTATE_H
