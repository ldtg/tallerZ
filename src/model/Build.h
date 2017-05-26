#ifndef TALLERZ_BUILD_H
#define TALLERZ_BUILD_H

#include "Attackable.h"
#include "BuildID.h"
#include "Player.h"
#include "UnitType.h"
class Build : public Attackable {
 private:
  const BuildID id;
  const Position centerPosition;
  const unsigned short size;
      //verificar con tech level
      const
  std::vector<UnitType> fabricableUnits;
  const unsigned short techLevel;
  std::vector<unsigned short> damagesToReceive;
  unsigned short health;
  UnitType actualUnitFab;
  unsigned short ticksBeforeCreate;
  bool timeToBuild;
  Player &owner;
 public:
  virtual Position getCurrentPosition() const override;
  virtual Position getAttackPosition(const Position &attackerPosition) const;
  virtual PlayerID getOwner() const ;
  virtual bool hasDamagesToReceive() const;
  virtual void receiveDamages();
  virtual bool isAlive() const override;
  virtual bool isMoving() const override;
  virtual Position nextMovePosition() const override;
  virtual void receiveAttack(const Weapon &weapon) override;
  void tick();
  bool hasToBuild();
  unsigned short getSpeedRate() const;
};

#endif //TALLERZ_BUILD_H
