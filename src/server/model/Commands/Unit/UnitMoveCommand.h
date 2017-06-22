#ifndef TALLERZ_SERVERUMOVECOMMAND_H
#define TALLERZ_SERVERUMOVECOMMAND_H

#include <server/model/Commands/Command.h>
#include <common/DataCommands/Unit/DataUnitMoveCommand.h>
class UnitMoveCommand : public Command{
 private:
  DataUnitMoveCommand data;
 public:
  UnitMoveCommand(const DataUnitMoveCommand & data);
  virtual void execute(GameController &gc);
};

#endif //TALLERZ_SERVERUMOVECOMMAND_H
