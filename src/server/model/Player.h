#ifndef TALLERZ_PLAYER_H
#define TALLERZ_PLAYER_H

#include "common/IDs/PlayerID.h"
#include "common/Map/Position.h"
#include "common/Types/BuildType.h"

class Player {
 private:
  PlayerID id;
  unsigned short capturedTerritories;
  unsigned short unitsAlives;
  bool alive;
 public:
  explicit Player(const PlayerColor &color);
  virtual unsigned short getAmountOfTerritories();
  virtual void addTerritory();
  virtual void subTerritory();
  virtual void addUnit();
  virtual void subUnit();
  virtual bool isAlive() const;
  virtual void buildDestroyed(const BuildType &type);
  virtual PlayerID getID() const;
};

#endif //TALLERZ_PLAYER_H
