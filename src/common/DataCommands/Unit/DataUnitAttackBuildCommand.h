#ifndef TALLERZ_DATAUNITATTACKBUILDCOMMAND_H
#define TALLERZ_DATAUNITATTACKBUILDCOMMAND_H

#include <common/IDs/UnitID.h>
#include <common/IDs/BuildID.h>
struct DataUnitAttackBuildCommand {
  UnitID attacker;
  BuildID attacked;
  DataUnitAttackBuildCommand(const UnitID &attacker, const BuildID &attacked);
  DataUnitAttackBuildCommand();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(attacker, attacked);
  }
};

#endif //TALLERZ_DATAUNITATTACKBUILDCOMMAND_H
