#ifndef TALLERZ_MOUSE_H
#define TALLERZ_MOUSE_H

#include "Handler.h"
class Mouse : public Handler {
 private:
  int x;
  int y;
 public:
  Mouse(Vista &vista);
  void handle(SDL_Event *e);
};

#endif //TALLERZ_MOUSE_H
