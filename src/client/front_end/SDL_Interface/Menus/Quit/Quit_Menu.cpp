#include <client/front_end/SDL_Interface/Menus/Quit/Quit_Menu.h>

Quit_Menu::Quit_Menu(Window &window, View &view) : view(view), window(window) {
  this->renderQuad = {344, 270, 112, 60};
  this->background = new Texture(background_path.c_str(), &window);
  this->background->renderize(&window, &renderQuad);
  this->load_items();
}

void Quit_Menu::load_items() {
  set_absolute_position(_salir_b_rect, this->salir_b_rect);
  this->salir = new Salir_Button(&window, view, salir_b_rect);
}

void Quit_Menu::handle_click(int x, int y) {
  if (salir->inRectangle(x, y)) {
    salir->handle_event();
  }
}

void Quit_Menu::draw(SDL_Renderer *render, Camera &camera) {
    Menu::draw(render, camera);
    salir->draw(render, camera);
}

Quit_Menu::~Quit_Menu() {
  if (this->background != NULL) delete (this->background);
  if (this->salir != NULL) delete (this->salir);
}
