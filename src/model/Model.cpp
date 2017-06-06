#include <iostream>
#include "Model.h"
#include "Exceptions/model_exceptions/UnitNotFoundException.h"

Model::Model(Map &map, GameController &gc, Camera &camera)
    : map(map) ,gameController(gc), camera(camera) {}

void Model::leftClick(int x, int y) {
  Position pos(x + camera.x, y + camera.y);
  if (unitsSelected.empty()) {
    try {
      unitsSelected.push_back(map.getUnitIDFromPosition(pos, 20));
    } catch(const UnitNotFoundException &e){
      // Donde se hizo click no hay unidad.
    }
  }
}

void Model::rightClick(int x, int y) {
  if (unitsSelected.empty()) {
    return;
  }

  Position pos(x + camera.x, y + camera.y);

  try {
    UnitID attacked = map.getUnitIDFromPosition(pos, 20);
    for (UnitID attacker : unitsSelected) {
      gameController.attack(attacker, attacked);
    }
    unitsSelected.clear();
    return;
  } catch(const UnitNotFoundException &e){
    // Donde se hizo click no hay unidad.
  }
  try {
    BuildID buildAttacked = map.getBuildIDFromPosition(pos, 50);
    for (UnitID attacker : unitsSelected) {
      gameController.attack(attacker, buildAttacked);
    }
    unitsSelected.clear();
    return;
  } catch(const UnitNotFoundException &e) {
    // Donde se hizo click no hay edificio ni undida.
  }
  try {
    CapturableID capturable = map.getCapturableIDFromPosition(pos, 20);
    for (UnitID unit : unitsSelected) {
      gameController.capture(unit, capturable);
    }
    unitsSelected.clear();
    return;
  } catch(const UnitNotFoundException &e) {
    // Donde se hizo click no hay edificio ni undida.
  }

   gameController.move(unitsSelected.front(), pos);
   unitsSelected.clear();
}
