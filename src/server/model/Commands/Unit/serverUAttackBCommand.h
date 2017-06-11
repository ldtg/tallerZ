#ifndef TALLERZ_SERVERUATTACKBCOMMAND_H
#define TALLERZ_SERVERUATTACKBCOMMAND_H

#include <common/DataCommands/Unit/dataUnitAttackBuildCommand.h>
#include <server/model/Commands/serverCommand.h>
class serverUAttackBCommand : public serverCommand{
 private:
  dataUnitAttackBuildCommand data;
 public:
  serverUAttackBCommand(const dataUnitAttackBuildCommand & data);
  virtual void execute(serverGameController &gc);
};

#endif //TALLERZ_SERVERUATTACKBCOMMAND_H
