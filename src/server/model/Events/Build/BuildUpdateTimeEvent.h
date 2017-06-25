#ifndef TALLERZ_SERVIDOR_SERVERBUPDATETIMEEVENT_H
#define TALLERZ_SERVIDOR_SERVERBUPDATETIMEEVENT_H

#include <common/DataEvents/Build/DataBuildIDEvent.h>
#include <server/model/Events/ServerEvent.h>
#include <common/DataEvents/Build/DataBuildUpdateEvent.h>
class BuildUpdateTimeEvent : public ServerEvent{
 private:
  DataBuildUpdateEvent data;
 public:
  BuildUpdateTimeEvent(const BuildID &id, const BuildState &state);
  virtual std::stringstream getDataToSend() const;
};

#endif //TALLERZ_SERVIDOR_SERVERBUPDATETIMEEVENT_H
