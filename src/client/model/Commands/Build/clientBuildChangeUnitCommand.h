#ifndef TALLERZ_CLIENTBUILDCHANGEUNITCOMMAND_H
#define TALLERZ_CLIENTBUILDCHANGEUNITCOMMAND_H

#include <common/DataCommands/Build/dataBuildChangeUnitCommand.h>
#include <client/model/Commands/clientCommand.h>
class clientBuildChangeUnitCommand : public clientCommand {
 private:
  dataBuildChangeUnitCommand data;
 public:
  clientBuildChangeUnitCommand(const BuildID &id, const UnitType &type);
  virtual std::stringstream getDataToSend();
};
#endif //TALLERZ_CLIENTBUILDCHANGEUNITCOMMAND_H
