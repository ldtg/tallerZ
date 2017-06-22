#include "DataUnitAttackTOCommand.h"
DataUnitAttackTOCommand::DataUnitAttackTOCommand(const UnitID &attacker,
                                                 const TerrainObjectID &attacked)
    : attacker(attacker), attacked(attacked) {}
DataUnitAttackTOCommand::DataUnitAttackTOCommand() {}
