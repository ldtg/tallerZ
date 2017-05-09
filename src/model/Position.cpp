#include <algorithm>
#include "Position.h"
Position::Position(long x, long y) : x(
    x), y(y) {}
long Position::chebyshevDistance(const Position &other) const {
  long
      distanceX = std::max(this->x, other.x) - std::min(this->x, other.x);
  long
      distanceY = std::max(this->y, other.y) - std::min(this->y, other.y);
  return std::max(distanceX, distanceY);
}
bool Position::operator==(const Position &other) const {
  return this->x == other.x && this->y == other.y;
}
Movement Position::getMovement(const Position &other) const {
  if (this->x == other.x) {
    if (this->y == other.y)
      return STAY;
    if ((this->y - other.y) < 0)
      return DOWN;
    else
      return UP;
  } else if ((this->x - other.x) < 0) {
    if (this->y == other.y)
      return LEFT;
    if ((this->y - other.y) < 0)
      return DLEFT;
    else
      return ULEFT;
  } else {
    if (this->y == other.y)
      return RIGHT;
    if ((this->y - other.y) < 0)
      return DRIGHT;
    else
      return URIGHT;
  }
}
Position Position::move(Movement movement) const {
  switch (movement) {
    case STAY:return *this;
    case UP:return Position(x, y + 1);
    case DOWN:return Position(x, y - 1);
    case LEFT:return Position(x - 1, y);
    case RIGHT:return Position(x + 1, y);
    case DLEFT:return Position(x - 1, y - 1);
    case DRIGHT:return Position(x + 1, y - 1);
    case ULEFT:return Position(x - 1, y + 1);
    case URIGHT: return Position(x + 1, y + 1);
  }
}
std::vector<Position> Position::getNeighbors() const {
  std::vector<Position> neighbors;
  for (int move = UP; move != STAY; move++) {
    neighbors.push_back(this->move(Movement(move)));
  }
  return neighbors;
}
bool Position::operator<(const Position &other) const {
  if (this->x == other.x)
    return this->y < other.y;
  return this->x < other.x;
}

coordinates_t Position::getCoordinates() const {
  return std::make_tuple(this->x, this->y);
}

