#ifndef TALLERZ_SERVERCOMMAND_H
#define TALLERZ_SERVERCOMMAND_H

#include <server/model/GameController.h>
class Command {
 public:
  virtual void execute(GameController &gameController) = 0;
};

#endif //TALLERZ_SERVERCOMMAND_H
