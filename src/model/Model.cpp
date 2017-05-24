#include <iostream>
#include "Model.h"
#include "UnitNotFoundException.h"

Model::Model(Map &map, GameController &gc) : map(map) ,gameController(gc){}

void Model::click(int x, int y) {
  Position pos(x, y);
  try{
  if (unitsSelected.empty()) {
    unitsSelected.push_back(map.getUnitIDFromPosition(pos, 50));
  } else {
    gameController.move(unitsSelected.front(), pos);
  }}catch(const UnitNotFoundException &e){
    std::cerr<<"aadasd"<<std::endl;
  }
}
