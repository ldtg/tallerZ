//
// Created by darius on 21/05/17.
//

#include "Side_Board.h"
Side_Board::Side_Board(Window * window) {
  std::string path = "../src/front_end/Images/Interface/interface.png";
  this->side_board = load_texture(path.c_str(), window->getWindow());
  this->load_side_board(window);
}

SDL_Texture *Side_Board::get_side_board(){
  return this->side_board;
}

void Side_Board::load_side_board(Window * window) {
  SDL_RenderClear(window->getRender());
  SDL_RenderCopy(window->getRender(), this->side_board, NULL, NULL);
  SDL_RenderPresent( window->getRender());
}
