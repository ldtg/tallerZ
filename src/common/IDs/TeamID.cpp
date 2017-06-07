#include "TeamID.h"
unsigned short TeamID::nextID = 0;
TeamID::TeamID() : id(nextID) {
  nextID++;
}
bool TeamID::operator<(const TeamID &other) const {
  return id < other.id;
}
bool TeamID::operator==(const TeamID &other) const {
  return id == other.id;
}
bool TeamID::operator!=(const TeamID &other) const {
  return !this->operator==(other);
}
