#ifndef TALLERZ_BULLETMOVEEVENT_H
#define TALLERZ_BULLETMOVEEVENT_H

#include <client/model/Events/Event.h>

class BulletMoveEvent  : public Event {
 private:
  BulletID id;
  Position posTo;

 public:
  BulletMoveEvent(const BulletID &id, const Position &to);
  virtual void process();
};

#endif //TALLERZ_BULLETMOVEEVENT_H
