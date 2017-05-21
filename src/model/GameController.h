#ifndef TALLERZ_GAMECOTROLLER_H
#define TALLERZ_GAMECOTROLLER_H

#include "Map.h"
#include "Unit.h"
#include "UnitID.h"
#include "BuildID.h"
#include "Build.h"
#include "Event.h"

class GameController {
 private:
  Map map;
  std::map<UnitID, Unit *> units;
  // std::map<BuildID, Build*> builds;
  void move(Unit *unit, std::vector<Event *> &events) const;
  void hunt(Unit *unit, std::vector<Event *> &events) const;
  void capture(Unit *unit, std::vector<Event *> &events) const;
  void unitReceiveDamage(Unit *current, std::vector<Event *> &events) const;
 public:
  GameController(const Map &map, const std::map<UnitID, Unit *> &units);
  void move(const UnitID &unit, const Position &position);
  void attack(const UnitID &attacker, const UnitID &attacked);
  //void attack(UnitID attacker, BuildID attacked);
  //void capture(UnitID unit, Position position);
  std::vector<Event *> tick();

  void updateMap(std::vector<Event *> vector);
  void removeDeaths(const std::vector<Unit *> &vector);
  void doTick(std::vector<Event *> &events);
  void autoAttack(Unit *current);
};

#endif //TALLERZ_GAMECOTROLLER_H
