#ifndef TALLERZ_ENDGAMEEVENT_H
#define TALLERZ_ENDGAMEEVENT_H

#include <client/model/Events/Event.h>
class EndGameEvent : public Event{
 private:
  TeamID winner;
 public:
  explicit EndGameEvent(const TeamID &winner);
  virtual void process() override;
};

#endif //TALLERZ_ENDGAMEEVENT_H
