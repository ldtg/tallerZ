#ifndef TALLERZ_NULLHANDLER_H
#define TALLERZ_NULLHANDLER_H

#include "Handler.h"

class NullHandler : public Handler {
 public:
  NullHandler(Vista &vista);
  void handle(SDL_Event *e);
};

#endif //TALLERZ_NULLHANDLER_H
