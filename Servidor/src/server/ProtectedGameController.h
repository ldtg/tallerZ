#ifndef TALLERZ_PROTECTEDGAMECONTROLLER_H
#define TALLERZ_PROTECTEDGAMECONTROLLER_H

#include <server/model/GameController.h>
#include <mutex>
#include "server/model/RealGameController.h"
class ProtectedGameController : public GameController {
 private:
  RealGameController &gameController;
  std::mutex mutex;
 public:
  explicit ProtectedGameController(RealGameController &gc);
  virtual void move(const UnitID &unit, const Position &position);
  virtual void attack(const UnitID &attacker, const UnitID &attacked);
  virtual void attack(const UnitID &attacker, const BuildID &attacked);
  virtual void attack(const UnitID &attacker, const TerrainObjectID &attacked);
  virtual void changeUnitFab(const BuildID &buildId, const UnitType &type);
  virtual void capture(const UnitID &unit, const CapturableID &capturable);
  virtual void tick();
  virtual void playerDisconnected(const PlayerID player);
  virtual ~ProtectedGameController();
};

#endif //TALLERZ_PROTECTEDGAMECONTROLLER_H
