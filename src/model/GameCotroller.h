#ifndef TALLERZ_GAMECOTROLLER_H
#define TALLERZ_GAMECOTROLLER_H

#include "Map.h"
#include "Unit.h"
#include "UnitID.h"

class GameCotroller {
 private:
  Map map;
  std::map<UnitID, Unit*> units;
 public:
  void move(UnitID unit, Position position);
  void attack(UnitID attacker, UnitID attacked);
  void capture(UnitID unit, Position position);
  void tick();
};

#endif //TALLERZ_GAMECOTROLLER_H
