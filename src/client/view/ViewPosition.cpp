#include <cmath>
#include <iostream>
#include "ViewPosition.h"

ViewPosition::ViewPosition(float x, float y) {
  this->x = x;
  this->y = y;
}

float ViewPosition::getX() const {
  return this->x;
}

float ViewPosition::getY() const {
  return this->y;
}

Position ViewPosition::getPos() const {
  return Position((long)x, (long)y);
}

void ViewPosition::add(ViewPosition other) {
  this->x += other.x;
  this->y += other.y;
}

double ViewPosition::getRotation(const ViewPosition &target) const {
  float deltaY = (-1*target.y) - (-1*this->y);
  float deltaX = target.x - this->x;
  double rotation = std::atan2(deltaY, deltaX) * 180.0000 / M_PI;

  return rotation/-1;
}

int ViewPosition::getDrawRoration(const ViewPosition &target) const {
  double rotation = getRotation(target)*-1;
  if (rotation < 0) {
    rotation += 360;
  }

  if (rotation >= 0 && rotation < 22.5) {
    return 0;
  }
  else if (rotation > 22.5 && rotation <= 67.5) {
    return 45;
  }
  else if (rotation > 67.5 && rotation <= 112.5) {
    return 90;
  }
  else if (rotation > 112.5 && rotation <= 157.5) {
    return 135;
  }
  else if (rotation > 157.5 && rotation <= 202.5) {
    return 180;
  }
  else if (rotation > 202.5 && rotation <= 247.5) {
    return 225;
  }
  else if (rotation > 247.5 && rotation <= 292.5) {
    return 270;
  }
  else {
    return 315;
  }
}
