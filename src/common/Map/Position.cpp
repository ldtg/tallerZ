#include <algorithm>
#include <sstream>
#include <iostream>
#include "Position.h"

Position::Position() : x(0), y(0) {}

Position::Position(long x, long y)
    : x(x), y(y) {}

unsigned long Position::chebyshevDistance(const Position &other) const {
  unsigned long aux =(unsigned long)
      std::max(std::labs(this->x - other.x), std::labs(this->y - other.y));
  return aux;
}

bool Position::operator==(const Position &other) const {
  return this->x == other.x && this->y == other.y;
}

bool Position::operator<(const Position &other) const {
  if (this->x == other.x)
    return this->y < other.y;
  return this->x < other.x;
}

bool Position::isIn(long width, long height) {
  return (x < width) && (y < height);
}

void Position::mod(unsigned short modx, unsigned short mody) {
  this->x = this->x / modx;
  this->y = this->y / mody;
}

void Position::move(Position target) {
  if (this->x < target.x) {
    this->x++;
  } else if (this->x > target.x) {
    this->x--;
  }

  if (this->y < target.y) {
    this->y++;
  } else if (this->y > target.y) {
    this->y--;
  }
}

int Position::getRoration(Position target) const {
  int rotation = 0;

  if (this->x < target.x) {
    if (this->y < target.y) {
      rotation = 315;
    } else if (this->y > target.y) {
      rotation = 45;
    } else {
      rotation = 0;
    }
  } else if (this->x > target.x) {
    if (this->y < target.y) {
      rotation = 225;
    } else if (this->y > target.y) {
      rotation = 135;
    } else {
      rotation = 180;
    }
  } else {
    if (this->y < target.y) {
      rotation = 270;
    } else if (this->y > target.y) {
      rotation = 90;
    }
  }

  return rotation;
}

bool Position::operator!=(const Position &other) const {
  return !(this->operator==(other));
}

bool Position::equalDelta(const Position &other, unsigned short delta) const {
  double xdelta = std::pow(other.x - this->x, 2);
  double ydelta = std::pow(other.y - this->y, 2);

  return std::sqrt(xdelta + ydelta) <= delta;
}

long Position::getX() const {
  return x;
}
long Position::getY() const {
  return y;
}

Position Position::sub(unsigned long x, unsigned long y) const {
  return Position(this->x - x, this->y - y);
}

Position Position::add(unsigned long x, unsigned long y) const {
  return Position(this->x + x, this->y + y);
}

Position Position::getAttackPosition(const Position &position,
                                     const unsigned short size) const {
  Position attacker = position;
  Position attacked = Position(x, y);
  Position attackedBase = Position(x, y);
  while (attackedBase.chebyshevDistance(attacked) < size) {
    attacked.move(attacker);
  }
  return attacked;
}
std::vector<Position> Position::getStraighNeighbors() const {
  std::vector<Position> neighbors;
  neighbors.push_back(Position(x + 1, y));
  neighbors.push_back(Position(x, y + 1));
  if (x != 0) {
    neighbors.push_back(Position(x - 1, y));
  }
  if (y != 0) {
    neighbors.push_back(Position(x, y - 1));
  }

  return neighbors;
}
std::vector<Position> Position::getDiagonalNeighbors() const {
  std::vector<Position> neighbors;
  neighbors.push_back(Position(x + 1, y + 1));
  if (x != 0) {
    neighbors.push_back(Position(x - 1, y + 1));
    if (y != 0) {
      neighbors.push_back(Position(x - 1, y - 1));
    }
  }
  if (y != 0) {
    neighbors.push_back(Position(x + 1, y - 1));
  }

  return neighbors;
}
std::vector<Position> Position::getNeighborsOfDiagonal(const Position &position) const {
  std::vector<Position> neighbors;
  if (position.x > this->x) {
    neighbors.push_back(Position(x + 1, y));
    if (position.y > this->y) {
      neighbors.push_back(Position(x, y + 1));
    } else {
      neighbors.push_back(Position(x, y - 1));
    }
  } else {
    neighbors.push_back(Position(x - 1, y));
    if (position.y > this->y) {
      neighbors.push_back(Position(x, y + 1));
    } else {
      neighbors.push_back(Position(x, y - 1));
    }
  }

  return neighbors;
}

