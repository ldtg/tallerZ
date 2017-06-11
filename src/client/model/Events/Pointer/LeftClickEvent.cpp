#include "LeftClickEvent.h"

//SDL_MouseButtonEvent Click::get_click_data() {
//  return this->event;
//}

LeftClickEvent::LeftClickEvent(int x, int y) : x(x), y(y) {}

void LeftClickEvent::process() {
  model->leftClick(x,y);
}
