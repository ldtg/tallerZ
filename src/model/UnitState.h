#ifndef TALLERZ_UNITSTATE_H
#define TALLERZ_UNITSTATE_H

#include "MovementState.h"
#include "Attackable.h"
#include "UnitType.h"
class UnitState {
 private:
  unsigned long health;
  MovementState movementState;
  Attackable *hunted;
 public:
  UnitState(UnitType type);
  void moving();
  void still();
  void receiveDamage(unsigned short damage);
  void hunting(Attackable *hunted);
  void capturing();
  bool isAlive() const;
  bool isHunting() const;
  bool isCapturing() const;
  bool isMoving() const;
  bool isStill() const;
  Attackable* getHunted() const;

  unsigned long getHealth() const;
};

#endif //TALLERZ_UNITSTATE_H
