#include "UnitID.h"
unsigned long UnitID::nextid = 0;
UnitID::UnitID(UnitType type) : type(type) {
  this->id = nextid;
  nextid++;
}
bool UnitID::operator<(const UnitID &other) const {
  return this->id < other.id;
}
