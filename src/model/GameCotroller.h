#ifndef TALLERZ_GAMECOTROLLER_H
#define TALLERZ_GAMECOTROLLER_H

#include "Map.h"
#include "Unit.h"
#include "UnitID.h"
#include "BuildID.h"
#include "Build.h"
#include "Event.h"

class GameCotroller {
 private:
  Map map;
  std::map<UnitID, Unit*> units;
 // std::map<BuildID, Build*> builds;
  // map de current attacks?
  void move(Unit *unit, std::vector<Event*> &events);
  void hunt(Unit *unit, std::vector<Event*> &events);
  void capture(Unit *unit, std::vector<Event*> &events);
 public:
  void move(UnitID &unit, Position &position);
  void attack(UnitID attacker, UnitID attacked);
 // void attack(UnitID attacker, BuildID attacked);
  //void capture(UnitID unit, Position position);
  std::vector<Event*> tick();

};

#endif //TALLERZ_GAMECOTROLLER_H
