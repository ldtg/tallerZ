#include "BuildChangeUnitCommand.h"
BuildChangeUnitCommand::BuildChangeUnitCommand(const DataBuildChangeUnitCommand &data)
    : data(data) {

}
void BuildChangeUnitCommand::execute(GameController &gc) {
  gc.changeUnitFab(data.id, data.type);
}
