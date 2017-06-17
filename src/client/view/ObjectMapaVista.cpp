#include "ObjectMapaVista.h"

ObjectMapaVista::ObjectMapaVista() : x(0), y(0), width(0),
                                     height(0), rotation(0) {}

int ObjectMapaVista::getWidth() const {
    return width;
}

int ObjectMapaVista::getHeight() const {
    return height;
}

void ObjectMapaVista::setPos(ViewPosition pos) {
    this->x = pos.getX();
    this->y = pos.getY();
}

void ObjectMapaVista::setPos(Position pos) {
  this->x = (float) pos.getX();
  this->y = (float) pos.getY();
}

Position ObjectMapaVista::getPos() const {
    return Position((long)x, (long)y);
}

ViewPosition ObjectMapaVista::getViewPos() const {
  return ViewPosition(x, y);
}

void ObjectMapaVista::setRotation(int rotation) {
  this->rotation = rotation;
}

int ObjectMapaVista::getRotation() {
  return rotation;
}
