#include <cereal/archives/binary.hpp>
#include "BuildUpdateTimeEvent.h"
BuildUpdateTimeEvent::BuildUpdateTimeEvent(const BuildID &id,
                                               const BuildState &state)
    : ServerEvent(B_UPDATE), data(id, state) {

}
std::stringstream BuildUpdateTimeEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
