#ifndef TALLERZ_TERRAINOBJECT_H
#define TALLERZ_TERRAINOBJECT_H

#include "Attackable.h"
#include "common/Types/TerrainObjectType.h"
#include "common/IDs/TerrainObjectID.h"
#include "common/States/TerrainObjectState.h"
#include "TerrainObjectData.h"
class TerrainObject : public Attackable {
 private:
  TerrainObjectID id;
  Position centerPosition;
  unsigned short health;
  unsigned short size;
  std::vector<unsigned short> damagesToReceive;
  bool passable;
  Player *owner;
 public:
  TerrainObject(const TerrainObjectData &data,
                const Position &centerPos,
                Player *owner);
  virtual Player *getOwner() override;
  virtual Position getAttackPosition(const Position &attacker) const override;
  virtual Position nextMovePosition() const override;
  virtual void receiveAttack(const Weapon &weapon) override;
  virtual void receiveDamages();
  virtual bool isAlive() const override;
  virtual bool isMoving() const override;
  virtual bool hasDamagesToReceive() const;
  virtual TerrainObjectID getID() const;
  virtual TerrainObjectState getState() const;
  virtual Position getCenterPosition() const override;
  virtual ~TerrainObject() override;
};

#endif //TALLERZ_TERRAINOBJECT_H
