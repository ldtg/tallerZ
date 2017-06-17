#include <client/model/Events/view/CameraMove.h>
#include "MouseMotion.h"

MouseMotion::MouseMotion() : Handler() {}

void MouseMotion::handle(SDL_Event *e, EventHandler &eventHandler) {
  x = e->motion.x;
  y = e->motion.y;

  if (x < 10 || x > WINDOWWIDHT-10 || y < 10 || y > WINDOWHEIGHT-10) {
    eventHandler.add(new CameraMove(x, y));
  }
}
