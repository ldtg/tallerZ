#ifndef TALLERZ_SERVERUATTACKEVENT_H
#define TALLERZ_SERVERUATTACKEVENT_H

#include <common/DataEvents/Unit/DataUnitAttackEvent.h>
#include "server/model/Events/ServerEvent.h"

class UnitAttackEvent : public ServerEvent {
 private:
  DataUnitAttackEvent data;

 public:
  UnitAttackEvent(const UnitID &id,
                     const Position &hpos,
                     const Position &attpos);
  virtual std::stringstream getDataToSend() const;
};

#endif //TALLERZ_SERVERUATTACKEVENT_H
