#ifndef TALLERZ_BUILDDESTROYEDEVENT_H
#define TALLERZ_BUILDDESTROYEDEVENT_H

#include <common/IDs/BuildID.h>
#include <client/model/Events/Event.h>
class BuildDestroyedEvent : public Event{
 private:
  BuildID id;
 public:
  BuildDestroyedEvent(const BuildID &id);
  virtual void process();
};

#endif //TALLERZ_BUILDDESTROYEDEVENT_H
