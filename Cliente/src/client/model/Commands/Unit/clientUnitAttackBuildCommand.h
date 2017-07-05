#ifndef TALLERZ_CLIENTUNITATTACKBUILDCOMMAND_H
#define TALLERZ_CLIENTUNITATTACKBUILDCOMMAND_H

#include <common/DataCommands/Unit/dataUnitAttackBuildCommand.h>
#include <client/model/Commands/ClientCommand.h>
class clientUnitAttackBuildCommand : public ClientCommand {
 private:
  dataUnitAttackBuildCommand data;
 public:
  clientUnitAttackBuildCommand(const UnitID &attacker, const BuildID &attacked);
  virtual std::stringstream getDataToSend();
};

#endif //TALLERZ_CLIENTUNITATTACKBUILDCOMMAND_H
