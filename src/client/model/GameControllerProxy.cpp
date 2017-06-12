#include <client/model/Commands/Unit/clientUnitMoveCommand.h>
#include <client/model/Commands/Unit/clientUnitAttackUnitCommand.h>
#include <client/model/Commands/Unit/clientUnitAttackBuildCommand.h>
#include <client/model/Commands/Unit/clientUnitAttackTOCommand.h>
#include <client/model/Commands/Unit/clientUnitCaptureCommand.h>
#include <client/model/Commands/Build/clientBuildChangeUnitCommand.h>
#include "GameControllerProxy.h"
GameControllerProxy::GameControllerProxy(Queue<clientCommand *> &queue) : queue(
    queue) {}
void GameControllerProxy::move(const UnitID &unit, const Position &position) {
  queue.push(new clientUnitMoveCommand(unit, position));
}
void GameControllerProxy::attack(const UnitID &attacker,
                                 const UnitID &attacked) {
  queue.push(new clientUnitAttackUnitCommand(attacker, attacked));
}
void GameControllerProxy::attack(const UnitID &attacker,
                                 const BuildID &attacked) {
  queue.push(new clientUnitAttackBuildCommand(attacker, attacked));
}
void GameControllerProxy::attack(const UnitID &attacker,
                                 const TerrainObjectID &attacked) {
  queue.push(new clientUnitAttackTOCommand(attacker, attacked));
}
void GameControllerProxy::changeUnitFab(const BuildID &buildId,
                                        const UnitType &type) {
  queue.push(new clientBuildChangeUnitCommand(buildId, type));
}
void GameControllerProxy::capture(const UnitID &unit,
                                  const CapturableID &capturable) {
  queue.push(new clientUnitCaptureCommand(unit, capturable));
}


