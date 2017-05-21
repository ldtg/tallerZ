#include "Vista.h"
#include <string>
#include "Image.h"
#include "Sprite.h"
#include <iostream>
#include <vector>

Vista::Vista(const Map &map) : window(), panel(window.getRender()) {
  _quit = false;
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
        return new Image("../src/view/images/terrain/land.png");
    }
    else {
        return nullptr;
    }
}

ObjectMapaVista* Vista::getUnitVista(int type) {
  if (type == R_GRUNT) {
    return new Sprite("../src/view/images/terrain/fire_blue_r000_n", 3);
  }
  else {
    return nullptr;
  }
}

void Vista::setQuit() {
  _quit = true;
}

bool Vista::quit() {
  return _quit;
}
