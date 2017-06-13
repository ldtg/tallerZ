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
    dirX =- vel;
    dirY = 0;
    this->x -= vel;
  }
  else if (x > w-gap) {
    dirX = vel;
    dirY = 0;
    this->x += vel;
  }
  else if (y < gap) {
    dirX = 0;
    dirY = -vel;
    this->y -= vel;
  }
  else if ( y > h-gap) {
    dirX = 0;
    dirY = vel;
    this->y += vel;
  }
}

bool Camera::inLimits(int x, int y, int mapWidth, int mapHeight) {
  int x_aux = 0;
  int y_aux = 0;

  if (x < gap) {
    x_aux = this->x - vel;
  }
  else if (x > w-gap) {
    x_aux = this->x + vel;
  }
  else if (y < gap) {
    y_aux = this->y - vel;
  }
  else if (y > h-gap) {
    y_aux = this->y + vel;
  }

  bool limits = x_aux >= 0 && y_aux >= 0 &&
      x_aux+w < mapWidth && y_aux+h < mapHeight+30;

  return limits;
}
