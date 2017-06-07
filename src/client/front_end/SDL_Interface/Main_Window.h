//
// Created by darius on 21/05/17.
//

#ifndef TALLERZ_MAIN_WINDOW2_H
#define TALLERZ_MAIN_WINDOW2_H

#include <client/view/Image.h>
#include <client/view/Sprite.h>
#include <client/front_end/SDL_Interface/Buttons/Menu_Button.h>
#include "client/view/Window.h"
#include "client/controller/Controller.h"
#include "Side_Board.h"
#include "Cursor.h"
#include "Side_Board.h"
#include "Cursor.h"
#include "Front_end_exceptions/Generator_Exception.h"

class Main_Window {
 private:
  Window * main_window;
  Cursor * cursor;
  //Sprite * robot_face;
  //Image * weapon_img;
  Side_Board * side_board;
  SDL_Surface * base_surface = NULL;
  Menu_Button *menu_button = NULL;
 public:
  Main_Window();

  ~Main_Window();

  Window * get_window() const;

  SDL_Surface * get_base_surface() const;

  void Maximize();

  void trap_cursor();

 private:
  void load_buttons(){
    this->menu_button = new Menu_Button(main_window);
  }
};

#endif //TALLERZ_MAIN_WINDOW2_H
