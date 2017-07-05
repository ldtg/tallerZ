#ifndef TALLERZ_SERVERBLTMOVEEVENT_H
#define TALLERZ_SERVERBLTMOVEEVENT_H

#include <common/DataEvents/Bullet/DataBulletMoveEvent.h>
#include <server/model/Events/ServerEvent.h>
class BulletMoveEvent : public ServerEvent{
 private:
  DataBulletMoveEvent data;
 public:
  BulletMoveEvent(const BulletID &id, const Position &posTo);
  virtual std::stringstream getDataToSend() const;
};

#endif //TALLERZ_SERVERBLTMOVEEVENT_H
