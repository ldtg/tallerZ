#include <algorithm>
#include <cmath>
#include "Position.h"

//Position::Position() {}

Position::Position(unsigned long x, unsigned long y)
    : x(x), y(y) {}

unsigned long Position::chebyshevDistance(const Position &other) const {
  long
      distanceX = std::max(this->x, other.x) - std::min(this->x, other.x);
  long
      distanceY = std::max(this->y, other.y) - std::min(this->y, other.y);
  return std::max(distanceX, distanceY);
}

unsigned long Position::euclideanDistance(const Position &other) const {
  return std::lround(std::sqrt(
      std::pow(this->x - other.x, 2) + std::pow(this->y - other.y, 2)));
}

bool Position::operator==(const Position &other) const {
  return this->x == other.x && this->y == other.y;
}

std::vector<Position> Position::getNeighbors() const {
  std::vector<Position> neighbors;
  neighbors.push_back(Position(x + 1, y));
  neighbors.push_back(Position(x + 1, y + 1));
  neighbors.push_back(Position(x, y + 1));
  if (x != 0 && y != 0) {
    neighbors.push_back(Position(x - 1, y - 1));
    neighbors.push_back(Position(x - 1, y - 1));
  } else if (x == 0 && y != 0) {
    neighbors.push_back(Position(x, y - 1));
    neighbors.push_back(Position(x + 1, y - 1));
  } else {
    neighbors.push_back(Position(x - 1, y));
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

bool Position::isIn(long width, long height) {
  return (x < width) && (y < height);
}
void Position::mod(unsigned short modx, unsigned short mody) {
  this->x = this->x / modx;
  this->y = this->y / mody;
}
void Position::move(Position target) {
  if (this->x < target.x)
    this->x++;
  else if (this->x > target.x)
    this->x--;
  if (this->y < target.y)
    this->y++;
  else if (this->y > target.y)
    this->y--;
}
bool Position::operator!=(const Position &other) const {
  return !(this->operator==(other));
}

