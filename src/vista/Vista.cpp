#include "Vista.h"
#include <string>
#include "Image.h"

Vista::Vista(Map &map) : map(map), window(), panel(window.getRender()) {
}

Vista::~Vista() {}

void Vista::update() {
    std::string type = map.getTypePos(0,0);
    if (type == "land") {
        Image *image0 = new Image("vista/images/terrain/rocks_jungle.png");
        image0->setPos(0,0);
        panel.add(image0);

        Image *image = new Image("vista/images/terrain/fire_blue_r000_n00.png");
        image->setPos(0,0);
        panel.add(image);
    }
    Image *image0 = new Image("vista/images/terrain/rocks_jungle.png");
    image0->setPos(96,0);
    panel.add(image0);

    panel.draw();
}
