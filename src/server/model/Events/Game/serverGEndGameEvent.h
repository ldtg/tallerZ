#ifndef TALLERZ_SERVERGENDGAMEEVENT_H
#define TALLERZ_SERVERGENDGAMEEVENT_H

#include <server/model/Events/serverEvent.h>
#include <common/DataEvents/Game/dataEndGameEvent.h>
class serverGEndGameEvent : public serverEvent{
 private:
  dataEndGameEvent data;
 public:
  serverGEndGameEvent(const TeamID &winner);
  virtual std::stringstream getDataToSend() const;
};

#endif //TALLERZ_SERVERGENDGAMEEVENT_H
