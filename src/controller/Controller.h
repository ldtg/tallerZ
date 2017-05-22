#ifndef TALLERZ_CONTROLLER_H
#define TALLERZ_CONTROLLER_H

#include <vector>
#include "Handler.h"
#include "Quit.h"
#include "HandlerFactory.h"
#include "../view/View.h"

class Controller {
 private:
  EventHandler &eventHandler;
  View &view;
  Model &model;
//  Quit _quit;
//  std::vector<Handler*> handlers;
 public:
  Controller(EventHandler &eventHandler, Model &model, View &view);
  void handle(SDL_Event *e);
};

#endif //TALLERZ_CONTROLLER_H
