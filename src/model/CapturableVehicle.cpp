#include "CapturableVehicle.h"
CapturableVehicle::CapturableVehicle(Vehicle &vehicle)
    : vehicle(vehicle) {
}
void CapturableVehicle::capture(const UnitID &unitID,
                                Player &newOwner,
                                Team &ownerTeam) {
  vehicle.capture(newOwner, ownerTeam, unitID.getType());
}
Position CapturableVehicle::getCapturePosition() const {
  return vehicle.getCurrentPosition();
}
std::map<BuildID, BuildState> CapturableVehicle::getCapturedBuilds() const {
  return std::map<BuildID, BuildState>();
}
std::map<UnitID, UnitState> CapturableVehicle::getCapturedUnits() const {
  std::map<UnitID, UnitState> aux;
  aux.emplace(vehicle.getId(), vehicle.getUnitState());
  return aux;
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
    default:return false;
  }
}
