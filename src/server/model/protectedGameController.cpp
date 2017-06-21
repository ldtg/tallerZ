#include "protectedGameController.h"
protectedGameController::protectedGameController(realGameController &gc)
    : gameController(gc) {}

void protectedGameController::move(const UnitID &unit,
                                   const Position &position) {
  std::unique_lock<std::mutex> lck(mutex);
  gameController.move(unit, position);
}

void protectedGameController::attack(const UnitID &attacker,
                                     const UnitID &attacked) {
  std::unique_lock<std::mutex> lck(mutex);
  gameController.attack(attacker, attacked);
}

void protectedGameController::attack(const UnitID &attacker,
                                     const BuildID &attacked) {
  std::unique_lock<std::mutex> lck(mutex);
  gameController.attack(attacker, attacked);
}

void protectedGameController::attack(const UnitID &attacker,
                                     const TerrainObjectID &attacked) {
  std::unique_lock<std::mutex> lck(mutex);
  gameController.attack(attacker, attacked);
}

void protectedGameController::changeUnitFab(const BuildID &buildId,
                                            const UnitType &type) {
  std::unique_lock<std::mutex> lck(mutex);
  gameController.changeUnitFab(buildId, type);
}

void protectedGameController::capture(const UnitID &unit,
                                      const CapturableID &capturable) {
  std::unique_lock<std::mutex> lck(mutex);
  gameController.capture(unit, capturable);
}

void protectedGameController::tick() {
  std::unique_lock<std::mutex> lck(mutex);
  gameController.tick();
}

void protectedGameController::playerDisconnected(const PlayerID player) {
  std::unique_lock<std::mutex> lck(mutex);
  gameController.playerDisconnected(player);
}

protectedGameController::~protectedGameController(){}
