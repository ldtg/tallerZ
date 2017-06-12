#include "clientCommand.h"
clientCommand::clientCommand(const CommandType &type) : type(type) {}
CommandType clientCommand::getType() const {
  return type;
}
