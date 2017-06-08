#ifndef TALLERZ_SERVERUMOVEEVENT_H
#define TALLERZ_SERVERUMOVEEVENT_H

#include <common/DataEvents/dataUnitMoveEvent.h>
#include "serverEvent.h"
class serverUMoveEvent : public serverEvent{//si se llama serverUnitMoveEvent no anda, ree loco
 private:
  dataUnitMoveEvent data;
 public:
  serverUMoveEvent(const UnitID &id, const Position &pos);
  virtual std::stringstream getDataToSend() const;
};

#endif //TALLERZ_SERVERUMOVEEVENT_H
