#ifndef TALLERZ_NULLHANDLER_H
#define TALLERZ_NULLHANDLER_H

#include "Handler.h"

class NullHandler : public Handler {
 public:
  NullHandler();
  void handle(SDL_Event *e, EventHandler &eventHandler,
              Model &model, View &view);
};

#endif //TALLERZ_NULLHANDLER_H
