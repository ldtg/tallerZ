#include <cereal/archives/binary.hpp>
#include "serverGPlayerDefeatedEvent.h"
serverGPlayerDefeatedEvent::serverGPlayerDefeatedEvent(const PlayerID &playerid)
    : serverEvent(G_PDEFEATED), data(playerid) {}
std::stringstream serverGPlayerDefeatedEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
