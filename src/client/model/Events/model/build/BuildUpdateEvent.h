#ifndef TALLERZ_CLIENTE_BUILDUPDATEEVENT_H
#define TALLERZ_CLIENTE_BUILDUPDATEEVENT_H

#include <common/IDs/BuildID.h>
#include <common/States/BuildState.h>
#include <client/model/Events/Event.h>
class BuildUpdateEvent : public Event {
 private:
  BuildID id;
  BuildState newState;
 public:
  BuildUpdateEvent(const BuildID &id, const BuildState &state);
  virtual void process();
};

#endif //TALLERZ_CLIENTE_BUILDUPDATEEVENT_H
