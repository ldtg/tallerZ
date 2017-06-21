#ifndef TALLERZ_SERVERUCAPTURECOMMAND_H
#define TALLERZ_SERVERUCAPTURECOMMAND_H

#include <common/DataCommands/Unit/DataUnitCaptureCommand.h>
#include <server/model/Commands/Command.h>
class UnitCaptureCommand : public Command{
 private:
  DataUnitCaptureCommand data;
 public:
  UnitCaptureCommand(const DataUnitCaptureCommand & data);
  virtual void execute(GameController &gc);
};

#endif //TALLERZ_SERVERUCAPTURECOMMAND_H
