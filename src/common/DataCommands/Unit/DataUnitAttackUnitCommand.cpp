#include "DataUnitAttackUnitCommand.h"
DataUnitAttackUnitCommand::DataUnitAttackUnitCommand(const UnitID &attacker,
                                                     const UnitID &attacked)
    : attacker(attacker), attacked(attacked) {}
DataUnitAttackUnitCommand::DataUnitAttackUnitCommand() {}
