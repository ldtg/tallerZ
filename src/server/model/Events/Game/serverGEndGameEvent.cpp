#include <cereal/archives/binary.hpp>
#include "serverGEndGameEvent.h"
serverGEndGameEvent::serverGEndGameEvent(const TeamID &winner) : serverEvent(
    G_ENDGAME), data(winner) {}
std::stringstream serverGEndGameEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
