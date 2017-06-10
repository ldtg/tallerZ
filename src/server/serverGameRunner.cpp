#include "serverGameRunner.h"
serverGameRunner::serverGameRunner(protectedGameController &gameController)
    : gameController(gameController), open(true) {}
void serverGameRunner::run() {
  while (open) {
    gameController.tick();
  }
}
void serverGameRunner::stop() {
  open = false;
}
bool serverGameRunner::isOpen() const {
  return open;
}
