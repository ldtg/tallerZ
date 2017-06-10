#ifndef TALLERZ_SERVERUMOVECOMMAND_H
#define TALLERZ_SERVERUMOVECOMMAND_H

#include <server/model/Commands/serverCommand.h>
#include <common/DataCommands/Unit/dataUnitMoveCommand.h>
class serverUMoveCommand : public serverCommand{
 private:
  dataUnitMoveCommand data;
 public:
  serverUMoveCommand(const dataUnitMoveCommand & data);
  virtual void execute(serverGameController &gc);
};

#endif //TALLERZ_SERVERUMOVECOMMAND_H
