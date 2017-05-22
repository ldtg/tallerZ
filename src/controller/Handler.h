#ifndef TALLERZ_HANDLER_H
#define TALLERZ_HANDLER_H

#include <SDL_events.h>
#include "view/View.h"

class Handler {
 public:
  virtual void handle(SDL_Event *e, EventHandler &eventHandler,
                      Model &model, View &view) = 0;
};

#endif //TALLERZ_HANDLER_H
