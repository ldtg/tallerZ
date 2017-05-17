#ifndef TALLERZ_VISTA_H
#define TALLERZ_VISTA_H

#include "../model/Map.h"
#include "Window.h"
#include "Panel.h"
#include <string>

class Vista {
    private:
        Map &map;
        Window window;
        Panel panel;
        void add(ObjectMapaVista *objectVista, int x, int y);
    public:
        Vista(Map &map);
        ~Vista();
        ObjectMapaVista *getObjectVista(std::string type);
        void update();
};


#endif //TALLERZ_VISTA_H
