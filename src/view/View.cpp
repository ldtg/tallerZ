#include "View.h"
#include <string>
#include "Image.h"
#include "Sprite.h"
#include <iostream>
#include <vector>
#include <model/Events/UnitMoveStepEvent.h>

View::View(const Map &map, EventHandler &eventHandler, Window& window)
    : window(window), panel(window.getRender()), eventHandler(eventHandler) {
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
    add(terrain, tile.getCornerPosition());

    terrainsVista.emplace(pos, terrain);
  }
}

void View::createInitialUnitVista(const std::map<UnitID, UnitState> &units) {
  for (auto const &unit : units) {
    UnitType type = unit.first.getType();
    Position pos = unit.second.position;
    ObjectMapaVista *unitVista = getUnitVista(type);
    add(unitVista, pos);

    unitsVista.emplace(unit.first, unitVista);
  }
}

//void View::setEventHandler(EventHandler &eventHandler) {
//  this->eventHandler = eventHandler;
//}

void View::update() {
  while (!eventHandler.empty()) {
    Event *event = eventHandler.get();
    event->process();
    //TODO: VER QUIEN HAVE DELETE EN ESTOS EVENT
//    delete (event);
    draw();
  }
  draw();
}

void View::draw() {
  for (auto const &posTerrain : terrainsVista) {
    panel.add(posTerrain.second);
  }

  for (auto const &posUnit : unitsVista) {
    panel.add(posUnit.second);
  }

  panel.draw();
}

void View::add(ObjectMapaVista *objectVista, Position pos) {
    if (objectVista == NULL)
      throw std::invalid_argument("View::add() objectMapaVista es NULL");

    objectVista->setPos(pos);
    panel.add(objectVista);
}

ObjectMapaVista* View::getTerrainVista(TerrainType type) {
    if (type == LAND) {
        return new Image("../src/view/images/terrain/land.png");
    }
    else {
        return nullptr;
    }
}

ObjectMapaVista* View::getUnitVista(UnitType type) {
  if (type == R_GRUNT) {
    return new Sprite("../src/view/images/units/walk_blue_r000_n", 4);
  }
  else {
    return nullptr;
  }
}

void View::move(UnitID id, Position posTo) {
  Position pos_aux = unitsVista.at(id)->getPos();
  while (pos_aux != posTo) {
    pos_aux.move(posTo);
    eventHandler.add(new UnitMoveStepEvent(id, pos_aux));
//    unitsVista.at(id)->setPos(posTo);
//    panel.draw();
//    update();
  }
}

void View::setQuit() {
  _quit = true;
}

bool View::quit() {
  return _quit;
}

std::map<UnitID, ObjectMapaVista*>& View::getUnitsVista() {
  return unitsVista;
}
