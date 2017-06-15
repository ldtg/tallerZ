#include <cereal/archives/binary.hpp>
#include "serverBUpdateTimeEvent.h"
serverBUpdateTimeEvent::serverBUpdateTimeEvent(const BuildID &id,
                                               const BuildState &state)
    : serverEvent(B_UPDATE), data(id, state) {

}
std::stringstream serverBUpdateTimeEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
