#ifndef TALLERZ_DATAUNITCAPTURECOMMAND_H
#define TALLERZ_DATAUNITCAPTURECOMMAND_H

#include <common/IDs/UnitID.h>
#include <common/IDs/CapturableID.h>
struct dataUnitCaptureCommand {
  UnitID id;
  CapturableID cid;
  dataUnitCaptureCommand(const UnitID &id, const CapturableID &cid);
  dataUnitCaptureCommand();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id, cid);
  }
};

#endif //TALLERZ_DATAUNITCAPTURECOMMAND_H
