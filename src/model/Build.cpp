#include <algorithm>
#include <Exceptions/model_exceptions/UnableToBuildThatUnitException.h>
#include "Build.h"
#include "Data.h"
#include "UnitFactory.h"

Position Build::getCenterPosition() const {
  return centerPosition;
}

Player *Build::getOwner() {
  return owner;
}

bool Build::isAlive() const {
  return health > 0;
}

bool Build::isMoving() const {
  return false;
}

Position Build::nextMovePosition() const {
  return centerPosition;
}

void Build::receiveAttack(const Weapon &weapon) {
//  if (weapon.isExplosive)
    this->damagesToReceive.push_back(weapon.damage);
}

Position Build::getAttackPosition(const Position &attackerPosition) const {
  return centerPosition.getAttackPosition(attackerPosition, size);
}

void Build::tick() {
  if (ticksBeforeCreate > 0) {
    ticksBeforeCreate--;
  } else if (owner->getAmountOfTerritories() > 0) {//para que gaia no cree unidades
    ticksBeforeCreate = this->getSpeedRate();
    timeToBuild = true;
  }
}

bool Build::hasToBuild() {
  return timeToBuild;
}

unsigned short Build::getSpeedRate() const {
  unsigned long timeInSecs;
  float baseTaken = (float) data.getData(actualUnitFab).factoryBaseTimeInSec
      / (float) owner->getAmountOfTerritories();
  float rel = (float) (this->health - data.getData(this->id.getType()).health)
      / (float) data.getData(this->id.getType()).health;
  float relsqrt = std::sqrt(1 - rel);
  timeInSecs = std::lround(baseTaken / relsqrt);

  return data.getTickAmount(timeInSecs);
}

bool Build::hasDamagesToReceive() const {
  return !damagesToReceive.empty();
}

void Build::receiveDamages() {
  for (auto damage: damagesToReceive) {
    if (this->health > damage) {
      this->health -= damage;
    } else {
      this->health = 0;
      owner->buildDestroyed(this->id.getType());
      damagesToReceive.clear();
      return;
    }
  }
  damagesToReceive.clear();
}

Build::Build(const BuildData &buildData,
             const Position &centerPosition,
             Player &owner, Team team,
             const unsigned short techLevel)
    : id(buildData.type),
      owner(&owner), team(team),
      centerPosition(centerPosition),
      size(buildData.size),
      techLevel(techLevel),
      fabricableUnits(data.getFabUnits(buildData.type, techLevel)),
      ticksBeforeCreate(this->getSpeedRate()),
      health(buildData.health),
      timeToBuild(false),
      actualUnitFab(UnitType::R_GRUNT) {

}

UnitType Build::getActualUnitFab() const {
  return actualUnitFab;
}

std::vector<UnitType> Build::getFabricableUnits() const {
  return fabricableUnits;
}

void Build::changeFabUnit(const UnitType &type) {
  if (std::find(fabricableUnits.begin(), fabricableUnits.end(), type)
      == fabricableUnits.end()) {
    throw UnableToBuildThatUnitException(
        "El tipo de unidad no esta en el vector de tipos permitidos");
  } else {
    this->actualUnitFab = type;
    this->ticksBeforeCreate = this->getSpeedRate();
    this->timeToBuild = false;
  }
}

BuildID Build::getId() const {
  return this->id;
}

BuildState Build::getBuildState() const {
  return BuildState(owner->getID(), centerPosition.sub(BUILDWIDHT/2, BUILDHEIGHT/2),
                    health,
                    data.ticksToSec(ticksBeforeCreate),
                    actualUnitFab);
}

std::vector<Unit *> Build::fabricateUnits() {
  std::vector<Unit *> aux;
  for (int i = 0; i < data.getData(actualUnitFab).factoryRate; ++i) {
    //mejorar
    Position buildPosition(this->centerPosition.getX() + i * 16,
                           this->centerPosition.getY() + this->size);
    aux.push_back(UnitFactory::createUnitDynamic(buildPosition,
                                                 actualUnitFab,
                                                 *owner,
                                                 team));
    owner->addUnit();
  }
  this->timeToBuild = false;
  return aux;
}

void Build::changePlayer(Player *player, Team &team) {
  this->owner = player;
  this->team = team;
  this->actualUnitFab = UnitType::R_GRUNT;
  this->ticksBeforeCreate = this->getSpeedRate();
  this->timeToBuild = false;
}

