#include "dataUnitAttackUnitCommand.h"
dataUnitAttackUnitCommand::dataUnitAttackUnitCommand(const UnitID &attacker,
                                                     const UnitID &attacked)
    : attacker(attacker), attacked(attacked) {}
dataUnitAttackUnitCommand::dataUnitAttackUnitCommand() {}
