#ifndef TALLERZ_BUILD_H
#define TALLERZ_BUILD_H

#include "Attackable.h"
#include "common/IDs/BuildID.h"
#include "Player.h"
#include "common/Types/UnitType.h"
#include "BuildData.h"
#include "common/States/BuildState.h"
#include "Unit.h"

class Build : public Attackable {
 private:
  BuildID id;
  Player *owner;
  Team team;
  Position centerPosition;
  //distancia desde el centro a los bordes
  unsigned short size;
  unsigned short techLevel;
  std::vector<UnitType> fabricableUnits;
  std::vector<unsigned short> damagesToReceive;
  unsigned short health;
  UnitType actualUnitFab;
  unsigned short ticksBeforeCreate;
  unsigned short actualTicksBeforeCreateBase;
  bool timeToBuild;

  unsigned short getSpeedRate() const;

 public:
  Build(const BuildData &data,
        const Position &centerPosition,
        Player &owner,const Team &team,
        const unsigned short techLevel);
  virtual Position getCenterPosition() const override;
  virtual Player* getOwner() ;
  virtual bool hasDamagesToReceive() const;
  virtual void receiveDamages();
  virtual bool isAlive() const override;
  virtual bool isMoving() const override;
  virtual Position nextMovePosition() const override;
  virtual void receiveAttack(const Weapon &weapon) override;

  //Para que cuando lo ataquen, ataquen la posicion mas cercana al atacante (solo las esquinas)
  virtual Position getAttackPosition(const Position &attackerPosition) const override;
  BuildID getId() const;
  BuildState getBuildState() const;
  void tick();
  bool hasToBuild();
  UnitType getActualUnitFab() const;
  std::vector<UnitType> getFabricableUnits() const;
  void changeFabUnit(const UnitType &type);
  void changePlayer(Player *player, const Team &team);
  std::vector<Unit *> fabricateUnits(const Position &buildPos);

  unsigned short get_health(){
    return this->health;
  }
};

#endif //TALLERZ_BUILD_H