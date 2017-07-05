#ifndef TALLERZ_POSITION_H
#define TALLERZ_POSITION_H

#include <vector>
#include <tuple>

class Position {
 private:
  long x;
  long y;

 public:
  Position();
  Position(long x, long y);
  unsigned long chebyshevDistance(const Position &other) const;
  void mod(unsigned short modx, unsigned short mody);
  void move(Position target);
  int getRoration(Position target) const;
  long getX() const;
  long getY() const;
  bool operator==(const Position &other) const;
  bool operator!=(const Position &other) const;
  bool operator<(const Position &other) const;
  bool equalDelta(const Position &other, unsigned short delta) const;
  bool isIn(long width, long height);
  Position sub(unsigned long x, unsigned long y) const;
  Position add(unsigned long x, unsigned long y) const;
  Position getAttackPosition(const Position &position,
                             const unsigned short size) const;
  std::vector<Position> getStraighNeighbors() const;
  std::vector<Position> getDiagonalNeighbors() const;
  std::vector<Position> getNeighborsOfDiagonal(const Position &position) const;
  template<class Archive>
  void serialize(Archive &archive) {
    archive(x, y);
  }
};

#endif //TALLERZ_POSITION_H
