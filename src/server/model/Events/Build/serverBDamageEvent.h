#ifndef TALLERZ_SERVERBDAMAGEEVENT_H
#define TALLERZ_SERVERBDAMAGEEVENT_H

#include <common/DataEvents/Build/dataBuildUpdateEvent.h>
#include <server/model/Events/serverEvent.h>
class serverBDamageEvent : public serverEvent{
 private:
  dataBuildUpdateEvent data;
 public:
  serverBDamageEvent(const BuildID &id, const BuildState &newState);
  virtual std::stringstream getDataToSend() const;
};
#endif //TALLERZ_SERVERBDAMAGEEVENT_H
