#ifndef TALLERZ_SERVERCOMMANDFACTORY_H
#define TALLERZ_SERVERCOMMANDFACTORY_H

#include <common/Types/CommandType.h>
#include "Command.h"
class CommandFactory {
 public:
  static Command* createCommand(const CommandType &type, std::stringstream &ss);
};

#endif //TALLERZ_SERVERCOMMANDFACTORY_H
