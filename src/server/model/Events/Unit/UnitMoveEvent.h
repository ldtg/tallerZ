#ifndef TALLERZ_SERVERUMOVEEVENT_H
#define TALLERZ_SERVERUMOVEEVENT_H
#include <server/model/Events/ServerEvent.h>
#include <common/DataEvents/Unit/DataUnitMoveEvent.h>

class UnitMoveEvent : public ServerEvent {
 private:
  DataUnitMoveEvent data;
 public:
  UnitMoveEvent(const UnitID &id, const Position &pos);
  virtual std::stringstream getDataToSend() const;

};

#endif //TALLERZ_SERVERUMOVEEVENT_H
