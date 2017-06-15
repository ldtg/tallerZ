#include "BuildUpdateEvent.h"
BuildUpdateEvent::BuildUpdateEvent(const BuildID &id, const BuildState &state)
    : id(id), newState(state) {
}
void BuildUpdateEvent::process() {
  model->getMap().updateBuild(id, newState);
}