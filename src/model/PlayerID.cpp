#include "PlayerID.h"

unsigned short PlayerID::nextid = 1;// 0 es para gaia

PlayerID::PlayerID(const PlayerColor &color) : id(nextid), color(color) {
  if(color == PlayerColor::GREY){
    id = 0;
  } else {
    this->nextid++;
  }
}

std::string PlayerID::getColor() const {
  std::string color_s;
  switch (color) {
    case RED: color_s = "red"; break;
    case GREEN: color_s = "green"; break;
    case BLUE: color_s = "blue"; break;
    case GREY: color_s = "grey"; break;
    default: color_s = ""; break;
  }

  return color_s;
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
