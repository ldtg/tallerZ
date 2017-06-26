#ifndef TALLERZ_CLIENTUNITATTACKUNITCOMMAND_H
#define TALLERZ_CLIENTUNITATTACKUNITCOMMAND_H

#include <common/DataCommands/Unit/dataUnitAttackUnitCommand.h>
#include <client/model/Commands/ClientCommand.h>
class clientUnitAttackUnitCommand : public ClientCommand {
 private:
  dataUnitAttackUnitCommand data;
 public:
  clientUnitAttackUnitCommand(const UnitID &attacker, const UnitID &attacked);
  virtual std::stringstream getDataToSend();
};

#endif //TALLERZ_CLIENTUNITATTACKUNITCOMMAND_H
