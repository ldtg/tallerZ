#ifndef TALLERZ_SERVERUCREATEEVENT_H
#define TALLERZ_SERVERUCREATEEVENT_H
#include <server/model/Events/serverEvent.h>

#include <common/DataEvents/Unit/dataUnitCreateEvent.h>
class serverUCreateEvent : public serverEvent{
 private:
  dataUnitCreateEvent data;
 public:
  serverUCreateEvent(const UnitID &id, const UnitState &state);
  virtual std::stringstream getDataToSend() const;
};
#endif //TALLERZ_SERVERUCREATEEVENT_H
