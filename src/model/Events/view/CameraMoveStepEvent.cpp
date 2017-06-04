#include "CameraMoveStepEvent.h"

CameraMoveStepEvent::CameraMoveStepEvent(Camera &camera, int x, int y)
    : camera(camera), x(x), y(y) {}

void CameraMoveStepEvent::process() {
  camera.move(x,y);
}
