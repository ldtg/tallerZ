#ifndef TALLERZ_HANDLER_H
#define TALLERZ_HANDLER_H

#include <SDL_events.h>
#include "../view/Vista.h"
class Handler {
 protected:
  Vista &vista;
  //TODO: agregar modelo.
 public:
  Handler(Vista &vista);
  virtual void handle(SDL_Event *e) = 0;
};

#endif //TALLERZ_HANDLER_H
