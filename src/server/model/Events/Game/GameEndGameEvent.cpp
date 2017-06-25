#include <cereal/archives/binary.hpp>
#include "GameEndGameEvent.h"
GameEndGameEvent::GameEndGameEvent(const TeamID &winner) : ServerEvent(
    G_ENDGAME), data(winner) {}
std::stringstream GameEndGameEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
