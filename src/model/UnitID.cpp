#include "UnitID.h"

unsigned long UnitID::nextid = 0;

UnitID::UnitID(const UnitType &type) : type(type), id(nextid) {
  nextid++;
}

bool UnitID::operator<(const UnitID &other) const {
  return this->id < other.id;
}
bool UnitID::operator==(const UnitID &other) const {
  return this->id == other.id;
}
bool UnitID::operator!=(const UnitID &other) const {
  return !this->operator==(other);
}
UnitType UnitID::getType() const {
  return type;
}
