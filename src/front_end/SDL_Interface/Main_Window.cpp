//
// Created by darius on 21/05/17.
//

#include "Main_Window.h"

Main_Window::Main_Window() {
  this->main_window = new Window();
  this->cursor = new Cursor();
  this->side_board = new Side_Board(this->main_window);
  this->robot_face = new Sprite();
  this->event = new SDL_Event();
  this->run();
}

Main_Window::~Main_Window() {
  delete this->event;
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

  bool quit = false;
  while (!quit){
    while (SDL_PollEvent(this->event)){
      if (event->type == SDL_QUIT){
        quit = true;
      }
    }
  }
}

void Main_Window::Maximize() {
  SDL_MaximizeWindow(this->main_window->getWindow());
}

void Main_Window::trap_cursor() {
  SDL_SetWindowGrab(this->main_window->getWindow(), SDL_TRUE);
}
