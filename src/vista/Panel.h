#ifndef TALLERZ_PANEL_H
#define TALLERZ_PANEL_H

#include <SDL2/SDL.h>
#include "ObjectMapaVista.h"
#include <vector>

class Panel {
    private:
        SDL_Renderer *window_render;
        std::vector<ObjectMapaVista*> objectsMapaVista;
        void clean();
    public:
        Panel(SDL_Renderer *render);
        ~Panel();
        void add(ObjectMapaVista *objectMapaVista);
        void draw();
};


#endif //TALLERZ_PANEL_H
