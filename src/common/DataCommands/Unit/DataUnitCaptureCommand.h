#ifndef TALLERZ_DATAUNITCAPTURECOMMAND_H
#define TALLERZ_DATAUNITCAPTURECOMMAND_H

#include <common/IDs/UnitID.h>
#include <common/IDs/CapturableID.h>
struct DataUnitCaptureCommand {
  UnitID id;
  CapturableID cid;
  DataUnitCaptureCommand(const UnitID &id, const CapturableID &cid);
  DataUnitCaptureCommand();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id, cid);
  }
};

#endif //TALLERZ_DATAUNITCAPTURECOMMAND_H
