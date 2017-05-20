#include "Vista.h"
#include <string>
#include "Image.h"
#include "Sprite.h"
#include <iostream>
#include <vector>

Vista::Vista(const Map &map) : window(), panel(window.getRender()) {
  createInitialTerrainVista(map.getMap());
  createInitialUnitVista(map.getUnits());
}

Vista::~Vista() {}

void Vista::createInitialTerrainVista(const std::map<Position, Tile> &map) {
  for (auto const &posMap : map) {
    Position pos = posMap.first;
    Tile tile = posMap.second;
    TerrainType terrainType = tile.getTerrainType();
    ObjectMapaVista *terrain = getTerrainVista(terrainType);
    add(terrain, pos.getX(), pos.getY());

    terrainsVista.emplace(pos, terrain);
  }
}

void Vista::createInitialUnitVista(const std::map<UnitID, UnitState> &units) {
  for (auto const &unit : units) {
    UnitType type = unit.first.getType();
    Position pos = unit.second.currentPosition;
    ObjectMapaVista *unitVista = getUnitVista(type);
    add(unitVista, pos.getX(), pos.getY());

    unitsVista.emplace(pos, unitVista);
  }
}

void Vista::update() {
/*
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
*/
  for (auto const &posTerrain : terrainsVista) {
      panel.add(posTerrain.second);
  }

  for (auto const &posUnit : unitsVista) {
    panel.add(posUnit.second);
  }

  panel.draw();
}

void Vista::add(ObjectMapaVista *objectVista, long x, long y) {
    if (objectVista == NULL)
        return;

    objectVista->setPos(x, y);
    panel.add(objectVista);
}

ObjectMapaVista* Vista::getTerrainVista(int type) {
    if (type == LAND) {
        return new Image("../src/vista/images/terrain/land.png");
    }
    else {
        return nullptr;
    }
}

ObjectMapaVista* Vista::getUnitVista(int type) {
  if (type == R_GRUNT) {
    return new Sprite("../src/vista/images/terrain/fire_blue_r000_n", 5);
  }
  else {
    return nullptr;
  }
}