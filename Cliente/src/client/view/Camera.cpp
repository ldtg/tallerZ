#include "Camera.h"

Camera::Camera(int w,
               int h,
               int mapWidth,
               int mapHeight,
               const Position &initial)
    : w(w), h(h), mapHeight(mapHeight), mapWidth(mapWidth) {
  int aux_x = (int) initial.getX() - w / 2;
  if (aux_x < 0) {
    x = 0;
  } else {
    if (aux_x + w > mapWidth)
      x = aux_x - ((aux_x + w) - (mapWidth));
    else
      x = aux_x;
  }
  int aux_y = (int) initial.getY() - h / 2;
  if (aux_y < 0) {
    y = 0;
  } else {
    if (aux_y + w > mapHeight)
      y = aux_y - ((aux_y + w) - (mapHeight));
    else
      y = aux_y;
  }

  dirX = 0;
  dirY = 0;
  vel = 5;
  gap = 10;

}

void Camera::move(int x, int y) {
  if (x < gap) {
    dirX = -vel;
    dirY = 0;
    this->x -= vel;
  } else if (x > w - gap) {
    dirX = vel;
    dirY = 0;
    this->x += vel;
  } else if (y < gap) {
    dirX = 0;
    dirY = -vel;
    this->y -= vel;
  } else if (y > h - gap) {
    dirX = 0;
    dirY = vel;
    this->y += vel;
  }
}

bool Camera::inLimits(int x, int y) {
  int x_aux = 0;
  int y_aux = 0;

  if (x < gap) {
    x_aux = this->x - vel;
  } else if (x > w - gap) {
    x_aux = this->x + vel;
  } else if (y < gap) {
    y_aux = this->y - vel;
  } else if (y > h - gap) {
    y_aux = this->y + vel;
  }

  bool limits = x_aux >= 0 && y_aux >= 0 &&
      x_aux + w < mapWidth && y_aux + h < mapHeight + 30;

  return limits;
}
