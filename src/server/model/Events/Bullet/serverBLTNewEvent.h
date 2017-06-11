#ifndef TALLERZ_SERVERBLTNEWEVENT_H
#define TALLERZ_SERVERBLTNEWEVENT_H

#include <server/model/Events/serverEvent.h>
#include <common/DataEvents/Bullet/dataBulletNewEvent.h>
class serverBLTNewEvent : public serverEvent{
 private:
  dataBulletNewEvent data;
 public:
  serverBLTNewEvent(const BulletID &id,
                    WeaponType weapon,
                    const Position &from,
                    const Position &to);
  virtual std::stringstream getDataToSend() const;
};


#endif //TALLERZ_SERVERBLTNEWEVENT_H
