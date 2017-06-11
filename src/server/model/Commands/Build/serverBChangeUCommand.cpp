#include "serverBChangeUCommand.h"
serverBChangeUCommand::serverBChangeUCommand(const dataBuildChangeUnitCommand &data)
    : data(data) {

}
void serverBChangeUCommand::execute(serverGameController &gc) {
  gc.changeUnitFab(data.id, data.type);
}
