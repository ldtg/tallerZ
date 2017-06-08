#ifndef TALLERZ_DATAUNITATTACKEVENT_H
#define TALLERZ_DATAUNITATTACKEVENT_H

#include <common/Map/Position.h>
#include <common/IDs/UnitID.h>
struct dataUnitAttackEvent {
  UnitID attacker;
  Position huntedPos;
  Position attackerPos;
  dataUnitAttackEvent(const UnitID &id,
                      const Position &hpos,
                      const Position &attpos);
  dataUnitAttackEvent(){};
  template<class Archive>
  void serialize(Archive &archive) {
    archive(attacker, huntedPos, attackerPos);
  }
};

#endif //TALLERZ_DATAUNITATTACKEVENT_H
