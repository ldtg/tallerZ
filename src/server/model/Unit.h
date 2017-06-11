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
  const UnitID id;
  Player *owner;
  Team team;
  Position currentPosition;
  MovementState movState;
  const Weapon weapon;
  const unsigned short range;
  const unsigned short baseSpeed;
  const unsigned short attackCounterBase;
  unsigned short health;
  unsigned short attackCounterActual;
  bool firstAttack;
  Attackable *hunted;
  Capturable *capturable;
  std::vector<Position> movementsPositions;
  std::vector<unsigned short> damagesToReceive;

  Unit(const Position &current,
       const UnitData &unitData,
       Player& owner,
       Team team);

 public:
  virtual ~Unit();
  virtual UnitState getUnitState() const = 0;
  virtual Position getCenterPosition() const;
  virtual Position getAttackPosition(const Position &attacker) const override ;
  virtual Position nextMovePosition() const override;
  virtual unsigned long getHealth() const;
  virtual bool hasDamagesToReceive() const;
  virtual bool hasMovesToDo() const;
  virtual void receiveDamages();
  virtual bool isInRange(Attackable *other);
  virtual bool attackedInRange();
  virtual void move(const std::vector<Position> &movementsPositions);
  virtual void capture(const std::vector<Position> &movementsPositions, Capturable *capturable);
  virtual bool doMoveWithSpeed(float terrainFactor);
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
  virtual bool isFirstAttack() const;
  virtual void autoAttack(Attackable *hunted) ;
  virtual bool isAutoAttacking() const;
  virtual unsigned short getMovementSpeed(float terrainFactor) const = 0;
  void kill();
  bool isAttacking();
  Attackable *getHunted();
  Capturable *getCapturable();
  Weapon getWeapon();
  unsigned short getRange() const;
  UnitID getId() const;
  void addMove(const Position &position);
  bool canAttack(Attackable *attackable);
  virtual Player* getOwner();
  virtual Team getOwnerTeam();
  Bullet createBullet();
  void still();
  virtual bool capturableInRange();
};

#endif //TALLERZ_UNIT_H