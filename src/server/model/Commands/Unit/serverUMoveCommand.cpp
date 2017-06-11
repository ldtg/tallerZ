#include "serverUMoveCommand.h"
serverUMoveCommand::serverUMoveCommand(const dataUnitMoveCommand &data)
    : data(data) {}
void serverUMoveCommand::execute(serverGameController &gc) {
  gc.move(data.id, data.pos);
}
