#ifndef TALLERZ_SERVERCOMMAND_H
#define TALLERZ_SERVERCOMMAND_H

#include <server/serverGameController.h>
class serverCommand {
 public:
  virtual void execute(serverGameController &gameController) = 0;
};

#endif //TALLERZ_SERVERCOMMAND_H
