#ifndef TALLERZ_MOUSEMOTION_H
#define TALLERZ_MOUSEMOTION_H

#include "Handler.h"

class MouseMotion : public Handler {
 private:
  int x;
  int y;
 public:
  MouseMotion();
  void handle(SDL_Event *e, EventHandler &eventHandler);
};

#endif //TALLERZ_MOUSEMOTION_H
