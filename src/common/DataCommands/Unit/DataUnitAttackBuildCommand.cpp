#include "DataUnitAttackBuildCommand.h"

DataUnitAttackBuildCommand::DataUnitAttackBuildCommand(const UnitID &attacker,
                                                       const BuildID &attacked)
    : attacker(attacker), attacked(attacked) {}

DataUnitAttackBuildCommand::DataUnitAttackBuildCommand() {}
