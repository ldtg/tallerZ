#ifndef TALLERZ_SERVERBLTMOVEEVENT_H
#define TALLERZ_SERVERBLTMOVEEVENT_H

#include <common/DataEvents/Bullet/dataBulletMoveEvent.h>
#include <server/model/Events/serverEvent.h>
class serverBLTMoveEvent : public serverEvent{
 private:
  dataBulletMoveEvent data;
 public:
  serverBLTMoveEvent(const BulletID &id, const Position &posTo);
  virtual std::stringstream getDataToSend() const;
};

#endif //TALLERZ_SERVERBLTMOVEEVENT_H
