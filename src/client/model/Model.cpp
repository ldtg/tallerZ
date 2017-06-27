#include <iostream>
#include <front_end/SDL_Interface/Menus/Production/Production_Menu.h>
#include "Model.h"
#include "Exceptions/model_exceptions/UnitNotFoundException.h"

Model::Model(Map &map,
             GameControllerProxy &gameController,
             Camera &camera,
             View &view,
             const PlayerID &player,
             const TeamID &teamID)
    : map(map),
      gameController(gameController),
      camera(camera),
      view(view),
      player(player),
      teamID(teamID) {

  unitSearchRange = 15;
  capturableSearchRange = 20;
  buildSearchRange = 50;
  terrainObjSearchRange = 50;
  view.load_side_board(*this);
}

void Model::leftClick(int x, int y) {
  Position pos(x + camera.x, y + camera.y);
  unitsSelected.clear();

  try {
    UnitID unit = map.getUnitIDFromPosition(pos, unitSearchRange);
    if (map.getUnitState(unit).owner == player) {
      unitsSelected.push_back(unit);
      unsigned short health = map.getUnitState(unit).healthPercent;
      view.show_unit_side_details(unit);
    }
  } catch (const UnitNotFoundException &e) {
    view.clear_unit_side_details();
    // Donde se hizo click no hay unidad.
  }

  if (view.get_present_menu() == nullptr) {
    try {
      BuildID factoryID = map.getBuildIDFromPosition(pos, buildSearchRange);
      if (map.getBuildState(factoryID).owner == player) {
        view.load_production_menu(factoryID,
                                  map.getBuilds().at(factoryID),
                                  *this, x, y);
      }
    } catch (const UnitNotFoundException &e) {
      // Donde se hizo click no hay edificio.
    }
  } else {
    if (!view.get_present_menu()->isInRectangle(x, y)) {
      view.free_menu();
    } else {
      view.get_present_menu()->handle_click(x, y);
    }
  }
  if (view.get_side_board()->is_in_quit_button(x, y)) {
    if (view.get_present_menu() != nullptr) {
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
    CapturableID
        capturable = map.getCapturableIDFromPosition(pos, capturableSearchRange);
    for (UnitID unit : unitsSelected) {
      gameController.capture(unit, capturable);
    }
    if (capturable.getType() == UNIT) {
      unitsSelected.clear();
      // Se selecciona la unidad capturada.
      UnitID unit = map.getUnitIDFromPosition(pos, unitSearchRange);
      unitsSelected.push_back(unit);
      unsigned short health = map.getUnitState(unit).healthPercent;
      view.show_unit_side_details(unit);
    }
    return;
  } catch (const UnitNotFoundException &e) {
    // Donde se hizo click no hay un capturable.
  }

  try {
    UnitID attacked = map.getUnitIDFromPosition(pos, unitSearchRange);
    for (UnitID attacker : unitsSelected) {
      gameController.attack(attacker, attacked);
    }
    return;
  } catch (const UnitNotFoundException &e) {
    // Donde se hizo click no hay una unidad.
  }

  try {
    BuildID buildAttacked = map.getBuildIDFromPosition(pos, buildSearchRange);
    for (UnitID attacker : unitsSelected) {
      gameController.attack(attacker, buildAttacked);
    }
    return;
  } catch (const UnitNotFoundException &e) {
    // Donde se hizo click no hay un edificio.
  }

  try {
    TerrainObjectID terrainID =
        map.getTerrainObjectIDFromPosition(pos, terrainObjSearchRange);
    for (UnitID attacker : unitsSelected) {
      gameController.attack(attacker, terrainID);
    }
    return;
  } catch (const UnitNotFoundException &e) {
    // Donde se hizo click no hay un terrainObject.
  }

  gameController.move(unitsSelected.front(), pos);
}

Map &Model::getMap() {
  return map;
}

GameControllerProxy *Model::get_gameControllerProxy() {
  return &gameController;
}

PlayerID Model::getPlayer() const {
  return player;
}

TeamID Model::getTeamID() const {
  return teamID;
}

std::vector<UnitID> Model::getUnitsSelected() {
  return unitsSelected;
}

void Model::clearUnitsSelected() {
  unitsSelected.clear();
}
