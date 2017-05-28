#include <iostream>
#include "Model.h"
#include "Exceptions/model_exceptions/UnitNotFoundException.h"

Model::Model(Map &map, GameController &gc) : map(map) ,gameController(gc){}

void Model::leftClick(int x, int y) {
  Position pos(x, y);
  try{
    unitsSelected.push_back(map.getUnitIDFromPosition(pos, 30));
  } catch(const UnitNotFoundException &e){
    // No se hace nada si donde se hizo click no hay unidad.
  }
}

void Model::rightClick(int x, int y) {
  if (!unitsSelected.empty()) {
    Position pos(x, y);
    gameController.move(unitsSelected.front(), pos);
    unitsSelected.clear();
  }
}
