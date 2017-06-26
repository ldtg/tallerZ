#include <client/model/Events/Pointer/RightClickEvent.h>
#include "MouseButtonRight.h"

MouseButtonRight::MouseButtonRight() : Handler() {}

void MouseButtonRight::handle(SDL_Event *e, EventHandler &eventHandler) {
  x = e->button.x;
  y = e->button.y;

  eventHandler.add(new RightClickEvent(x,y));
}
