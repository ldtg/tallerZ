#ifndef TALLERZ_DATAUNITATTACKTOCOMMAND_H
#define TALLERZ_DATAUNITATTACKTOCOMMAND_H

#include <common/IDs/UnitID.h>
#include <common/IDs/TerrainObjectID.h>
struct DataUnitAttackTOCommand {
  UnitID attacker;
  TerrainObjectID attacked;
  DataUnitAttackTOCommand(const UnitID &attacker,
                          const TerrainObjectID &attacked);
  DataUnitAttackTOCommand();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(attacker, attacked);
  }
};

#endif //TALLERZ_DATAUNITATTACKTOCOMMAND_H
