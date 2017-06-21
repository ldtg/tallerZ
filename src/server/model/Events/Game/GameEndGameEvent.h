#ifndef TALLERZ_SERVERGENDGAMEEVENT_H
#define TALLERZ_SERVERGENDGAMEEVENT_H

#include <server/model/Events/ServerEvent.h>
#include <common/DataEvents/Game/DataEndGameEvent.h>
class GameEndGameEvent : public ServerEvent{
 private:
  DataEndGameEvent data;
 public:
  GameEndGameEvent(const TeamID &winner);
  virtual std::stringstream getDataToSend() const;
};

#endif //TALLERZ_SERVERGENDGAMEEVENT_H
