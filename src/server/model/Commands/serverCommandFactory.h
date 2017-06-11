#ifndef TALLERZ_SERVERCOMMANDFACTORY_H
#define TALLERZ_SERVERCOMMANDFACTORY_H

#include <common/DataCommands/CommandType.h>
#include "serverCommand.h"
class serverCommandFactory {
 public:
  static serverCommand *createCommand(const CommandType &type, std::stringstream &ss);
};

#endif //TALLERZ_SERVERCOMMANDFACTORY_H
