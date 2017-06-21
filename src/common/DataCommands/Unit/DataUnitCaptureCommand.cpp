#include "DataUnitCaptureCommand.h"
DataUnitCaptureCommand::DataUnitCaptureCommand(const UnitID &id,
                                               const CapturableID &cid)
    : id(id), cid(cid) {}
DataUnitCaptureCommand::DataUnitCaptureCommand() {}
