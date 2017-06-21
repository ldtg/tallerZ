#ifndef TALLERZ_UNIT_H
#define TALLERZ_UNIT_H

#include <queue>
#include <stack>
#include "common/Map/Position.h"
#include "common/Types/TerrainType.h"
#include "common/States/UnitState.h"
#include "common/IDs/UnitID.h"
#include "Weapon.h"
#include "Attackable.h"
#include "UnitData.h"
#include "common/Map/TerrainData.h"
#include "Player.h"
#include "Team.h"
#include "Bullet.h"
#include "Capturable.h"
#include "common/IDs/CapturableID.h"
#include "MovementState.h"

class Unit : public Attackable {
 protected:
  Position currentPosition;
  Player *owner;
  Team team;
  UnitID id;
  MovementState movState;
  Weapon weapon;
  unsigned short range;
  unsigned short baseSpeed;
  unsigned short attackCounterBase;
  unsigned short health;
  unsigned short attackCounterActual;
  bool firstAttack;
  Attackable *hunted;
  Capturable *capturable;
  std::vector<Position> movementsPositions;
  std::vector<unsigned short> damagesToReceive;
  Unit(const Position &current,
       const UnitData &unitData,
       Player &owner,
       const Team &team);

  virtual void doOneMove();
  virtual unsigned short getMovementSpeed(float terrainFactor) const = 0;
 public:
  virtual void move(const std::vector<Position> &movementsPositions);
  virtual void capture(const std::vector<Position> &movementsPositions,
                       Capturable *capturable);
  virtual void hunt(const std::vector<Position> &movementsPositions,
                    Attackable *other);
  virtual void attack(Attackable *other);
  virtual void autoAttack(Attackable *hunted);
  virtual void doMoveWithSpeed(float terrainFactor);
  virtual void addMove(const Position &position);
  virtual void receiveDamages();
  virtual void receiveAttack(const Weapon &weapon) override;
  virtual void kill();

  virtual void still();
  virtual bool isTimeToAttack();
  virtual bool hasDamagesToReceive() const;
  virtual bool isInRange(Attackable *other) const;
  virtual bool attackedInRange() const;
  virtual bool canGoThrough(const TerrainData &terrainType) const = 0;
  virtual bool isAlive() const override;
  virtual bool isMoving() const override;
  virtual bool isCapturing() const;
  virtual bool isStill() const;
  virtual bool isAttacking() const;
  virtual bool isFirstAttack() const;
  virtual bool isAutoAttacking() const;
  virtual bool canAttack(Attackable *attackable) const;

  virtual UnitID getId() const;
  virtual UnitState getUnitState() const = 0;
  virtual Position getCenterPosition() const;
  virtual Position getAttackPosition(const Position &attacker) const override;
  virtual Position nextMovePosition() const override;
  virtual Attackable *getHunted();
  virtual Capturable *getCapturable();
  virtual Player *getOwner();
  virtual Team getOwnerTeam();
  virtual Bullet createBullet();

  virtual ~Unit();
};

#endif //TALLERZ_UNIT_H
