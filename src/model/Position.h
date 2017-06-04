#ifndef TALLERZ_POSITION_H
#define TALLERZ_POSITION_H

#include <vector>
#include <tuple>

typedef std::tuple<long, long> coordinates_t;

class Position {
 private:
//  unsigned long x;
//  unsigned long y;
  long x;
  long y;

 public:
  Position();
  Position(long x, long y);
  unsigned long chebyshevDistance(const Position &other) const;
  unsigned long euclideanDistance(const Position &other) const;
  unsigned long manhattanDistance(const Position &other) const;
  void mod(unsigned short modx, unsigned short mody);
  void move(Position target);
  int getRoration(Position target) const;
  std::vector<Position> getNeighbors() const;
  coordinates_t getCoordinates() const;
  long getX() const;
  long getY() const;
//  bool isValid() const;
  bool operator==(const Position &other) const;
  bool operator!=(const Position &other) const;
  bool operator<(const Position &other) const;
  bool equalDelta(const Position &other, unsigned short delta) const;
  bool isIn(long width, long height);
  bool isIn(long width, long height, int otherX, int otherY) const;
  std::string toString() const;
  Position sub(unsigned long x, unsigned long y) const;
  Position add(unsigned long x, unsigned long y) const;
  Position getAttackPosition(const Position &position, const unsigned short size) const;
};

#endif //TALLERZ_POSITION_H
