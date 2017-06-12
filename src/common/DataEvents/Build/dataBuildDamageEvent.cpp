#include "dataBuildDamageEvent.h"
dataBuildDamageEvent::dataBuildDamageEvent(const BuildID &id,
                                           const BuildState &newState)
    : id(id), newState(newState) {}
