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
    ObjectMapaVista *objectVista = NULL;
    std::vector<int> objectVistaWidht(mapWidht, 0);

    for (int xModel=0; xModel <= mapWidht; xModel++) {
        for (int yModel = 0; yModel < mapHeight; yModel++) {

//            std::cout << "x: " << xModel << " y: " << yModel << std::endl;
//            std::cout << "xV: " << xVista << " yV: " << yVista << std::endl;

            std::string type = map.getTypePos(xModel, yModel);
            if (type == "land") {
                objectVista = new Image("vista/images/terrain/rocks_jungle.png");
            }

            xVista = objectVistaWidht[yModel];
            objectVista->setPos(xVista, yVista);
            panel.add(objectVista);

            objectVistaWidht[yModel] += objectVista->getWidth();
            yVista += objectVista->getHeight();
        }
        yVista = 0;
    }
    objectVista = new Image("vista/images/terrain/fire_blue_r000_n00.png");
    objectVista->setPos(50, 50);
    panel.add(objectVista);

    panel.draw();
}
