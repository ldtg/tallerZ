#ifndef TALLERZ_SERVERBLTNEWEVENT_H
#define TALLERZ_SERVERBLTNEWEVENT_H

#include <server/model/Events/ServerEvent.h>
#include <common/DataEvents/Bullet/DataBulletNewEvent.h>
class BulletNewEvent : public ServerEvent{
 private:
  DataBulletNewEvent data;
 public:
  BulletNewEvent(const BulletID &id,
                    WeaponType weapon,
                    const Position &from,
                    const Position &to);
  virtual std::stringstream getDataToSend() const;
};


#endif //TALLERZ_SERVERBLTNEWEVENT_H
