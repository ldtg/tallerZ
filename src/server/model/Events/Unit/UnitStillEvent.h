#ifndef TALLERZ_SERVERUSTILLEVENT_H
#define TALLERZ_SERVERUSTILLEVENT_H

#include <server/model/Events/ServerEvent.h>
#include <common/DataEvents/Unit/DataUnitIDEvent.h>
#include <common/DataEvents/Unit/DataUnitStillEvent.h>
class UnitStillEvent: public ServerEvent{
 private:
  DataUnitStillEvent data;
 public:
  UnitStillEvent(const UnitID &id, const Position &pos);
  virtual std::stringstream getDataToSend() const;
};

#endif //TALLERZ_SERVERUSTILLEVENT_H
