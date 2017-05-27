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

//void ObjectMapaVista::setPosTo(Position &pos) {
//  this->posTo = pos;
//}

void ObjectMapaVista::set_texture(SDL_Renderer *render) {}
