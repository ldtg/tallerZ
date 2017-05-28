#ifndef TALLERZ_CAPTURABLEVEHICLE_H
#define TALLERZ_CAPTURABLEVEHICLE_H

#include "Capturable.h"
#include "Vehicle.h"
#include "BuildID.h"
#include "BuildState.h"
class CapturableVehicle : public Capturable {
 private:
  Vehicle &vehicle;
 public:
  explicit CapturableVehicle(Vehicle &vehicle);

  virtual void capture(const UnitID &unitID,
                       Player &newOwner,
                       Team &ownerTeam);
  virtual Position getCapturePosition() const;
  virtual std::map<BuildID, BuildState> getCapturedBuilds() const;
  virtual std::map<UnitID, UnitState> getCapturedUnits() const;
  virtual bool capturerDissapear() const;
  virtual bool isRecapturable() const;
  virtual bool canBeCapturedBy(const UnitID &id) const;


};

#endif //TALLERZ_CAPTURABLEVEHICLE_H
