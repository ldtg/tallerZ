#include "UnitAttackBuildCommand.h"
UnitAttackBuildCommand::UnitAttackBuildCommand(const DataUnitAttackBuildCommand &data)
    : data(data) {}
void UnitAttackBuildCommand::execute(GameController &gc) {
  gc.attack(data.attacker, data.attacked);
}
