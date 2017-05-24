#ifndef TALLERZ_MOUSE_H
#define TALLERZ_MOUSE_H

#include "Handler.h"
class Mouse : public Handler {
 private:
  int x;
  int y;
 public:
  Mouse();
  void handle(SDL_Event *e, EventHandler &eventHandler);
};

#endif //TALLERZ_MOUSE_H
