#include <common/DataEvents/Unit/dataUnitMoveEvent.h>
#include <client/model/Events/model/unit/UnitMoveEvent.h>
#include <cereal/archives/binary.hpp>
#include <common/DataEvents/Unit/dataUnitAttackEvent.h>
#include <client/model/Events/model/unit/UnitAttackEvent.h>
#include <common/DataEvents/Unit/dataUnitCreateEvent.h>
#include <client/model/Events/model/unit/UnitCreateEvent.h>
#include <common/DataEvents/Unit/dataUnitIDEvent.h>
#include <client/model/Events/model/unit/UnitDeathEvent.h>
#include <client/model/Events/model/unit/UnitStillEvent.h>
#include <common/DataEvents/Build/dataBuildDamageEvent.h>
#include <client/model/Events/model/build/BuildDamageEvent.h>
#include <common/DataEvents/Build/dataBuildIDEvent.h>
#include <client/model/Events/model/build/BuildDestroyedEvent.h>
#include <common/DataEvents/Bullet/dataBulletNewEvent.h>
#include <client/model/Events/model/bullet/BulletNewEvent.h>
#include <common/DataEvents/Bullet/dataBulletMoveEvent.h>
#include <client/model/Events/model/bullet/BulletMoveEvent.h>
#include <common/DataEvents/Bullet/dataBulletHitEvent.h>
#include <client/model/Events/model/bullet/BulletHitEvent.h>
#include <common/DataEvents/Capturable/dataCaptureEvent.h>
#include <client/model/Events/model/capturable/CaptureEvent.h>
#include <common/DataEvents/TerrainObject/dataTerrainObjectIDEvent.h>
#include <client/model/Events/model/terrainObject/TerrainObjectDestroyedEvent.h>
#include <common/DataEvents/Game/dataPlayerDefeatEvent.h>
#include <client/model/Events/model/game/PlayerDefeatedEvent.h>
#include <common/DataEvents/Game/dataEndGameEvent.h>
#include <client/model/Events/model/game/EndGameEvent.h>
#include "EventFactory.h"
Event *EventFactory::createEvent(const EventType &type, std::stringstream &ss) {
  switch (type) {
    case U_MOVE: {
      cereal::BinaryInputArchive iarchive(ss);
      dataUnitMoveEvent data;
      iarchive(data);
      return new UnitMoveEvent(data.id, data.posTo);
    }
    case U_ATTACK: {
      cereal::BinaryInputArchive iarchive(ss);
      dataUnitAttackEvent data;
      iarchive(data);
      return new UnitAttackEvent(data.attacker,
                                 data.huntedPos,
                                 data.attackerPos);
    }
    case U_CREATE: {
      cereal::BinaryInputArchive iarchive(ss);
      dataUnitCreateEvent data;
      iarchive(data);
      return new UnitCreateEvent(data.id, data.state);
    }
    case U_DEATH: {
      cereal::BinaryInputArchive iarchive(ss);
      dataUnitIDEvent data;
      iarchive(data);
      return new UnitDeathEvent(data.id);
    }
    case U_STILL: {
      cereal::BinaryInputArchive iarchive(ss);
      dataUnitIDEvent data;
      iarchive(data);
      return new UnitStillEvent(data.id);
    }
    case B_DAMAGE: {
      cereal::BinaryInputArchive iarchive(ss);
      dataBuildDamageEvent data;
      iarchive(data);
      return new BuildDamageEvent(data.id, data.newState);
    }
    case B_DESTROYED: {
      cereal::BinaryInputArchive iarchive(ss);
      dataBuildIDEvent data;
      iarchive(data);
      return new BuildDestroyedEvent(data.id);
    }
    case BLT_NEW: {
      cereal::BinaryInputArchive iarchive(ss);
      dataBulletNewEvent data;
      iarchive(data);
      return new BulletNewEvent(data.id, data.weapon, data.from, data.to);
    }
    case BLT_MOVE: {
      cereal::BinaryInputArchive iarchive(ss);
      dataBulletMoveEvent data;
      iarchive(data);
      return new BulletMoveEvent(data.id, data.posTo);
    }
    case BLT_HIT: {
      cereal::BinaryInputArchive iarchive(ss);
      dataBulletHitEvent data;
      iarchive(data);
      return new BulletHitEvent(data.id, data.pos, data.weapon);
    }
    case C_CAPTURE: {
      cereal::BinaryInputArchive iarchive(ss);
      dataCaptureEvent data;
      iarchive(data);
      return new CaptureEvent(data.capturer,
                              data.captured,
                              data.capturedPosition,
                              data.capturedBuilds,
                              data.capturedUnits,
                              data.capturerDissapear);
    }
    case TO_DESTROYED: {
      cereal::BinaryInputArchive iarchive(ss);
      dataTerrainObjectIDEvent data;
      iarchive(data);
      return new TerrainObjectDestroyedEvent(data.id);
    }
    case G_PDEFEATED: {
      cereal::BinaryInputArchive iarchive(ss);
      dataPlayerDefeatEvent data;
      iarchive(data);
      return new PlayerDefeatedEvent(data.playerID);
    }
    case G_ENDGAME: {
      cereal::BinaryInputArchive iarchive(ss);
      dataEndGameEvent data;
      iarchive(data);
      return new EndGameEvent(data.winner);
    }
  }
}
