#include "UnitMoveCommand.h"
UnitMoveCommand::UnitMoveCommand(const DataUnitMoveCommand &data)
    : data(data) {}
void UnitMoveCommand::execute(GameController &gc) {
  gc.move(data.id, data.pos);
}
