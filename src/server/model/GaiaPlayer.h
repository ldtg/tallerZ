#ifndef TALLERZ_GAIAPLAYER_H
#define TALLERZ_GAIAPLAYER_H

#include "Player.h"
//Player especial que siempre esta vivo
class GaiaPlayer : public Player {
 public:
  GaiaPlayer();
  virtual void addTerritory() override;
  virtual void subTerritory() override;
  virtual void addUnit() override;
  virtual void subUnit() override;
  virtual void buildDestroyed(const BuildType &type) override;
  virtual bool isAlive() const override;
  virtual ~GaiaPlayer();
};

#endif //TALLERZ_GAIAPLAYER_H
