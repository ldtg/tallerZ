#include "MouseButtonLeft.h"

#include <iostream>
#include <model/Events/Pointer/LeftClickEvent.h>

MouseButtonLeft::MouseButtonLeft() : Handler() {
//  SDL_GetMouseState(&x, &y);
}

void MouseButtonLeft::handle(SDL_Event *e, EventHandler &eventHandler) {
  x = e->button.x;
  y = e->button.y;

  eventHandler.add(new LeftClickEvent(x,y));

//    std::cout << "(" << x << "," << y << ")" << std::endl;
}
