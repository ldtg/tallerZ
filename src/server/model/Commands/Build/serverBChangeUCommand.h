#ifndef TALLERZ_SERVERBCHANGEUCOMMAND_H
#define TALLERZ_SERVERBCHANGEUCOMMAND_H

#include <common/DataCommands/Build/dataBuildChangeUnitCommand.h>
#include <server/model/Commands/serverCommand.h>
class serverBChangeUCommand : public serverCommand{
 private:
  dataBuildChangeUnitCommand data;
 public:
  serverBChangeUCommand(const dataBuildChangeUnitCommand & data);
  virtual void execute(serverGameController &gc);
};

#endif //TALLERZ_SERVERBCHANGEUCOMMAND_H
