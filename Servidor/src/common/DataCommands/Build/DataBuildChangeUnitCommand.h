#ifndef TALLERZ_DATABUILDCHANGEUNITCOMMAND_H
#define TALLERZ_DATABUILDCHANGEUNITCOMMAND_H

#include <common/Types/UnitType.h>
#include <common/IDs/BuildID.h>
struct DataBuildChangeUnitCommand {
  BuildID id;
  UnitType type;
  DataBuildChangeUnitCommand(const BuildID &id, UnitType type);
  DataBuildChangeUnitCommand();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id, type);
  }
};

#endif //TALLERZ_DATABUILDCHANGEUNITCOMMAND_H
