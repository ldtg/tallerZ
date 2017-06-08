#include "dataUnitAttackTOCommand.h"
dataUnitAttackTOCommand::dataUnitAttackTOCommand(const UnitID &attacker,
                                                 const TerrainObjectID &attacked)
    : attacker(attacker), attacked(attacked) {}
dataUnitAttackTOCommand::dataUnitAttackTOCommand() {}
