#include <algorithm>
#include "Position.h"
Position::Position(unsigned long x, unsigned long y, unsigned short weight) : x(
    x), y(y), weight(weight) {}
unsigned long Position::chebyshevDistance(const Position &other) const {
  unsigned long
      distanceX = std::max(this->x, other.x) - std::min(this->x, other.x);
  unsigned long
      distanceY = std::max(this->y, other.y) - std::min(this->y, other.y);
  return std::max(distanceX, distanceY);
}
unsigned short Position::getWeight() const {
  return this->weight;
}
bool Position::operator==(const Position &node) const {
  return this->x == node.x && this->y == node.y;
}
Movement Position::getMovement(const Position &other) const{
  return DLEFT;
}

