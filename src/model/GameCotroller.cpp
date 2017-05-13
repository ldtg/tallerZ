#include "GameCotroller.h"
#include "AStar.h"
void GameCotroller::move(UnitID idunit, Position position) {
  Unit *unit = units[idunit];
  AStar astar(map, unit, map.getTile(position));
  unit->move(astar.find());
}
void GameCotroller::attack(UnitID attackerId, UnitID attackedId) {
  Unit *attacker = units.at(attackerId);
  Attackable *attacked = units.at(attackedId);
  if (attacker->isInRange(attacked)
      && map.canAttack(attacker->getCurrentPosition(),
                       attacked->getCurrentPosition())) {
    attacker->attack(attacked);
  } else {
    AStar astar(map, attacker, map.getTile(attacked->getCurrentPosition()));
    attacker->hunt(astar.find(), attacked);
  }
}
void GameCotroller::capture(UnitID idunit, Position position) {
  Unit *unit = units[idunit];
  AStar astar(map, unit, map.getTile(position));
  unit->capture(astar.find());
}
void GameCotroller::tick() {
  for (auto it_units = units.begin(); it_units != units.end();
       ++it_units) {
    Unit *current = it_units->second;
    current->receiveDamages();
    if (current->isAlive()) {
      if (current->isMoving()) {
        //TODO: crear evento move
        //map.procces(event)
        current->doMove();
      }
      if (current->isHunting()) {
        Attackable *hunted = current->getHunted();
        if (current->attackedInRange()
            && map.canAttack(current->getCurrentPosition(),
                             hunted->getCurrentPosition())) {
          current->doAttack();
          //TODO: crear evento attack
          //map.procces(event)
        } else {
          //TODO: crear evento move
          //map.procces(event)
          current->doMove();
        }
        if (hunted->isMoving())
          current->addMove(hunted->nextMove()); //en vez de recalcular el path uso los movs del atacado
      }
      if (current->isCapturing()) {
        //TODO: crear evento move
        //map.procces(event)
        current->doMove();
        if (current->isStill()) { //llego
          //TODO: crear evento captura
          //this->newCapture(current);
        }
      }
    } else {
      //TODO: crear evento muerte
      //map.procces(event)
      delete current;
      it_units = units.erase(it_units);
    }
  }
}
