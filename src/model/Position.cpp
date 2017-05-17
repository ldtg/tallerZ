#include <algorithm>
#include <cmath>
#include "Position.h"

//Position::Position() {}

Position::Position(long x, long y)
    : x(x), y(y) {}

/*
Position::Position(const Position &other) {
  this->x = other.x;
  this->y = other.y;
}

Position& Position::operator=(const Position &other) {
  this->x = other.x;
  this->y = other.y;

  return *this;
}

Position::Position(Position &&other) {
  this->x = other.x;
  this->y = other.y;

  other.x = -1;
  other.y = -1;
}

Position& Position::operator=(Position &&other) {
  this->x = other.x;
  this->y = other.y;

  other.x = -1;
  other.y = -1;

  return *this;
}
*/

long Position::chebyshevDistance(const Position &other) const {
  long
      distanceX = std::max(this->x, other.x) - std::min(this->x, other.x);
  long
      distanceY = std::max(this->y, other.y) - std::min(this->y, other.y);
  return std::max(distanceX, distanceY);
}

long Position::euclideanDistance(const Position &other) const {
    return std::lround(std::sqrt(
            std::pow(this->x - other.x, 2) + std::pow(this->y - other.y, 2)));
}

bool Position::operator==(const Position &other) const {
  return this->x == other.x && this->y == other.y;
}

Movement Position::getMovement(const Position &other) const {
  if (this->x == other.x) {
    if (this->y == other.y)
      return STAY;
    if ((this->y - other.y) > 0)
      return UP;
    else
      return DOWN;
  } else if ((this->x - other.x) > 0) {
    if (this->y == other.y)
      return LEFT;
    if ((this->y - other.y) > 0)
      return ULEFT;
    else
      return DLEFT;
  } else {
    if (this->y == other.y)
      return RIGHT;
    if ((this->y - other.y) > 0)
      return URIGHT;
    else
      return DRIGHT;
  }
}
Position Position::move(Movement movement) const {
  switch (movement) {
    case STAY:return *this;
    case UP:return Position(x, y - 1);
    case DOWN:return Position(x, y + 1);
    case LEFT:return Position(x - 1, y);
    case RIGHT:return Position(x + 1, y);
    case DLEFT:return Position(x - 1, y + 1);
    case DRIGHT:return Position(x + 1, y + 1);
    case ULEFT:return Position(x - 1, y - 1);
    case URIGHT: return Position(x + 1, y - 1);
    default: return Position(0, 0);
  }
}

std::vector<Position> Position::getNeighbors() const {
  std::vector<Position> neighbors;
  for (int move = UP; move != STAY; move++) {
    Position aux = this->move(Movement(move));
    if (aux.isValid())
      neighbors.push_back(aux);
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

bool Position::isValid() const {
  return (x >= 0) && (y >= 0);
}

bool Position::isIn(long width, long height) {
  return (x < width) && (y < height);
}

