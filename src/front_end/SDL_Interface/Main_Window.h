//
// Created by darius on 21/05/17.
//

#ifndef TALLERZ_MAIN_WINDOW2_H
#define TALLERZ_MAIN_WINDOW2_H

#include <view/Image.h>
#include <view/Sprite.h>
#include <front_end/SDL_Interface/Buttons/Menu_Button.h>
#include "../../view/Window.h"
#include "front_end/SDL_Interface/Side_Board.h"
#include "front_end/SDL_Interface/Cursor.h"
#include "Front_end_exceptions/Front_end_exception.h"

class Main_Window {
 private:
  SDL_Event * event;
  Window * main_window;
  Cursor * cursor;
  Sprite * robot_face;
  Image * weapon_img;
  Side_Board * side_board;
  SDL_Surface * base_surface = NULL;
  Menu_Button *menu_button = NULL;
 public:
  Main_Window();

  ~Main_Window();

  Window * get_window() const;

  void run();

  SDL_Surface * get_base_surface() const;

  void Maximize();

  void trap_cursor();

 private:
  void load_buttons(){
    this->menu_button = new Menu_Button(main_window);
  }
};

#endif //TALLERZ_MAIN_WINDOW2_H
