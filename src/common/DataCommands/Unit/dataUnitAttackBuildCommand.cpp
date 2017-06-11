#include "dataUnitAttackBuildCommand.h"

dataUnitAttackBuildCommand::dataUnitAttackBuildCommand(const UnitID &attacker,
                                                       const BuildID &attacked)
    : attacker(attacker), attacked(attacked) {}

dataUnitAttackBuildCommand::dataUnitAttackBuildCommand() {}
