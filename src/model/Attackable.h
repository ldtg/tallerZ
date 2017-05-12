#ifndef TALLERZ_ATTACKABLE_H
#define TALLERZ_ATTACKABLE_H

#include "Position.h"
class Attackable {
 public:
  virtual Position getCurrentPosition() const = 0;
  virtual bool isAlive() const = 0;
  virtual bool isMoving() const = 0;
  virtual Movement nextMove() const = 0;
  virtual void receiveAttack(unsigned short damage) = 0;

};

#endif //TALLERZ_ATTACKABLE_H
