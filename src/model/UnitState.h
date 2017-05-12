#ifndef TALLERZ_UNITSTATE_H
#define TALLERZ_UNITSTATE_H

#include "MovementState.h"
#include "Unit.h"
class UnitState {
 private:
  unsigned long health;
  MovementState movementState;
  Attackable *hunted;
 public:
  void moving();
  void still();
  void receiveDamage(unsigned short damage);
  bool isAlive();
  void hunting(Attackable *hunted);
  bool isHunting() const;
  bool isCapturing() const;
  Attackable* getHunted();
  bool isMoving() const;
  bool isStill() const;
  void capturing();
};

#endif //TALLERZ_UNITSTATE_H
