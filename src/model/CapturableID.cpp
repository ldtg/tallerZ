#include "CapturableID.h"

unsigned short CapturableID::nextid = 0;

CapturableID::CapturableID(const CapturableType &type)
    : id(nextid), type(type) { nextid++; }

CapturableType CapturableID::getType() const {
  return type;
}

bool CapturableID::operator<(const CapturableID &other) const {
  return this->id < other.id;
}

bool CapturableID::operator==(const CapturableID &other) const {
  return this->id == other.id;
}

bool CapturableID::operator!=(const CapturableID &other) const {
  return !this->operator==(other);
}
