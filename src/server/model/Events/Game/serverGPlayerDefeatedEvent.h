#ifndef TALLERZ_SERVERGPLAYERDEFEATEDEVENT_H
#define TALLERZ_SERVERGPLAYERDEFEATEDEVENT_H

#include <common/DataEvents/Game/dataPlayerDefeatEvent.h>
#include <server/model/Events/serverEvent.h>
class serverGPlayerDefeatedEvent : public serverEvent{
 private:
  dataPlayerDefeatEvent data;
 public:
  serverGPlayerDefeatedEvent(const PlayerID &playerid);
  virtual std::stringstream getDataToSend() const ;


};

#endif //TALLERZ_SERVERGPLAYERDEFEATEDEVENT_H
