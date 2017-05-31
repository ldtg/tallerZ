#ifndef TALLERZ_BUILDDESTROYEDEVENT_H
#define TALLERZ_BUILDDESTROYEDEVENT_H

#include <model/BuildID.h>
#include <model/Events/Event.h>
class BuildDestroyedEvent : public Event{
 private:
  BuildID id;
 public:
  BuildDestroyedEvent(const BuildID &id);
  virtual void process();
};

#endif //TALLERZ_BUILDDESTROYEDEVENT_H
