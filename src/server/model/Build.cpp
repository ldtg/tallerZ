#include <algorithm>
#include "Build.h"
#include "Data.h"
#include "UnitFactory.h"

Build::Build(const BuildData &buildData,
             const Position &centerPosition,
             Player &owner, const Team &team,
             const unsigned short techLevel)
    : id(buildData.type),
      owner(&owner), team(team),
      centerPosition(centerPosition),
      size(buildData.size),
      techLevel(techLevel),
      fabricableUnits(data.getFabUnits(buildData.type, techLevel)),
      ticksBeforeCreate(this->getSpeedRate()),
      health(buildData.health), actualTicksBeforeCreateBase(ticksBeforeCreate),
      timeToBuild(true),
      actualUnitFab(UnitType::R_GRUNT) {}

void Build::tick() {
  if (ticksBeforeCreate > 0) {
    ticksBeforeCreate--;
    unsigned long aux = this->getSpeedRate();
    if (actualTicksBeforeCreateBase != aux) {
      float
          rel = (float) ticksBeforeCreate / (float) actualTicksBeforeCreateBase;
      unsigned long round = (unsigned long) std::lround(
          rel * (float) aux);
      ticksBeforeCreate = round;
      actualTicksBeforeCreateBase = aux;
    }
  } else if (owner->getAmountOfTerritories() > 0) {
    ticksBeforeCreate = this->getSpeedRate();
    timeToBuild = true;
  }
}

void Build::changeFabUnit(const UnitType &type) {
  if (std::find(fabricableUnits.begin(), fabricableUnits.end(), type)
      != fabricableUnits.end()) {
    this->actualUnitFab = type;
    this->ticksBeforeCreate = this->getSpeedRate();
    this->actualTicksBeforeCreateBase = this->ticksBeforeCreate;
    this->timeToBuild = false;
  }
}

void Build::changePlayer(Player *player, const Team &team) {
  this->owner = player;
  this->team = team;
  if (this->id.getType() == VEHICLEF)
    this->actualUnitFab = UnitType::V_JEEP;
  else
    this->actualUnitFab = UnitType::R_GRUNT;
  this->ticksBeforeCreate = this->getSpeedRate();
  this->actualTicksBeforeCreateBase = this->ticksBeforeCreate;
  this->timeToBuild = false;
}

unsigned long Build::getSpeedRate() const {
  unsigned long timeInSecs;
  float baseTaken = (float) data.getData(actualUnitFab).factoryBaseTimeInSec
      / (float) owner->getAmountOfTerritories();
  float rel =
      1 - ((float) (data.getData(this->id.getType()).health - this->health)
          / (float) data.getData(this->id.getType()).health);
  float relsqrt = std::sqrt(rel);
  timeInSecs = (unsigned long) std::lround(baseTaken / relsqrt);

  return data.getTickAmount(timeInSecs);
}

void Build::receiveDamages() {
  for (auto damage: damagesToReceive) {
    if (this->health > damage) {
      this->health -= damage;
    } else {
      this->health = 0;
      this->ticksBeforeCreate = 0;
      owner->buildDestroyed(this->id.getType());
      damagesToReceive.clear();
      return;
    }
  }
  damagesToReceive.clear();
}

void Build::receiveAttack(const Weapon &weapon) {
  if (weapon.isExplosive)
    this->damagesToReceive.push_back(weapon.damage);
}

std::vector<Unit *> Build::fabricateUnits(const Position &buildPos) {
  std::vector<Unit *> aux;
  if (timeToBuild) {
    for (int i = 0; i < data.getData(actualUnitFab).factoryRate; ++i) {

      aux.push_back(UnitFactory::createUnitDynamic(buildPos.add(i * 15, 0),
                                                   actualUnitFab,
                                                   *owner,
                                                   team));
      owner->addUnit();
    }
  }
  this->timeToBuild = false;
  return aux;
}

Position Build::getCenterPosition() const {
  return centerPosition;
}

Player *Build::getOwner() {
  return owner;
}

Position Build::nextMovePosition() const {
  return centerPosition;
}

Position Build::getAttackPosition(const Position &attackerPosition) const {
  return centerPosition.getAttackPosition(attackerPosition, size + 1);
}

BuildState Build::getBuildState() const {
  return BuildState(owner->getID(),
                    centerPosition.sub(size, size),
                    health,
                    data.ticksToSec(ticksBeforeCreate),
                    actualUnitFab, fabricableUnits);
}

bool Build::isAlive() const {
  return health > 0;
}

bool Build::isMoving() const {
  return false;
}

bool Build::hasToBuild() const {
  return timeToBuild;
}

bool Build::hasDamagesToReceive() const {
  return !damagesToReceive.empty();
}

BuildID Build::getId() const {
  return this->id;
}
Build::~Build() {}

