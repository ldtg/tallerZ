#include <client/model/Commands/Unit/clientUnitMoveCommand.h>
#include <server/model/Commands/serverCommandFactory.h>
#include <sstream>
#include <client/model/Commands/Unit/clientUnitAttackUnitCommand.h>
#include <client/model/Commands/Unit/clientUnitAttackBuildCommand.h>
#include <client/model/Commands/Unit/clientUnitAttackTOCommand.h>
#include <client/model/Commands/Unit/clientUnitCaptureCommand.h>
#include <client/model/Commands/Build/clientBuildChangeUnitCommand.h>
#include "GameControllerProxy.h"
void GameControllerProxy::move(const UnitID &unit, const Position &position) {
  clientUnitMoveCommand move(unit, position);
  //para test sin separar
  std::stringstream ss = move.getDataToSend();
  serverCommand *sc = serverCommandFactory::createCommand(move.getType(), ss);
  sc->execute(gc);
  delete sc;
}
void GameControllerProxy::attack(const UnitID &attacker,
                                 const UnitID &attacked) {
  clientUnitAttackUnitCommand attack(attacker, attacked);
  //para test sin separar
  std::stringstream ss = attack.getDataToSend();
  serverCommand *sc = serverCommandFactory::createCommand(attack.getType(), ss);
  sc->execute(gc);
  delete sc;
}
void GameControllerProxy::attack(const UnitID &attacker,
                                 const BuildID &attacked) {
  clientUnitAttackBuildCommand attack(attacker, attacked);
  //para test sin separar
  std::stringstream ss = attack.getDataToSend();
  serverCommand *sc = serverCommandFactory::createCommand(attack.getType(), ss);
  sc->execute(gc);
  delete sc;

}
void GameControllerProxy::attack(const UnitID &attacker,
                                 const TerrainObjectID &attacked) {
  clientUnitAttackTOCommand attack(attacker, attacked);
  //para test sin separar
  std::stringstream ss = attack.getDataToSend();
  serverCommand *sc = serverCommandFactory::createCommand(attack.getType(), ss);
  sc->execute(gc);
  delete sc;
}
void GameControllerProxy::changeUnitFab(const BuildID &buildId,
                                        const UnitType &type) {
  clientBuildChangeUnitCommand change(buildId, type);
  //para test sin separar
  std::stringstream ss = change.getDataToSend();
  serverCommand *sc = serverCommandFactory::createCommand(change.getType(), ss);
  sc->execute(gc);
  delete sc;
}
void GameControllerProxy::capture(const UnitID &unit,
                                  const CapturableID &capturable) {
  clientUnitCaptureCommand capt(unit, capturable);
  //para test sin separar
  std::stringstream ss = capt.getDataToSend();
  serverCommand *sc = serverCommandFactory::createCommand(capt.getType(), ss);
  sc->execute(gc);
  delete sc;
}
GameControllerProxy::GameControllerProxy(GameController &gc) : gc(gc) {}
