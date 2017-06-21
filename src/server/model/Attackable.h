#ifndef TALLERZ_ATTACKABLE_H
#define TALLERZ_ATTACKABLE_H

#include "common/Map/Position.h"
#include "Weapon.h"
#include "common/IDs/PlayerID.h"
#include "Player.h"
class Attackable {
 public:
  virtual Position getAttackPosition(const Position &attacker) const = 0;
  virtual Position getCenterPosition() const = 0;
  virtual Player* getOwner() = 0;
  virtual bool isAlive() const = 0;
  virtual bool isMoving() const = 0;
  virtual Position nextMovePosition() const = 0;
  virtual void receiveAttack(const Weapon &weapon) = 0;
  virtual ~Attackable(){};
};

#endif //TALLERZ_ATTACKABLE_H
