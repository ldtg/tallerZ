#ifndef TALLERZ_DATAUNITATTACKUNITCOMMAND_H
#define TALLERZ_DATAUNITATTACKUNITCOMMAND_H

#include <common/IDs/UnitID.h>
struct DataUnitAttackUnitCommand {
  UnitID attacker;
  UnitID attacked;
  DataUnitAttackUnitCommand(const UnitID &attacker, const UnitID &attacked);
  DataUnitAttackUnitCommand();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(attacker, attacked);
  }
};

#endif //TALLERZ_DATAUNITATTACKUNITCOMMAND_H
