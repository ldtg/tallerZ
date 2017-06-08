#ifndef TALLERZ_SERVERUMOVEEVENT_H
#define TALLERZ_SERVERUMOVEEVENT_H
#include <server/model/Events/serverEvent.h>
#include <common/DataEvents/dataUnitMoveEvent.h>

class serverUMoveEvent : public serverEvent {
 private:
  dataUnitMoveEvent data;
 public:
  serverUMoveEvent(const UnitID &id, const Position &pos);
  virtual std::stringstream getDataToSend() const;

};

#endif //TALLERZ_SERVERUMOVEEVENT_H
