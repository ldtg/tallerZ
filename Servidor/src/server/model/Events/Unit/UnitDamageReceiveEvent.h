#ifndef TALLERZ_SERVIDOR_UNITDAMAGERECEIVEEVENT_H
#define TALLERZ_SERVIDOR_UNITDAMAGERECEIVEEVENT_H

#include <server/model/Events/ServerEvent.h>
#include <common/DataEvents/Unit/DataUnitStateEvent.h>
class UnitDamageReceiveEvent  : public ServerEvent{
 private:
  DataUnitStateEvent data;
 public:
  UnitDamageReceiveEvent(const UnitID &id, const UnitState &state);
  virtual std::stringstream getDataToSend() const;
};

#endif //TALLERZ_SERVIDOR_UNITDAMAGERECEIVEEVENT_H
