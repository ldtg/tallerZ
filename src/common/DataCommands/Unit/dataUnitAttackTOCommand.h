#ifndef TALLERZ_DATAUNITATTACKTOCOMMAND_H
#define TALLERZ_DATAUNITATTACKTOCOMMAND_H

#include <common/IDs/UnitID.h>
#include <common/IDs/TerrainObjectID.h>
struct dataUnitAttackTOCommand {
  UnitID attacker;
  TerrainObjectID attacked;
  dataUnitAttackTOCommand(const UnitID &attacker,
                          const TerrainObjectID &attacked);
  dataUnitAttackTOCommand();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(attacker, attacked);
  }
};

#endif //TALLERZ_DATAUNITATTACKTOCOMMAND_H
