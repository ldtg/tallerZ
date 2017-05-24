//
// Created by darius on 22/05/17.
//

#ifndef TALLERZ_RUN_H
#define TALLERZ_RUN_H

#include <controller/Controller.h>
#include <front_end/SDL_Interface/Main_Window.h>

/**
 * @class Z_RUNNER
 * ejecutora del juego que conecta los distintos componentes
 * realizados hasta ahora
 */
class Z_RUNNER {
 private:
  Main_Window * main_window;
  Controller * controller;
  View * view;
  EventHandler * eventHandler;
  Model * model;
  Map * map;
  GameController * gameController;

 public:
  Z_RUNNER();

  void run();

  ~Z_RUNNER();
};

#endif //TALLERZ_RUN_H
