#ifndef TALLERZ_CLIENTUNITMOVECOMMAND_H
#define TALLERZ_CLIENTUNITMOVECOMMAND_H

#include <client/model/Commands/ClientCommand.h>
#include <common/DataCommands/Unit/dataUnitMoveCommand.h>
class clientUnitMoveCommand : public ClientCommand{
 private:
  dataUnitMoveCommand data;
 public:
  clientUnitMoveCommand(const UnitID &id, const Position &pos);
  virtual std::stringstream getDataToSend();
};

#endif //TALLERZ_CLIENTUNITMOVECOMMAND_H
