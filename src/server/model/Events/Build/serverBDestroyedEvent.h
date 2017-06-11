#ifndef TALLERZ_SERVERBDESTROYEDEVENT_H
#define TALLERZ_SERVERBDESTROYEDEVENT_H

#include <common/DataEvents/Build/dataBuildIDEvent.h>
#include <server/model/Events/serverEvent.h>
class serverBDestroyedEvent : public serverEvent{
 private:
  dataBuildIDEvent data;
 public:
  serverBDestroyedEvent(const BuildID &id);
  virtual std::stringstream getDataToSend() const;
};

#endif //TALLERZ_SERVERBDESTROYEDEVENT_H
