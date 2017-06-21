#ifndef TALLERZ_SERVERGPLAYERDEFEATEDEVENT_H
#define TALLERZ_SERVERGPLAYERDEFEATEDEVENT_H

#include <common/DataEvents/Game/DataPlayerDefeatEvent.h>
#include <server/model/Events/ServerEvent.h>
class GamePlayerDefeatedEvent : public ServerEvent{
 private:
  DataPlayerDefeatEvent data;
 public:
  GamePlayerDefeatedEvent(const PlayerID &playerid);
  virtual std::stringstream getDataToSend() const ;


};

#endif //TALLERZ_SERVERGPLAYERDEFEATEDEVENT_H
