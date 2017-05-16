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

class Unit : public Attackable {
 protected:
  Position currentPosition;
  std::queue<Movement> movements;
  std::vector<unsigned short> damagesReceives;
  Weapon weapon;
  unsigned short range;
  UnitID id;
  UnitState state;
  Unit(Position current, UnitType type, WeaponType wtype);
 public:
  virtual ~Unit();
  virtual Position getCurrentPosition() const override;
  virtual Movement nextMove() const override;
  virtual Position nextPosition() const;
  virtual UnitState getState() const;
  virtual unsigned long getHealth() const;
  virtual void receiveDamages();
  virtual bool isInRange(Attackable *other);
  virtual bool attackedInRange();
  virtual void move(std::queue<Movement> moves);
  virtual void capture(std::queue<Movement> moves);
  virtual void doMove();
  virtual void hunt(std::queue<Movement> moves, Attackable *other);
  virtual void attack(Attackable *other);
  virtual void doAttack();
  virtual void receiveAttack(unsigned short damage) override;
  virtual bool canGoThrough(TerrainType terrainType) const = 0;
  virtual float getMovementCost(TerrainType terrainType) const = 0;
  virtual bool isAlive() const override;
  virtual bool isMoving() const override;
  virtual bool isCapturing() const;
  virtual bool isStill() const;
  bool isHunting();
  Attackable *getHunted();
  void addMove(Movement movement);
  Weapon getWeapon();
  UnitID getId() const;
};

#endif //TALLERZ_UNIT_H
