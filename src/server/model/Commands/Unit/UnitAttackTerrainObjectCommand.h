#ifndef TALLERZ_SERVERUATTACKTOCOMMAND_H
#define TALLERZ_SERVERUATTACKTOCOMMAND_H

#include <common/DataCommands/Unit/DataUnitAttackTOCommand.h>
#include <server/model/Commands/Command.h>
class UnitAttackTerrainObjectCommand : public Command{
 private:
  DataUnitAttackTOCommand data;
 public:
  UnitAttackTerrainObjectCommand(const DataUnitAttackTOCommand & data);
  virtual void execute(GameController &gc);
};

#endif //TALLERZ_SERVERUATTACKTOCOMMAND_H
