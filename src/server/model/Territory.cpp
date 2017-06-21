#include "Territory.h"

Territory::Territory(const Position &flagPosition,
                     const std::vector<Build *> &builds,
                     Player *owner,
                     Team team)
    : Capturable(CapturableType::FLAG),
      flagPosition(flagPosition),
      builds(builds),
      owner(owner),
      team(team) {}

void Territory::capture(const UnitID &unitID,
                        Player *newOwner,
                        const Team &ownerTeam) {
  if (owner->getID() != newOwner->getID()) {
    owner->subTerritory();
    newOwner->addTerritory();
    for (Build *build: builds) {
      build->changePlayer(newOwner, ownerTeam);
    }
    owner = newOwner;
  }
}

Position Territory::getCapturePosition() const {
  return flagPosition;
}

std::map<BuildID, BuildState> Territory::getCapturedBuilds() const {
  std::map<BuildID, BuildState> aux;
  for (Build *build:builds) {
    aux.emplace(build->getId(), build->getBuildState());
  }
  return aux;
}

std::map<UnitID, UnitState> Territory::getCapturedUnits() const {
  return std::map<UnitID, UnitState>();
}

CapturableState Territory::getCapturableState() const {
  return CapturableState(owner->getID(), flagPosition);
}

bool Territory::capturerDissapear() const {
  return false;
}

bool Territory::isRecapturable() const {
  return true;
}

bool Territory::canBeCapturedBy(const UnitID &id) const {
  return true;
}
Territory::~Territory() {}
