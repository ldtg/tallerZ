#include "Vista.h"
#include <string>
#include "Image.h"
#include "Sprite.h"
#include <iostream>
#include <vector>

Vista::Vista(Map &map) : map(map), window(), panel(window.getRender()) {}

Vista::~Vista() {}

void Vista::update() {
    int mapWidht = map.getWidht();
    int mapHeight = map.getHeight();
    int xVista = 0;
    int yVista = 0;
    ObjectMapaVista *background = NULL;
    ObjectMapaVista *objectVista = NULL;
    std::vector<int> objectVistaWidht(mapWidht, 0);

    for (int xModel=0; xModel <= mapWidht; xModel++) {
        for (int yModel=0; yModel < mapHeight; yModel++) {
            xVista = objectVistaWidht[yModel];

            std::vector<std::string> type = map.getTypePos(xModel, yModel);
            background = getObjectVista(type[0]);
            objectVista = getObjectVista(type[1]);

            add(background, xVista, yVista);
            //TODO: PONER (X,Y) DEL OBJ EN MAPA.
            add(objectVista, xModel, yModel);

            objectVistaWidht[yModel] += background->getWidth();
            yVista += background->getHeight();
        }
        yVista = 0;
    }
    panel.draw();
}

void Vista::add(ObjectMapaVista *objectVista, int x, int y) {
    if (objectVista == NULL)
        return;

    objectVista->setPos(x, y);
    panel.add(objectVista);
}

ObjectMapaVista* Vista::getObjectVista(std::string type) {
    if (type == "land") {
        return new Image("vista/images/terrain/rocks_jungle.png");
    } else if (type == "grunt") {
        return new Sprite("vista/images/terrain/fire_blue_r000_n", 2);
    }
    else {
        return nullptr;
    }
}
