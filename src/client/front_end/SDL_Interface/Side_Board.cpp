//
// Created by darius on 21/05/17.
//

#include "Side_Board.h"
#include <client/view/View.h>

Side_Board::Side_Board(Window * window, View& view) : window(window), view(view){
  this->side_board_texture = new Texture(path, window);
  this->side_board_texture->renderize(window);
  this->load_items();
}

Side_Board::~Side_Board() {
  if (this->menu_button != NULL) delete this->menu_button;
  if (this->side_board_texture != NULL) delete this->side_board_texture;
}

Texture *Side_Board::get_side_board(){
  return this->side_board_texture;
}
void Side_Board::load_side_board(Window * window) {
  this->side_board_texture->renderize(window, &renderQuad);
}
void Side_Board::load_items() {
  this->menu_button = new Quit_Button(window,view);
}
bool Side_Board::is_in_menu_button(int x, int y) {
  return menu_button->inRectangle(x,y);
}
void Side_Board::add_to_panel(Panel &panel) {
  panel.add(this);
  panel.add(menu_button);
}
