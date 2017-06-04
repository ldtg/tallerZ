#ifndef TALLERZ_BUILDDAMAGEEVENT_H
#define TALLERZ_BUILDDAMAGEEVENT_H

#include <Events/Event.h>
#include "BuildID.h"
#include "BuildState.h"
class BuildDamageEvent : public Event{
 private:
  BuildID id;
  BuildState newState;
 public:
  BuildDamageEvent(const BuildID &id, const BuildState &state);
  virtual void process();
};

#endif //TALLERZ_BUILDDAMAGEEVENT_H
