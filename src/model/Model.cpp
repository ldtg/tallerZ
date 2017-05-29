#include <iostream>
#include "Model.h"
#include "Exceptions/model_exceptions/UnitNotFoundException.h"

Model::Model(Map &map, GameController &gc) : map(map) ,gameController(gc){}

void Model::leftClick(int x, int y) {
  Position pos(x, y);
  if (unitsSelected.empty()) {
    unitsSelected.push_back(map.getUnitIDFromPosition(pos, 30));
  } else {
      try {
        UnitID attacked = map.getUnitIDFromPosition(pos, 30);
        for (UnitID attacker : unitsSelected) {
          gameController.attack(attacker, attacked);
        }
        return;
      } catch(const UnitNotFoundException &e){
        // Donde se hizo click no hay unidad.
      }
      try {
        BuildID buildAttacked = map.getBuildIDFromPosition(pos, 100);
        for (UnitID attacker : unitsSelected) {
          gameController.attack(attacker, buildAttacked);
        }
      } catch(const UnitNotFoundException &e) {
        // Donde se hizo click no hay edificio ni undida.
        unitsSelected.clear();
      }
//    unitsSelected.clear();
  }
}

void Model::rightClick(int x, int y) {
  if (!unitsSelected.empty()) {
    Position pos(x, y);
    gameController.move(unitsSelected.front(), pos);
    unitsSelected.clear();
  }
}
