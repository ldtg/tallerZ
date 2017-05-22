#ifndef TALLERZ_QUIT_H
#define TALLERZ_QUIT_H

#include "Handler.h"

class Quit : public Handler {
 public:
  Quit();
  void handle(SDL_Event *e, EventHandler &eventHandler,
              Model &model, View &view);
};

#endif //TALLERZ_QUIT_H
