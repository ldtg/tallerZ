#include "serverUMoveCommand.h"
serverUMoveCommand::serverUMoveCommand(const dataUnitMoveCommand &data)
    : data(data) {}
void serverUMoveCommand::execute(GameController &gc) {
  gc.move(data.id, data.pos);
}
