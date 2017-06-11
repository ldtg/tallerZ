#ifndef TALLERZ_SERVERUCAPTURECOMMAND_H
#define TALLERZ_SERVERUCAPTURECOMMAND_H

#include <common/DataCommands/Unit/dataUnitCaptureCommand.h>
#include <server/model/Commands/serverCommand.h>
class serverUCaptureCommand : public serverCommand{
 private:
  dataUnitCaptureCommand data;
 public:
  serverUCaptureCommand(const dataUnitCaptureCommand & data);
  virtual void execute(GameController &gc);
};

#endif //TALLERZ_SERVERUCAPTURECOMMAND_H
