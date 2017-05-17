#ifndef TALLERZ_UNIT_H
#define TALLERZ_UNIT_H

#include <queue>
#include <stack>
#include "Position.h"
#include "TerrainType.h"
#include "UnitState.h"
#include "UnitID.h"
#include "Weapon.h"
#include "Attackable.h"
#include "UnitData.h"
#include "TerrainData.h"

class Unit : public Attackable {
 protected:
  const UnitID id;
  Position currentPosition;
  MovementState movState;
  const Weapon weapon;
  const unsigned short range;
  const unsigned short baseSpeed;
  unsigned short health;

  Attackable *hunted;
  std::queue<Position> movementsPositions;
  std::vector<unsigned short> damagesReceives;
  Unit(Position current, UnitData data);
 public:
  virtual ~Unit();
  virtual UnitState getUnitState();
  virtual Position getCurrentPosition() const override;
  virtual Position nextMovePosition() const override;
  virtual unsigned long getHealth() const;
  virtual void receiveDamages();
  virtual bool isInRange(Attackable *other);
  virtual bool attackedInRange();
  virtual void move(std::queue<Position> movementsPositions);
  virtual void capture(std::queue<Position> movementsPositions);
  virtual void doMoveWithSpeed(float terrainFactor);
  virtual void doOneMove();
  virtual void hunt(std::queue<Position> movementsPositions, Attackable *other);
  virtual void attack(Attackable *other);
  virtual void doAttack();
  virtual void receiveAttack(Weapon weapon) override;
  virtual bool canGoThrough(TerrainData terrainType) const = 0;
  virtual bool isAlive() const override;
  virtual bool isMoving() const override;
  virtual bool isCapturing() const;
  virtual bool isStill() const;
  virtual unsigned short getMovementSpeed(float terrainFactor) const = 0;
  bool isHunting();
  Attackable *getHunted();
  Weapon getWeapon();
  UnitID getId() const;
};

#endif //TALLERZ_UNIT_H
