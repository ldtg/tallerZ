#include "RightClickEvent.h"

RightClickEvent::RightClickEvent(int x, int y) : x(x), y(y) {}

void RightClickEvent::process() {
  model->rightClick(x,y);
}
