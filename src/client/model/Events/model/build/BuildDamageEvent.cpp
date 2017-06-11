#include "BuildDamageEvent.h"
BuildDamageEvent::BuildDamageEvent(const BuildID &id, const BuildState &state)
    : id(id), newState(state) {
}
void BuildDamageEvent::process() {
}
