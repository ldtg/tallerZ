#include "ObjectView.h"

ObjectView::ObjectView() : x(0), y(0), width(0), height(0),
                           rotationDraw(0), rotation(0.0), pointRot(NULL) {}

int ObjectView::getWidth() const {
    return width;
}

int ObjectView::getHeight() const {
    return height;
}

void ObjectView::setPos(ViewPosition pos) {
    this->x = pos.getX();
    this->y = pos.getY();
}

void ObjectView::setPos(Position pos) {
  this->x = (float) pos.getX();
  this->y = (float) pos.getY();
}

Position ObjectView::getPos() const {
    return Position((long)x, (long)y);
}

ViewPosition ObjectView::getViewPos() const {
  return ViewPosition(x, y);
}

void ObjectView::setDrawRotation(int rotation) {
  this->rotationDraw = rotation;
}

int ObjectView::getDrawRotation() const {
  return rotationDraw;
}

void ObjectView::setRotation(double rotation) {
  this->rotation = rotation;
}

double ObjectView::getRotation() const {
  return rotation;
}

void ObjectView::setPointRotation(SDL_Point *pointRot) {
  this->pointRot = pointRot;
}
