#include <common/DataEvents/dataUnitMoveEvent.h>
#include <client/model/Events/model/unit/UnitMoveEvent.h>
#include <cereal/archives/binary.hpp>
#include "EventFactory.h"
Event *EventFactory::createEvent(const EventType &type, std::stringstream &ss) {
  switch (type) {
    case U_MOVE: {
      cereal::BinaryInputArchive iarchive(ss);
      dataUnitMoveEvent data;
      iarchive(data);
      return new UnitMoveEvent(data.id, data.posTo);
    }
  }
}
