//
// Created by darius on 21/05/17.
//

#include "Side_Board.h"
Side_Board::Side_Board() {
  std::string path = "../src/front_end/Images/Interface/interface.png";
  this->side_board = load_image(path.c_str());
}

SDL_Surface *Side_Board::get_side_board(){
  return this->side_board;
}

void Side_Board::load_side_board(SDL_Surface * surface) {
  SDL_BlitSurface(this->side_board, NULL,
                  surface , NULL);
}
