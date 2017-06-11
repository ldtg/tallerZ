#ifndef TALLERZ_CONTROLLER_H
#define TALLERZ_CONTROLLER_H

#include <vector>
#include "Handler.h"
#include "Quit.h"
#include "HandlerFactory.h"
#include "client/view/View.h"

class Controller {
 private:
  EventHandler &eventHandler;
 public:
  Controller(EventHandler &eventHandler);
  void handle(SDL_Event *e);
  void checkMouseState(SDL_Event *e);
};

#endif //TALLERZ_CONTROLLER_H
