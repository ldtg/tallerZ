#include <iostream>
#include "Model.h"
#include "Exceptions/model_exceptions/UnitNotFoundException.h"

Model::Model(Map &map, GameController &gc) : map(map) ,gameController(gc){}

void Model::leftClick(int x, int y) {
  Position pos(x, y);
  try{
    if (unitsSelected.empty()) {
      unitsSelected.push_back(map.getUnitIDFromPosition(pos, 30));
    } else {
      UnitID attacked = map.getUnitIDFromPosition(pos, 30);
      for (UnitID attacker : unitsSelected) {
        gameController.attack(attacker, attacked);
      }
      unitsSelected.clear();
    }
  } catch(const UnitNotFoundException &e){
    // Donde se hizo click no hay unidad.
    unitsSelected.clear();
  }
}

void Model::rightClick(int x, int y) {
  if (!unitsSelected.empty()) {
    Position pos(x, y);
    gameController.move(unitsSelected.front(), pos);
    unitsSelected.clear();
  }
}
