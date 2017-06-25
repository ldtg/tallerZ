#include "DataBuildChangeUnitCommand.h"

DataBuildChangeUnitCommand::DataBuildChangeUnitCommand(const BuildID &id,
                                                       UnitType type)
    : id(id), type(type) {}

DataBuildChangeUnitCommand::DataBuildChangeUnitCommand() {}
