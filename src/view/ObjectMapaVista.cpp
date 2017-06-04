#include "ObjectMapaVista.h"

int ObjectMapaVista::getWidth() const {
    return width;
}

int ObjectMapaVista::getHeight() const {
    return height;
}

void ObjectMapaVista::setPos(Position pos) {
    this->x = pos.getX();
    this->y = pos.getY();
}

Position ObjectMapaVista::getPos() const {
    return Position(x, y);
}

void ObjectMapaVista::setRotation(int rotation) {
  this->rotation = rotation;
}

int ObjectMapaVista::getRotation() {
  return rotation;
}
ObjectMapaVista::ObjectMapaVista() : x(0),y(0),width(0),height(0),rotation(0){
}

//void ObjectMapaVista::set_texture(SDL_Renderer *render) {}
