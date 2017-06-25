#ifndef TALLERZ_SERVERUATTACKBCOMMAND_H
#define TALLERZ_SERVERUATTACKBCOMMAND_H

#include <common/DataCommands/Unit/DataUnitAttackBuildCommand.h>
#include <server/model/Commands/Command.h>
class UnitAttackBuildCommand : public Command{
 private:
  DataUnitAttackBuildCommand data;
 public:
  UnitAttackBuildCommand(const DataUnitAttackBuildCommand & data);
  virtual void execute(GameController &gc);
};

#endif //TALLERZ_SERVERUATTACKBCOMMAND_H
