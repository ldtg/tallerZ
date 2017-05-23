#ifndef TALLERZ_PLAYER_H
#define TALLERZ_PLAYER_H

#include "PlayerID.h"
#include "Position.h"
#include "BuildType.h"
class Player {
 private:
  const PlayerID id;
  unsigned short capturedTerritories;
  unsigned short unitsAlives;
  bool alive;
 public:
  explicit Player(const std::string &name);
  unsigned short getAmountOfTerritories();
  void addTerritory();
  void subTerritory();
  void addUnit();
  void subUnit();
  bool isAlive() const;
  void buildDestroyed(const BuildType &type);
  PlayerID getID() const;

};

#endif //TALLERZ_PLAYER_H
