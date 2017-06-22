#include "DataUnitMoveCommand.h"
DataUnitMoveCommand::DataUnitMoveCommand(const UnitID &id, const Position &pos)
    : id(id), pos(pos) {}
DataUnitMoveCommand::DataUnitMoveCommand() {}
