#ifndef TALLERZ_CLIENTUNITCAPTURECOMMAND_H
#define TALLERZ_CLIENTUNITCAPTURECOMMAND_H

#include <common/DataCommands/Unit/dataUnitCaptureCommand.h>
#include <client/model/Commands/ClientCommand.h>
class clientUnitCaptureCommand : public ClientCommand {
 private:
  dataUnitCaptureCommand data;
 public:
  clientUnitCaptureCommand(const UnitID &id, const CapturableID &cid);
  virtual std::stringstream getDataToSend();
};
#endif //TALLERZ_CLIENTUNITCAPTURECOMMAND_H
