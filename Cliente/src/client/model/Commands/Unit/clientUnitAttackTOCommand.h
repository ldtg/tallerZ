#ifndef TALLERZ_CLIENTUNITATTACKTOCOMMAND_H
#define TALLERZ_CLIENTUNITATTACKTOCOMMAND_H

#include <common/DataCommands/Unit/dataUnitAttackTOCommand.h>
#include <client/model/Commands/ClientCommand.h>
class clientUnitAttackTOCommand : public ClientCommand {
 private:
  dataUnitAttackTOCommand data;
 public:
  clientUnitAttackTOCommand(const UnitID &attacker, const TerrainObjectID &attacked);
  virtual std::stringstream getDataToSend();
};

#endif //TALLERZ_CLIENTUNITATTACKTOCOMMAND_H
