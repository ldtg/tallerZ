#include "dataUnitCaptureCommand.h"
dataUnitCaptureCommand::dataUnitCaptureCommand(const UnitID &id,
                                               const CapturableID &cid)
    : id(id), cid(cid) {}
dataUnitCaptureCommand::dataUnitCaptureCommand() {}
