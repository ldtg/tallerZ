//
// Created by darius on 21/05/17.
//

#include "Side_Board.h"

Side_Board::Side_Board(Window * window) {
  this->side_board_texture = new Texture(path, window);
  this->load_side_board(window);
  this->menu_button = new Menu_Button(window);
}

Side_Board::~Side_Board() {
  delete this->menu_button;
  delete this->side_board_texture;
}

Texture *Side_Board::get_side_board(){
  return this->side_board_texture;
}
void Side_Board::load_side_board(Window * window) {
  this->side_board_texture->renderize(window);
}
