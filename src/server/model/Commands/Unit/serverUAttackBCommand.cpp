#include "serverUAttackBCommand.h"
serverUAttackBCommand::serverUAttackBCommand(const dataUnitAttackBuildCommand &data)
    : data(data) {}
void serverUAttackBCommand::execute(serverGameController &gc) {
  gc.attack(data.attacker, data.attacked);
}
