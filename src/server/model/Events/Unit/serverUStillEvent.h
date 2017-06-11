#ifndef TALLERZ_SERVERUSTILLEVENT_H
#define TALLERZ_SERVERUSTILLEVENT_H

#include <server/model/Events/serverEvent.h>
#include <common/DataEvents/Unit/dataUnitIDEvent.h>
class serverUStillEvent: public serverEvent{
 private:
  dataUnitIDEvent data;
 public:
  serverUStillEvent(const UnitID &id);
  virtual std::stringstream getDataToSend() const;
};

#endif //TALLERZ_SERVERUSTILLEVENT_H
