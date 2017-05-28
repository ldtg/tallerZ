#include "PlayerID.h"
unsigned short PlayerID::nextid = 0;
PlayerID::PlayerID(const std::string &name) : id(nextid), name(name) {
  this->nextid++;
}
std::string PlayerID::getName() const {
  return name;
}
bool PlayerID::operator<(const PlayerID &other) const {
  return this->id < other.id;
}
bool PlayerID::operator==(const PlayerID &other) const {
  return this->id == other.id;
}
bool PlayerID::operator!=(const PlayerID &other) const {
  return !this->operator==(other);
}
