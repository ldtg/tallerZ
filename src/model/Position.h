#ifndef TALLERZ_POSITION_H
#define TALLERZ_POSITION_H

class Position {
 private:
  unsigned long x;
  unsigned long y;
  unsigned short weight;
 public:
  Position(unsigned long x, unsigned long y, unsigned short weight);
  unsigned long chebyshevDistance(const Position &other) const;
  unsigned short getWeight() const;
  bool operator==(const Position &node) const;
};

#endif //TALLERZ_POSITION_H
