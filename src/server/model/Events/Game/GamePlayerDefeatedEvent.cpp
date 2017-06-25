#include <cereal/archives/binary.hpp>
#include "GamePlayerDefeatedEvent.h"
GamePlayerDefeatedEvent::GamePlayerDefeatedEvent(const PlayerID &playerid)
    : ServerEvent(G_PDEFEATED), data(playerid) {}
std::stringstream GamePlayerDefeatedEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
