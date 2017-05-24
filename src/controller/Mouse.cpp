#include "Mouse.h"

#include <iostream>
#include <model/Events/Pointer/ClickEvent.h>

Mouse::Mouse() : Handler() {
//  SDL_GetMouseState(&x, &y);
}

void Mouse::handle(SDL_Event *e, EventHandler &eventHandler) {
  x = e->button.x;
  y = e->button.y;

  eventHandler.add(new ClickEvent(x,y));

//    std::cout << "(" << x << "," << y << ")" << std::endl;
}
