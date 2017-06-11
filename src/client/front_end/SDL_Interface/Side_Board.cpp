//
// Created by darius on 21/05/17.
//

#include "Side_Board.h"

Side_Board::Side_Board(Window * window) {
  std::string path = "../src/front_end/Images/Interface/interface.png";
  this->side_board_texture = new Texture(path, window);
  //this->side_board = load_texture(path.c_str(), window->getWindow());
  this->load_side_board(window);
}

Side_Board::~Side_Board() {
  delete this->side_board_texture;
}

Texture *Side_Board::get_side_board(){
  return this->side_board_texture;
}
void Side_Board::load_side_board(Window * window) {
  this->side_board_texture->renderize(window);
}
