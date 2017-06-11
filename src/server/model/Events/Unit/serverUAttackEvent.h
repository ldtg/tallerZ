#ifndef TALLERZ_SERVERUATTACKEVENT_H
#define TALLERZ_SERVERUATTACKEVENT_H

#include <common/DataEvents/Unit/dataUnitAttackEvent.h>
#include "server/model/Events/serverEvent.h"

class serverUAttackEvent : public serverEvent {
 private:
  dataUnitAttackEvent data;

 public:
  serverUAttackEvent(const UnitID &id,
                     const Position &hpos,
                     const Position &attpos);
  virtual std::stringstream getDataToSend() const;
};

#endif //TALLERZ_SERVERUATTACKEVENT_H
