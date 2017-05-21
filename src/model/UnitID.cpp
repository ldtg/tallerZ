#include "UnitID.h"

unsigned long UnitID::nextid = 0;

UnitID::UnitID(const UnitType &type) : type(type), id(nextid) {
  nextid++;
}

bool UnitID::operator<(const UnitID &other) const {
  return this->id < other.id;
}
UnitType UnitID::getUnitType() const {
  return this->type;
}
UnitID::UnitID(const UnitType &type, const UnitType &second)
    : type(type), id(nextid), secondType(second) {
}
UnitType UnitID::getSecondUnitType() const {
  return this->secondType;
}
void UnitID::setSecondUnitType(const UnitType &type) {
  this->secondType = type;
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
