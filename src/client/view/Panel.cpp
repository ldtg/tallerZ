#include "Panel.h"
#include <iostream>

Panel::Panel(SDL_Renderer *render) : window_render(render) {}

Panel::~Panel() {
    for (ObjectMapaVista *objectMapaVista : objectsMapaVista) {
        delete (objectMapaVista);
    }
//    SDL_DestroyRenderer(window_render);
}

void Panel::add(ObjectMapaVista *objectMapaVista) {
  if (objectMapaVista== nullptr)
    throw std::invalid_argument("Panel::add() objectMapaVista es NULL");

  objectMapaVista->set_texture(window_render);
  objectsMapaVista.push_back(objectMapaVista);
}

void Panel::clean() {
    objectsMapaVista.clear();
}

void Panel::draw(Camera &camera) {
//    SDL_SetRenderDrawColor(window_render, 0xFF, 0xFF, 0xFF, 0xFF );
//    SDL_RenderClear(window_render);

    for (ObjectMapaVista *objectMapaVista : objectsMapaVista) {
        objectMapaVista->draw(window_render, camera);
    }

    SDL_RenderPresent(window_render);
    Panel::clean();
}
