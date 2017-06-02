#ifndef TALLERZ_GAIAPLAYER_H
#define TALLERZ_GAIAPLAYER_H

#include "Player.h"
class GaiaPlayer : public Player {
 public:
  GaiaPlayer();
  virtual unsigned short getAmountOfTerritories();
  virtual void addTerritory();
  virtual void subTerritory();
  virtual void addUnit();
  virtual void subUnit();
  virtual bool isAlive() const;
  virtual void buildDestroyed(const BuildType &type);

};

#endif //TALLERZ_GAIAPLAYER_H
