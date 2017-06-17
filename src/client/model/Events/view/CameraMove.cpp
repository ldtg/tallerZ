#include "CameraMove.h"

CameraMove::CameraMove(int x, int y) : x(x), y(y) {}

void CameraMove::process() {
  Camera &camera = view->getCamera();
//  int mapWidth = model->getMap().getWidht()*TILEWIDHT;
//  int mapHeight = model->getMap().getHeight()*TILEHEIGHT ;

  if (camera.inLimits(x, y)) {
      camera.move(x, y);
  }
}
