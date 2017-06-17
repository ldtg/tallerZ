#include <client/model/Events/view/CameraMove.h>
#include "MouseState.h"

MouseState::MouseState() : Handler() {}

void MouseState::handle(SDL_Event *e, EventHandler &eventHandler) {
  SDL_GetMouseState(&x, &y);

  if (x < 10 || x > WINDOWWIDHT-10 || y < 10 || y > WINDOWHEIGHT-10) {
    eventHandler.add(new CameraMove(x, y));
  }
}
