#ifndef TALLERZ_ATTACKABLE_H
#define TALLERZ_ATTACKABLE_H

#include "Position.h"
#include "Weapon.h"
class Attackable {
 public:
  virtual Position getCurrentPosition() const = 0;
  virtual bool isAlive() const = 0;
  virtual bool isMoving() const = 0;
  virtual Position nextMovePosition() const = 0;
  virtual void receiveAttack(Weapon weapon) = 0;

};

#endif //TALLERZ_ATTACKABLE_H
