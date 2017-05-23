#include "BuildID.h"
unsigned long BuildID::nextid = 0;

BuildID::BuildID(const BuildType &buildType) : type(type), id(nextid) {
  nextid++;
}
bool BuildID::operator<(const BuildID &other) const {
  return id < other.id;
}
BuildType BuildID::getType() const {
  return type;
}
