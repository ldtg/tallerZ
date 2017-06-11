#ifndef TALLERZ_MOUSEBUTTONRIGHT_H
#define TALLERZ_MOUSEBUTTONRIGHT_H

#include "Handler.h"

class MouseButtonRight  : public Handler {
 private:
  int x;
  int y;
 public:
  MouseButtonRight();
  void handle(SDL_Event *e, EventHandler &eventHandler);
};

#endif //TALLERZ_MOUSEBUTTONRIGHT_H
