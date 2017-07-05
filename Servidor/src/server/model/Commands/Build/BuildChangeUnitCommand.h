#ifndef TALLERZ_SERVERBCHANGEUCOMMAND_H
#define TALLERZ_SERVERBCHANGEUCOMMAND_H

#include <common/DataCommands/Build/DataBuildChangeUnitCommand.h>
#include <server/model/Commands/Command.h>
class BuildChangeUnitCommand : public Command{
 private:
  DataBuildChangeUnitCommand data;
 public:
  BuildChangeUnitCommand(const DataBuildChangeUnitCommand & data);
  virtual void execute(GameController &gc);
};

#endif //TALLERZ_SERVERBCHANGEUCOMMAND_H
