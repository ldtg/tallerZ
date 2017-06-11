#include "serverUAttackUCommand.h"
serverUAttackUCommand::serverUAttackUCommand(const dataUnitAttackUnitCommand &data)
    : data(data) {}
void serverUAttackUCommand::execute(serverGameController &gc) {
  gc.attack(data.attacker, data.attacked);
}
