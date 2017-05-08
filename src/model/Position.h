#ifndef TALLERZ_POSITION_H
#define TALLERZ_POSITION_H
#include <vector>
#include "Movement.h"
class Position {
 private:
  long x;
  long y;
 public:
  Position(long x, long y);
  long chebyshevDistance(const Position &other) const;
  Position move(Movement movement) const;
  Movement getMovement(const Position &other) const;
  std::vector<Position> getNeighbors() const;
  bool operator==(const Position &other) const;
  bool operator<(const Position &other) const;
};

#endif //TALLERZ_POSITION_H
