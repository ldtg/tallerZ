#include "UnitCaptureCommand.h"
UnitCaptureCommand::UnitCaptureCommand(const DataUnitCaptureCommand &data)
    : data(data) {}
void UnitCaptureCommand::execute(GameController &gc) {
  gc.capture(data.id, data.cid);
}
