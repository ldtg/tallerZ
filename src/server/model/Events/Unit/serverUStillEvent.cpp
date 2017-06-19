#include <cereal/archives/binary.hpp>
#include "serverUStillEvent.h"

serverUStillEvent::serverUStillEvent(const UnitID &id, const Position &pos) :serverEvent(U_STILL), data(id,pos){}

std::stringstream serverUStillEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
