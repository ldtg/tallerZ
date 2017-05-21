//
// Created by darius on 21/05/17.
//

#include "Main_Window.h"

Main_Window::Main_Window() {
  this->main_window = new Window();
  this->side_board = new Side_Board();
  this->side_board->load_side_board(this->base_surface);
}
Main_Window::~Main_Window() {
  delete this->side_board;
  delete this->main_window;
}

Window *Main_Window::get_window() const {
  return this->main_window;
}

void Main_Window::load_base_surface() {
  this->base_surface = SDL_GetWindowSurface(this->main_window->getWindow());
  SDL_FillRect( base_surface, NULL, SDL_MapRGB(
      base_surface->format, 0xFF, 0xFF, 0xFF ) );
  this->main_window->update();
}
SDL_Surface *Main_Window::get_base_surface() const {
  return this->base_surface;
}
