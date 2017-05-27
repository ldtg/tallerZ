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
#include "Player.h"
#include "Team.h"
#include "Bullet.h"

class Unit : public Attackable {
 protected:
  const UnitID id;
  Player &owner;
  Team &team;
  Position currentPosition;
  MovementState movState;
  const Weapon weapon;
  const unsigned short range;
  const unsigned short baseSpeed;
  const unsigned short attackCounterBase;
  unsigned short health;
  unsigned short attackCounterActual;

  Attackable *hunted;
  std::vector<Position> movementsPositions;
  std::vector<unsigned short> damagesToReceive;
  //para los vehiculos con conductor
  Unit(const Position &position,
       const UnitData &data,
       const UnitType &type, Player &owner,
       Team &team);

  Unit(const Position &current,
       const UnitData &data,
       Player& owner,
       Team &team);
 public:
  virtual ~Unit();
  virtual UnitState getUnitState();
  virtual Position getCurrentPosition() const;
  virtual Position getAttackPosition(const Position &attacker) const override ;
  virtual Position nextMovePosition() const override;
  virtual unsigned long getHealth() const;
  virtual bool hasDamagesToReceive() const;
  virtual void receiveDamages();
  virtual bool isInRange(Attackable *other);
  virtual bool attackedInRange();
  virtual void move(const std::vector<Position> &movementsPositions);
  virtual void capture(const std::vector<Position> &movementsPositions);
  virtual void doMoveWithSpeed(float terrainFactor);
  virtual void doOneMove();
  virtual void hunt(const std::vector<Position> &movementsPositions,
                    Attackable *other);
  virtual void attack(Attackable *other);
  virtual bool timeToAttack();
  virtual void receiveAttack(const Weapon &weapon) override;
  virtual bool canGoThrough(const TerrainData &terrainType) const = 0;
  virtual bool isAlive() const override;
  virtual bool isMoving() const override;
  virtual bool isCapturing() const;
  virtual bool isStill() const;
  virtual unsigned short getMovementSpeed(float terrainFactor) const = 0;
  bool isHunting();
  Attackable *getHunted();
  Weapon getWeapon();
  unsigned short getRange() const;
  UnitID getId() const;
  void addMove(const Position &position);
  bool canAttack(Attackable *attackable);
  virtual PlayerID getOwner() const;
  Bullet createBullet();
  void still();
};

#endif //TALLERZ_UNIT_H
