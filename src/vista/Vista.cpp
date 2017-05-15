#include "Vista.h"
#include <string>
#include "Image.h"
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

//            std::cout << "x: " << xModel << " y: " << yModel << std::endl;
//            std::cout << "xV: " << xVista << " yV: " << yVista << std::endl;
            xVista = objectVistaWidht[yModel];

            std::vector<std::string> type = map.getTypePos(xModel, yModel);
            background = getObjectVista(type[0]);
            objectVista = getObjectVista(type[1]);

            background->setPos(xVista, yVista);
            panel.add(background);
            if (objectVista != NULL) {
                //TODO: POENER (X,Y) DEL OBJ EN MAPA.
                objectVista->setPos(xModel, yModel);
                panel.add(objectVista);
            }

            objectVistaWidht[yModel] += background->getWidth();
            yVista += background->getHeight();
        }
        yVista = 0;
    }

    panel.draw();
}

ObjectMapaVista* Vista::getObjectVista(std::string type) {
    if (type == "land") {
        return new Image("vista/images/terrain/rocks_jungle.png");
    } else if (type == "grunt") {
        return new Image("vista/images/terrain/fire_blue_r000_n00.png");
    }
    else {
        return NULL;
    }
}
