#ifndef TALLERZ_GAMECONTROLLERPROXY_H
#define TALLERZ_GAMECONTROLLERPROXY_H
class GameController;
#include <server/model/GameController.h>
class GameControllerProxy {
 private:
  GameController &gc;//test
 public:
  GameControllerProxy(GameController &gc);
  void move(const UnitID &unit, const Position &position);
  void attack(const UnitID &attacker, const UnitID &attacked);
  void attack(const UnitID &attacker, const BuildID &attacked);
  void attack(const UnitID &attacker, const TerrainObjectID &attacked);
  void changeUnitFab(const BuildID &buildId, const UnitType &type);
  void capture(const UnitID &unit, const CapturableID &capturable);
};

#endif //TALLERZ_GAMECONTROLLERPROXY_H
