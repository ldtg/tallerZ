#include "ClickEvent.h"

//SDL_MouseButtonEvent Click::get_click_data() {
//  return this->event;
//}

ClickEvent::ClickEvent(int x, int y) : x(x), y(y) {}

void ClickEvent::process() {
  model->click(x,y);
}
