#ifndef TALLERZ_QUIT_H
#define TALLERZ_QUIT_H

#include "Handler.h"

class Quit : public Handler {
 public:
  Quit(Vista &vista);
  void handle(SDL_Event *e);
};

#endif //TALLERZ_QUIT_H
