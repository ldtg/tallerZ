#ifndef TALLERZ_SERVERUSTILLEVENT_H
#define TALLERZ_SERVERUSTILLEVENT_H

#include <server/model/Events/serverEvent.h>
#include <common/DataEvents/Unit/dataUnitIDEvent.h>
#include <common/DataEvents/Unit/dataUnitStillEvent.h>
class serverUStillEvent: public serverEvent{
 private:
  dataUnitStillEvent data;
 public:
  serverUStillEvent(const UnitID &id, const Position &pos);
  virtual std::stringstream getDataToSend() const;
};

#endif //TALLERZ_SERVERUSTILLEVENT_H
