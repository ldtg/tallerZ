#include "serverUCaptureCommand.h"
serverUCaptureCommand::serverUCaptureCommand(const dataUnitCaptureCommand &data)
    : data(data) {}
void serverUCaptureCommand::execute(GameController &gc) {
  gc.capture(data.id, data.cid);
}
