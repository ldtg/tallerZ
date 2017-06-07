#ifndef TALLERZ_ENEMYDEFEATEDEVENT_H
#define TALLERZ_ENEMYDEFEATEDEVENT_H

#include <client/model/Events/Event.h>
class PlayerDefeatedEvent : public Event{
 private:
  PlayerID playerID;
 public:
  explicit PlayerDefeatedEvent(const PlayerID &playerid);
  virtual void process() override;
};

#endif //TALLERZ_ENEMYDEFEATEDEVENT_H
