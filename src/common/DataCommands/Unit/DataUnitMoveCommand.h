#ifndef TALLERZ_DATAUNITMOVECOMMAND_H
#define TALLERZ_DATAUNITMOVECOMMAND_H

#include <common/IDs/UnitID.h>
#include <common/Map/Position.h>
struct DataUnitMoveCommand {
  UnitID id;
  Position pos;
  DataUnitMoveCommand(const UnitID &id, const Position &pos);
  DataUnitMoveCommand();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id, pos);
  }
};

#endif //TALLERZ_DATAUNITMOVECOMMAND_H
