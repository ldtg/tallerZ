#ifndef TALLERZ_SERVERUATTACKTOCOMMAND_H
#define TALLERZ_SERVERUATTACKTOCOMMAND_H

#include <common/DataCommands/Unit/dataUnitAttackTOCommand.h>
#include <server/model/Commands/serverCommand.h>
class serverUAttackTOCommand : public serverCommand{
 private:
  dataUnitAttackTOCommand data;
 public:
  serverUAttackTOCommand(const dataUnitAttackTOCommand & data);
  virtual void execute(GameController &gc);
};

#endif //TALLERZ_SERVERUATTACKTOCOMMAND_H
