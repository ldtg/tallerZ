#ifndef TALLERZ_TERRAINOBJECT_H
#define TALLERZ_TERRAINOBJECT_H

#include "Attackable.h"
#include "TerrainObjectType.h"
#include "TerrainObjectID.h"
#include "TerrainObjectState.h"
#include "TerrainObjectData.h"
class TerrainObject : public Attackable {
 private:
  TerrainObjectID id;
  Position centerPosition;
  unsigned short health;
  unsigned short size;
  std::vector<unsigned short> damagesToReceive;
  bool passable;
  Player &owner;
 public:
  virtual Player &getOwner();
  explicit TerrainObject(const TerrainObjectData &data,
                         const Position &centerPos,
                         Player &owner);
  virtual Position getAttackPosition(const Position &attacker) const override;
  virtual bool isAlive() const;
  virtual bool isMoving() const;
  virtual Position nextMovePosition() const;
  virtual void receiveAttack(const Weapon &weapon);
  virtual bool hasDamagesToReceive() const;
  virtual void receiveDamages();
  TerrainObjectID getID() const;
  TerrainObjectState getState() const;
  virtual Position getCenterPosition() const override;
};

#endif //TALLERZ_TERRAINOBJECT_H
