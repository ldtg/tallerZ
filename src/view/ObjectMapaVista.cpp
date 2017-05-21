#include "ObjectMapaVista.h"

ObjectMapaVista::~ObjectMapaVista() {}

int ObjectMapaVista::getWidth() const {
    return width;
}

int ObjectMapaVista::getHeight() const {
    return height;
}

void ObjectMapaVista::setPos(int x, int y) {
    this->x = x;
    this->y = y;
}

void ObjectMapaVista::set_texture(SDL_Renderer *render) {}
