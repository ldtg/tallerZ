#ifndef TALLERZ_SERVERBDAMAGEEVENT_H
#define TALLERZ_SERVERBDAMAGEEVENT_H

#include <common/DataEvents/Build/DataBuildUpdateEvent.h>
#include <server/model/Events/ServerEvent.h>
class BuildDamageEvent : public ServerEvent{
 private:
  DataBuildUpdateEvent data;
 public:
  BuildDamageEvent(const BuildID &id, const BuildState &newState);
  virtual std::stringstream getDataToSend() const;
};
#endif //TALLERZ_SERVERBDAMAGEEVENT_H
