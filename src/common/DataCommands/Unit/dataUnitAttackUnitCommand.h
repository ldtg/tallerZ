#ifndef TALLERZ_DATAUNITATTACKUNITCOMMAND_H
#define TALLERZ_DATAUNITATTACKUNITCOMMAND_H

#include <common/IDs/UnitID.h>
struct dataUnitAttackUnitCommand {
  UnitID attacker;
  UnitID attacked;
  dataUnitAttackUnitCommand(const UnitID &attacker, const UnitID &attacked);
  dataUnitAttackUnitCommand();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(attacker, attacked);
  }
};

#endif //TALLERZ_DATAUNITATTACKUNITCOMMAND_H
