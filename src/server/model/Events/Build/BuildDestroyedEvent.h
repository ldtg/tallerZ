#ifndef TALLERZ_SERVERBDESTROYEDEVENT_H
#define TALLERZ_SERVERBDESTROYEDEVENT_H

#include <common/DataEvents/Build/DataBuildIDEvent.h>
#include <server/model/Events/ServerEvent.h>
class BuildDestroyedEvent : public ServerEvent{
 private:
  DataBuildIDEvent data;
 public:
  BuildDestroyedEvent(const BuildID &id);
  virtual std::stringstream getDataToSend() const;
};

#endif //TALLERZ_SERVERBDESTROYEDEVENT_H
