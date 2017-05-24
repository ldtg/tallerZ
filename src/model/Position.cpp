#include <algorithm>
#include <cmath>
#include <sstream>
#include "Position.h"

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
  unsigned long aux =
      std::max(std::labs(this->x - other.x), std::labs(this->y - other.y));
  return aux;
}

bool Position::operator==(const Position &other) const {
  return this->x == other.x && this->y == other.y;
}

std::vector<Position> Position::getNeighbors() const {
  std::vector<Position> neighbors;
  neighbors.push_back(Position(x + 1, y));
  neighbors.push_back(Position(x, y + 1));
  neighbors.push_back(Position(x + 1, y + 1));
  if (x != 0) {
    neighbors.push_back(Position(x - 1, y + 1));
    neighbors.push_back(Position(x - 1, y));
    if (y != 0) {
      neighbors.push_back(Position(x - 1, y - 1));
    }
  }
  if (y != 0) {
    neighbors.push_back(Position(x, y - 1));
    neighbors.push_back(Position(x + 1, y - 1));
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

bool Position::isIn(long width, long height, int otherX, int otherY) const {
  return (otherX <= x <= otherX + width) && (otherY <= y <= otherY + height);
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
bool Position::equalDelta(const Position &other, unsigned short delta) const {
  return std::abs(this->x - other.x) < delta
      && std::abs(this->y - other.y) < delta;
}
std::string Position::toString() const {
  std::stringstream aux;
  aux << x << ", " << y;
  return aux.str();
}

long Position::getX() const {
  return x;
}

long Position::getY() const {
  return y;
}
Position Position::sub(unsigned long x, unsigned long y) const{
  return Position(this->x-x, this->y-y);
}
