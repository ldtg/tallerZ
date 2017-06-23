#include "ObjectMapaVista.h"

ObjectMapaVista::ObjectMapaVista() : x(0), y(0), width(0), height(0),
                                     rotationDraw(0), rotation(0.0), pointRot(NULL) {}

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

void ObjectMapaVista::setDrawRotation(int rotation) {
  this->rotationDraw = rotation;
}

int ObjectMapaVista::getDrawRotation() const {
  return rotationDraw;
}

void ObjectMapaVista::setRotation(double rotation) {
  this->rotation = rotation;
}

double ObjectMapaVista::getRotation() const {
  return rotation;
}

void ObjectMapaVista::setPointRotation(SDL_Point *pointRot) {
  this->pointRot = pointRot;
}
