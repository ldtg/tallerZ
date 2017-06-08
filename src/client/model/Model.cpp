#include <iostream>
#include <Exceptions/model_exceptions/BuildingNotFoundException.h>
#include <front_end/SDL_Interface/Menus/Production/Production_Menu.h>
#include "Model.h"
#include "Exceptions/model_exceptions/UnitNotFoundException.h"

Model::Model(Map &map, GameController &gc, Camera &camera, View &view)
    : map(map) ,gameController(gc), camera(camera), view(view) {}

void Model::leftClick(int x, int y) {
  Position pos(x + camera.x, y + camera.y);
  if (unitsSelected.empty()) {
    try {
      unitsSelected.push_back(map.getUnitIDFromPosition(pos, 20));
    } catch(const UnitNotFoundException &e){
      // Donde se hizo click no hay unidad.
    }
  }
  if (view.get_present_menu() == nullptr){
    try {
      BuildID factoryID = map.getBuildIDFromPosition(pos,50);
      view.load_production_menu(x,y);
    } catch(const UnitNotFoundException &e){
      // Donde se hizo click no hay fabrica
    }
  } else {
    if (!view.get_present_menu()->isInRectangle(x,y)){
      view.free_menu();
    } else {
      view.get_present_menu()->handle_click(x,y);
    }
  }
}

void Model::rightClick(int x, int y) {
  if (unitsSelected.empty()) {
    return;
  }

  Position pos(x + camera.x, y + camera.y);

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

   gameController.move(unitsSelected.front(), pos);
   unitsSelected.clear();
}
