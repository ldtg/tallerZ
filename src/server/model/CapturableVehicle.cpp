#include "CapturableVehicle.h"

CapturableVehicle::CapturableVehicle(Vehicle &vehicle)
    : Capturable(CapturableType::UNIT), vehicle(vehicle) {}

void CapturableVehicle::capture(const UnitID &unitID,
                                Player *newOwner,
                                const Team &ownerTeam) {
  vehicle.changeOwner(newOwner, ownerTeam, unitID.getType());
}

Position CapturableVehicle::getCapturePosition() const {
  return vehicle.getCenterPosition();
}

std::map<BuildID, BuildState> CapturableVehicle::getCapturedBuilds() const {
  return std::map<BuildID, BuildState>();
}

std::map<UnitID, UnitState> CapturableVehicle::getCapturedUnits() const {
  std::map<UnitID, UnitState> aux;
  aux.emplace(vehicle.getId(), vehicle.getUnitState());
  return aux;
}

CapturableState CapturableVehicle::getCapturableState() const {
  return CapturableState(vehicle.getOwner()->getID(),
                         vehicle.getCenterPosition());
}

bool CapturableVehicle::capturerDissapear() const {
  return true;
}

bool CapturableVehicle::isRecapturable() const {
  return false;
}

bool CapturableVehicle::canBeCapturedBy(const UnitID &id) const {
  switch (id.getType()) {
    case UnitType::R_GRUNT: return true;
    case UnitType::R_TOUGH: return true;
    case UnitType::R_LASER: return true;
    case UnitType::R_PSYCHO: return true;
    case UnitType::R_PYRO: return true;
    case UnitType::R_SNIPER: return true;
    default:return false;
  }
}

CapturableVehicle::~CapturableVehicle() {}
