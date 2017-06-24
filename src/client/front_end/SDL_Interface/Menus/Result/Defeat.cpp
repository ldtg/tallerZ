#include "Defeat.h"

Defeat::Defeat(Window &window, View &view) : view(view), window(window){
  this->renderQuad = {288, 240, 224, 120};
  this->background = new Texture(background_path.c_str(), &window);
  this->background->renderize(&window, &renderQuad);
  this->load_items();
}

void Defeat::handle_click(int x, int y) {
  if (ok->inRectangle(x, y)) {
    ok->handle_event();
  }
}

void Defeat::draw(SDL_Renderer *render, Camera &camera) {
  Menu::draw(render, camera);
  ok->draw(render, camera);
}

Defeat::~Defeat() {
  if (this->background != NULL) delete (this->background);
  if (this->ok != NULL) delete (this->ok);
}

void Defeat::load_items() {
  set_absolute_position(_ok_b_rect, this->ok_b_rect);
  this->ok = new Ok_Button(&window, view, ok_b_rect);
}

