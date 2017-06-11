#include "serverUCaptureCommand.h"
serverUCaptureCommand::serverUCaptureCommand(const dataUnitCaptureCommand &data)
    : data(data) {}
void serverUCaptureCommand::execute(serverGameController &gc) {
  gc.capture(data.id, data.cid);
}
