#ifndef TALLERZ_DATAUNITATTACKEVENT_H
#define TALLERZ_DATAUNITATTACKEVENT_H

#include <common/Map/Position.h>
#include <common/IDs/UnitID.h>

struct DataUnitAttackEvent {
  UnitID attacker;
  Position huntedPos;
  Position attackerPos;
  DataUnitAttackEvent(const UnitID &id,
                      const Position &hpos,
                      const Position &attpos);
  DataUnitAttackEvent(){};
  template<class Archive>
  void serialize(Archive &archive) {
    archive(attacker, huntedPos, attackerPos);
  }
};

#endif //TALLERZ_DATAUNITATTACKEVENT_H
