#include "dataBuildUpdateEvent.h"
dataBuildUpdateEvent::dataBuildUpdateEvent(const BuildID &id,
                                           const BuildState &newState)
    : id(id), newState(newState) {}
