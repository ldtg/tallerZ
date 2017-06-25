#ifndef TALLERZ_SERVERUATTACKUCOMMAND_H
#define TALLERZ_SERVERUATTACKUCOMMAND_H

#include <common/DataCommands/Unit/DataUnitAttackUnitCommand.h>
#include <server/model/Commands/Command.h>
class UnitAttackUnitCommand : public Command{
 private:
  DataUnitAttackUnitCommand data;
 public:
  UnitAttackUnitCommand(const DataUnitAttackUnitCommand & data);
  virtual void execute(GameController &gc);
};
#endif //TALLERZ_SERVERUATTACKUCOMMAND_H
