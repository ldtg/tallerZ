#ifndef TALLERZ_SERVERBLTHITEVENT_H
#define TALLERZ_SERVERBLTHITEVENT_H

#include <common/DataEvents/Bullet/DataBulletHitEvent.h>
#include <server/model/Events/ServerEvent.h>
class BulletHitEvent : public ServerEvent{
 private:
  DataBulletHitEvent data;
 public:
  BulletHitEvent(const BulletID &id,
                    const Position &pos,
                    WeaponType weapon);
  virtual std::stringstream getDataToSend() const;
};
#endif //TALLERZ_SERVERBLTHITEVENT_H
