#include "CameraMove.h"

CameraMove::CameraMove(int x, int y) : x(x), y(y) {}

void CameraMove::process() {
  view->moveCamera(x, y);
}
