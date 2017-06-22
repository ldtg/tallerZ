#ifndef TALLERZ_SERVERUCREATEEVENT_H
#define TALLERZ_SERVERUCREATEEVENT_H
#include <server/model/Events/ServerEvent.h>

#include <common/DataEvents/Unit/DataUnitCreateEvent.h>
class UnitCreateEvent : public ServerEvent{
 private:
  DataUnitCreateEvent data;
 public:
  UnitCreateEvent(const UnitID &id, const UnitState &state);
  virtual std::stringstream getDataToSend() const;
};
#endif //TALLERZ_SERVERUCREATEEVENT_H
