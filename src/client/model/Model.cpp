#include <iostream>
#include <front_end/SDL_Interface/Menus/Production/Production_Menu.h>
#include "Model.h"
#include "Exceptions/model_exceptions/UnitNotFoundException.h"

Model::Model(Map &map, GameControllerProxy &gc, Camera &camera, View &view)
    : map(map), gameController(gc), camera(camera), view(view) {}

void Model::leftClick(int x, int y) {
  Position pos(x + camera.x, y + camera.y);
  if (unitsSelected.empty()) {
    try {
      UnitID unit = map.getUnitIDFromPosition(pos, 40);
      unitsSelected.push_back(unit);
      view.show_unit_side_details(unit.getType());
    } catch(const UnitNotFoundException &e){
      view.clear_unit_side_details();
      // Donde se hizo click no hay unidad.
    }
  }
  if (view.get_present_menu() == nullptr) {
    try {
      BuildID factoryID = map.getBuildIDFromPosition(pos,50);
      view.load_production_menu(factoryID,map.getBuilds().at(factoryID),*this,x,y);
    } catch(const UnitNotFoundException &e){
      // Donde se hizo click no hay fabrica
    }
  } else {
    if (!view.get_present_menu()->isInRectangle(x, y)) {
      std::cout << std::to_string((size_t)view.get_present_menu());
      view.free_menu();
    } else {
      view.get_present_menu()->handle_click(x, y);
    }
  }
  if (view.get_side_board()->is_in_menu_button(x,y)){
    if (view.get_present_menu() != nullptr){
      view.free_menu();
    }
    view.get_side_board()->launch_menu_button();
  }
}

void Model::rightClick(int x, int y) {
  if (unitsSelected.empty()) {
    return;
  }

  Position pos(x + camera.x, y + camera.y);

  try {
    CapturableID capturable = map.getCapturableIDFromPosition(pos, 40);
    for (UnitID unit : unitsSelected) {
      gameController.capture(unit, capturable);
    }
    unitsSelected.clear();
    return;
  } catch (const UnitNotFoundException &e) {
    // Donde se hizo click no hay edificio ni undida.
  }
  try {
    UnitID attacked = map.getUnitIDFromPosition(pos, 40);
    for (UnitID attacker : unitsSelected) {
      gameController.attack(attacker, attacked);
    }
    unitsSelected.clear();
    return;
  } catch (const UnitNotFoundException &e) {
    // Donde se hizo click no hay unidad.
  }
  try {
    BuildID buildAttacked = map.getBuildIDFromPosition(pos, 50);

    for (UnitID attacker : unitsSelected) {
      gameController.attack(attacker, buildAttacked);
    }
    unitsSelected.clear();
    return;
  } catch (const UnitNotFoundException &e) {
    // Donde se hizo click no hay edificio ni undida.
  }
  try {
    TerrainObjectID terrainID = map.getTerrainObjectIDFromPosition(pos, 50);

    for (UnitID attacker : unitsSelected) {
      gameController.attack(attacker, terrainID);
    }
    unitsSelected.clear();
    return;
  } catch (const UnitNotFoundException &e) {
    // Donde se hizo click no hay edificio ni undida.
  }

  gameController.move(unitsSelected.front(), pos);
  unitsSelected.clear();
}

Map &Model::getMap() {
  return map;
}

GameControllerProxy *Model::get_gameControllerProxy() {
  return &gameController;
}

