#ifndef TALLERZ_SERVERBLTHITEVENT_H
#define TALLERZ_SERVERBLTHITEVENT_H

#include <common/DataEvents/Bullet/dataBulletHitEvent.h>
#include <server/model/Events/serverEvent.h>
class serverBLTHitEvent : public serverEvent{
 private:
  dataBulletHitEvent data;
 public:
  serverBLTHitEvent(const BulletID &id,
                    const Position &pos,
                    WeaponType weapon);
  virtual std::stringstream getDataToSend() const;
};
#endif //TALLERZ_SERVERBLTHITEVENT_H
