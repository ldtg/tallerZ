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
  virtual void addTerritory();
  virtual void subTerritory();
  virtual void addUnit();
  virtual void subUnit();
  virtual void buildDestroyed(const BuildType &type);
  virtual bool isAlive() const;
  void disconnect();
  virtual unsigned short getAmountOfTerritories() const;
  virtual PlayerID getID() const;
  virtual ~Player();
};

#endif //TALLERZ_PLAYER_H
