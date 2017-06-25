#include "DataBuildUpdateEvent.h"
DataBuildUpdateEvent::DataBuildUpdateEvent(const BuildID &id,
                                           const BuildState &newState)
    : id(id), newState(newState) {}
