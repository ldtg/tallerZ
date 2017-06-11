#ifndef TALLERZ_SERVERUDEATHEVENT_H
#define TALLERZ_SERVERUDEATHEVENT_H
#include <server/model/Events/serverEvent.h>
#include <common/DataEvents/Unit/dataUnitIDEvent.h>
#include <common/States/UnitState.h>
class serverUDeathEvent: public serverEvent{
 private:
  dataUnitIDEvent data;
 public:
  serverUDeathEvent(const UnitID &id);
  virtual std::stringstream getDataToSend() const;
};

#endif //TALLERZ_SERVERUDEATHEVENT_H
