#ifndef TALLERZ_CLIENTCOMMAND_H
#define TALLERZ_CLIENTCOMMAND_H

#include <common/DataCommands/CommandType.h>
#include <iosfwd>
class clientCommand {
 protected:
  CommandType type;
  clientCommand(const CommandType &type);
 public:
  virtual std::stringstream getDataToSend() = 0;
  CommandType getType() const;
};

#endif //TALLERZ_CLIENTCOMMAND_H
