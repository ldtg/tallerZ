#ifndef TALLERZ_SERVERUDEATHEVENT_H
#define TALLERZ_SERVERUDEATHEVENT_H
#include <server/model/Events/ServerEvent.h>
#include <common/DataEvents/Unit/DataUnitIDEvent.h>
#include <common/States/UnitState.h>
class UnitDeathEvent: public ServerEvent{
 private:
  DataUnitIDEvent data;
 public:
  UnitDeathEvent(const UnitID &id);
  virtual std::stringstream getDataToSend() const;
};

#endif //TALLERZ_SERVERUDEATHEVENT_H
