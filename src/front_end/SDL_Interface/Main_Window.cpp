//
// Created by darius on 21/05/17.
//

#include "Main_Window.h"

Main_Window::Main_Window() {
  this->main_window = new Window();

  this->map = new Map();
  this->eventHandler = new EventHandler();
  this->model = new Model();
  this->view = new View(*map, *eventHandler, *this->main_window);
  this->controller = new Controller(*eventHandler, *model, *view);

  this->cursor = new Cursor();
  this->side_board = new Side_Board(this->main_window);
  //this->robot_face = new Sprite();
  this->run();
}

Main_Window::~Main_Window() {
  delete this->map;
  delete this->eventHandler;
  delete this->model;
  delete this->view;

  //delete this->robot_face;
  delete this->menu_button;//TODO refactorizar como se guardan los botones y se liberan
  delete this->cursor;
  delete this->side_board;
  delete this->main_window;
}

Window *Main_Window::get_window() const {
  return this->main_window;
}

SDL_Surface *Main_Window::get_base_surface() const {
  return this->base_surface;
}

void Main_Window::run() {
  this->trap_cursor();
  this->load_buttons();
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

void Main_Window::Maximize() {
  SDL_MaximizeWindow(this->main_window->getWindow());
}

void Main_Window::trap_cursor() {
  SDL_SetWindowGrab(this->main_window->getWindow(), SDL_TRUE);
}
