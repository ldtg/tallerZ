#ifndef TALLERZ_SERVIDOR_SERVERBUPDATETIMEEVENT_H
#define TALLERZ_SERVIDOR_SERVERBUPDATETIMEEVENT_H

#include <common/DataEvents/Build/dataBuildIDEvent.h>
#include <server/model/Events/serverEvent.h>
#include <common/DataEvents/Build/dataBuildUpdateEvent.h>
class serverBUpdateTimeEvent : public serverEvent{
 private:
  dataBuildUpdateEvent data;
 public:
  serverBUpdateTimeEvent(const BuildID &id, const BuildState &state);
  virtual std::stringstream getDataToSend() const;
};

#endif //TALLERZ_SERVIDOR_SERVERBUPDATETIMEEVENT_H
