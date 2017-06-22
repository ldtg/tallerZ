#include "ProtectedGameController.h"
ProtectedGameController::ProtectedGameController(RealGameController &gc)
    : gameController(gc) {}

void ProtectedGameController::move(const UnitID &unit,
                                   const Position &position) {
  std::unique_lock<std::mutex> lck(mutex);
  gameController.move(unit, position);
}

void ProtectedGameController::attack(const UnitID &attacker,
                                     const UnitID &attacked) {
  std::unique_lock<std::mutex> lck(mutex);
  gameController.attack(attacker, attacked);
}

void ProtectedGameController::attack(const UnitID &attacker,
                                     const BuildID &attacked) {
  std::unique_lock<std::mutex> lck(mutex);
  gameController.attack(attacker, attacked);
}

void ProtectedGameController::attack(const UnitID &attacker,
                                     const TerrainObjectID &attacked) {
  std::unique_lock<std::mutex> lck(mutex);
  gameController.attack(attacker, attacked);
}

void ProtectedGameController::changeUnitFab(const BuildID &buildId,
                                            const UnitType &type) {
  std::unique_lock<std::mutex> lck(mutex);
  gameController.changeUnitFab(buildId, type);
}

void ProtectedGameController::capture(const UnitID &unit,
                                      const CapturableID &capturable) {
  std::unique_lock<std::mutex> lck(mutex);
  gameController.capture(unit, capturable);
}

void ProtectedGameController::tick() {
  std::unique_lock<std::mutex> lck(mutex);
  gameController.tick();
}

void ProtectedGameController::playerDisconnected(const PlayerID player) {
  std::unique_lock<std::mutex> lck(mutex);
  gameController.playerDisconnected(player);
}

ProtectedGameController::~ProtectedGameController(){}
