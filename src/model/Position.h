#ifndef TALLERZ_POSITION_H
#define TALLERZ_POSITION_H

#include <vector>
#include <tuple>
#include "Movement.h"

typedef std::tuple<long, long> coordinates_t;

class Position {
 private:
  long x;
  long y;
 public:
  Position(long x, long y);
  long chebyshevDistance(const Position &other) const;
  long euclideanDistance(const Position &other) const;

  Position move(Movement movement) const;
  Movement getMovement(const Position &other) const;
  std::vector<Position> getNeighbors() const;
  coordinates_t getCoordinates() const;
  bool isValid() const;
  bool operator==(const Position &other) const;
  bool operator<(const Position &other) const;
  bool isIn(unsigned long width, unsigned long height);
};

#endif //TALLERZ_POSITION_H
