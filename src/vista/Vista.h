#ifndef TALLERZ_VISTA_H
#define TALLERZ_VISTA_H

#include "../model/Map.h"
#include "Window.h"
#include "Panel.h"

class Vista {
    private:
        Map &map;
        Window window;
        Panel panel;
    public:
        Vista(Map &map);
        ~Vista();
        void update();
};


#endif //TALLERZ_VISTA_H
