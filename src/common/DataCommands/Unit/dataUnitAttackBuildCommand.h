#ifndef TALLERZ_DATAUNITATTACKBUILDCOMMAND_H
#define TALLERZ_DATAUNITATTACKBUILDCOMMAND_H

#include <common/IDs/UnitID.h>
#include <common/IDs/BuildID.h>
struct dataUnitAttackBuildCommand {
  UnitID attacker;
  BuildID attacked;
  dataUnitAttackBuildCommand(const UnitID &attacker, const BuildID &attacked);
  dataUnitAttackBuildCommand();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(attacker, attacked);
  }
};

#endif //TALLERZ_DATAUNITATTACKBUILDCOMMAND_H
