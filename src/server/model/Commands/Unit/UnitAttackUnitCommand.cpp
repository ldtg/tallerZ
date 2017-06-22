#include "UnitAttackUnitCommand.h"
UnitAttackUnitCommand::UnitAttackUnitCommand(const DataUnitAttackUnitCommand &data)
    : data(data) {}
void UnitAttackUnitCommand::execute(GameController &gc) {
  gc.attack(data.attacker, data.attacked);
}
