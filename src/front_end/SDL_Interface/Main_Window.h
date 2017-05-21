//
// Created by darius on 21/05/17.
//

#ifndef TALLERZ_MAIN_WINDOW2_H
#define TALLERZ_MAIN_WINDOW2_H

#include "../../view/Window.h"
#include "front_end/SDL_Interface/Side_Board.h"
#include "Front_end_exceptions/Front_end_exception.h"

class Main_Window {
 private:
  Window * main_window;
  Side_Board * side_board;
  SDL_Surface * base_surface = NULL;

 public:
  Main_Window();

  ~Main_Window();

  Window * get_window() const;
  
  SDL_Surface * get_base_surface() const;

};

#endif //TALLERZ_MAIN_WINDOW2_H
