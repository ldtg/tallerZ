#include "PlayerID.h"
unsigned short PlayerID::nextid = 1;// 0 es para gaia
PlayerID::PlayerID(const PlayerColor &color) : id(nextid), color(color) {
  if(color == PlayerColor::GREY){
    id = 0;
  } else {
    this->nextid++;
  }
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
