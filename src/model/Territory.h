#ifndef TALLERZ_TERRITORY_H
#define TALLERZ_TERRITORY_H

#include "Position.h"
#include "Player.h"
#include "Build.h"
class Territory {
 private:
  std::vector<Build *> builds;
  Position flagPosition;
  Player &owner;
 public:
  Territory(const Position &flagPosition, const std::vector<Build *> &builds);
  void capture(Player &newOwner);
};

#endif //TALLERZ_TERRITORY_H
