#include "LeftClickEvent.h"

LeftClickEvent::LeftClickEvent(int x, int y) : x(x), y(y) {}

void LeftClickEvent::process() {
  model->leftClick(x,y);
}
