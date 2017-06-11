#ifndef TALLERZ_DATABUILDCHANGEUNITCOMMAND_H
#define TALLERZ_DATABUILDCHANGEUNITCOMMAND_H

#include <common/Types/UnitType.h>
#include <common/IDs/BuildID.h>
struct dataBuildChangeUnitCommand {
  BuildID id;
  UnitType type;
  dataBuildChangeUnitCommand(const BuildID &id, UnitType type);
  dataBuildChangeUnitCommand();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id, type);
  }
};

#endif //TALLERZ_DATABUILDCHANGEUNITCOMMAND_H
