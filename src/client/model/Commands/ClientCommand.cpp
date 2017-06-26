#include "ClientCommand.h"

ClientCommand::ClientCommand(const CommandType &type) : type(type) {}

CommandType ClientCommand::getType() const {
  return type;
}
