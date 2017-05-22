#include "View.h"
#include <string>
#include "Image.h"
#include "Sprite.h"
#include <iostream>
#include <vector>

View::View(const Map &map, EventHandler &eventHandler)
    : window(), panel(window.getRender()), eventHandler(eventHandler) {
  _quit = false;
  createInitialTerrainVista(map.getMap());
  createInitialUnitVista(map.getUnits());
}

View::~View() {}

void View::createInitialTerrainVista(const std::map<Position, Tile> &map) {
  for (auto const &posMap : map) {
    Position pos = posMap.first;
    Tile tile = posMap.second;
    TerrainType terrainType = tile.getTerrainType();
    ObjectMapaVista *terrain = getTerrainVista(terrainType);
    add(terrain, pos.getX(), pos.getY());

    terrainsVista.emplace(pos, terrain);
  }
}

void View::createInitialUnitVista(const std::map<UnitID, UnitState> &units) {
  for (auto const &unit : units) {
    UnitType type = unit.first.getType();
    Position pos = unit.second.currentPosition;
    ObjectMapaVista *unitVista = getUnitVista(type);
    add(unitVista, pos.getX(), pos.getY());

    unitsVista.emplace(pos, unitVista);
  }
}

//void View::setEventHandler(EventHandler &eventHandler) {
//  this->eventHandler = eventHandler;
//}

void View::update() {
  if (!eventHandler.empty()) {
    Event *event = eventHandler.get();
    event->process();
  }

  for (auto const &posTerrain : terrainsVista) {
      panel.add(posTerrain.second);
  }

  for (auto const &posUnit : unitsVista) {
    panel.add(posUnit.second);
  }

  panel.draw();
}

void View::add(ObjectMapaVista *objectVista, long x, long y) {
    if (objectVista == NULL)
        return;

    objectVista->setPos(x, y);
    panel.add(objectVista);
}

ObjectMapaVista* View::getTerrainVista(int type) {
    if (type == LAND) {
        return new Image("../src/view/images/terrain/land.png");
    }
    else {
        return nullptr;
    }
}

ObjectMapaVista* View::getUnitVista(int type) {
  if (type == R_GRUNT) {
    return new Sprite("../src/view/images/terrain/fire_blue_r000_n", 3);
  }
  else {
    return nullptr;
  }
}

void View::setQuit() {
  _quit = true;
}

bool View::quit() {
  return _quit;
}
