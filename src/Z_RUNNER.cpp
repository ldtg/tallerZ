//
// Created by darius on 22/05/17.
//

#include "Z_RUNNER.h"
Z_RUNNER::Z_RUNNER() {
  main_window = new Main_Window();
  eventHandler = new EventHandler();
  this->map = new Map();
//  this->gameController = new GameController(map, );
//  this->model = new Model(map, );
  this->view = new View(*map, *eventHandler, *main_window->get_window());
  this->controller = new Controller(*eventHandler);
}

void Z_RUNNER::run() {
  bool quit = false;
  SDL_Event event;
  while (!quit){
    while (SDL_PollEvent(&event)){
      if (event.type == SDL_QUIT){
        quit = true;
      }
      controller->handle(&event);
    }
  }
}

Z_RUNNER::~Z_RUNNER() {
  delete controller;
  delete view;
  delete map;
  delete model;
  delete eventHandler;
  delete main_window;
}
