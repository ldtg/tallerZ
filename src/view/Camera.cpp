#include "Camera.h"

Camera::Camera(int w, int h) : w(w), h(h) {
  x = 0;
  y = 0;
  dirX = 0;
  dirY = 0;
  vel = 5;
  gap = 10;
}

void Camera::move(int x, int y) {
  if (x < gap) {
    dirX =- 2;
    dirY = 0;
    this->x -= 2;
  }
  else if (x > w-gap) {
    dirX = 2;
    dirY = 0;
    this->x += 2;
  }
  else if (y < gap) {
    dirX = 0;
    dirY = -2;
    this->y -= 2;
  }
  else if ( y > h-gap) {
    dirX = 0;
    dirY = 2;
    this->y += 2;
  }
}

/*
Position Camera::translateToViewPos(Position &pos) {
  return pos.sub(x, y);
}

Position Camera::translateToModelPos(Position &pos) {
  return pos.add(x, y);
}
*/
