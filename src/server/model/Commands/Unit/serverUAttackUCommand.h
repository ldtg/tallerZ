#ifndef TALLERZ_SERVERUATTACKUCOMMAND_H
#define TALLERZ_SERVERUATTACKUCOMMAND_H

#include <common/DataCommands/Unit/dataUnitAttackUnitCommand.h>
#include <server/model/Commands/serverCommand.h>
class serverUAttackUCommand : public serverCommand{
 private:
  dataUnitAttackUnitCommand data;
 public:
  serverUAttackUCommand(const dataUnitAttackUnitCommand & data);
  virtual void execute(GameController &gc);
};
#endif //TALLERZ_SERVERUATTACKUCOMMAND_H
