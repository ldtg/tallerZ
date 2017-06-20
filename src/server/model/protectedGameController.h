#ifndef TALLERZ_PROTECTEDGAMECONTROLLER_H
#define TALLERZ_PROTECTEDGAMECONTROLLER_H

#include <server/serverGameController.h>
#include <mutex>
#include "realGameController.h"
class protectedGameController : public serverGameController {
 private:
  realGameController &gameController;
  std::mutex mutex;
 public:
  explicit protectedGameController(realGameController &gc);
  virtual void move(const UnitID &unit, const Position &position);
  virtual void attack(const UnitID &attacker, const UnitID &attacked);
  virtual void attack(const UnitID &attacker, const BuildID &attacked);
  virtual void attack(const UnitID &attacker,
                      const TerrainObjectID &attacked);
  virtual void changeUnitFab(const BuildID &buildId, const UnitType &type);
  virtual void capture(const UnitID &unit, const CapturableID &capturable);
  virtual void tick();
  virtual void playerDisconnected(const PlayerID player);
  ~protectedGameController() {};
};

#endif //TALLERZ_PROTECTEDGAMECONTROLLER_H
