#ifndef TALLERZ_CONTROLLER_H
#define TALLERZ_CONTROLLER_H

#include <vector>
#include "Handler.h"
#include "Quit.h"
#include "HandlerFactory.h"
#include "../view/Vista.h"

class Controller {
 private:
  Vista &vista;
//  Quit _quit;
//  std::vector<Handler*> handlers;
 public:
  Controller(Vista &vista);
  void handle(SDL_Event *e);
};

#endif //TALLERZ_CONTROLLER_H
