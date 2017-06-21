#ifndef TALLERZ_CAPTURABLEVEHICLE_H
#define TALLERZ_CAPTURABLEVEHICLE_H

#include "Capturable.h"
#include "Vehicle.h"
#include "common/IDs/BuildID.h"
#include "common/States/BuildState.h"

class CapturableVehicle : public Capturable {
 private:
  Vehicle &vehicle;
 public:
  explicit CapturableVehicle(Vehicle &vehicle);

  virtual void capture(const UnitID &unitID,
                       Player *newOwner,
                       const Team &ownerTeam) override;
  virtual Position getCapturePosition() const override;
  virtual std::map<BuildID, BuildState> getCapturedBuilds() const override;
  virtual std::map<UnitID, UnitState> getCapturedUnits() const override;
  virtual CapturableState getCapturableState() const override;
  virtual bool capturerDissapear() const override;
  virtual bool isRecapturable() const override;
  virtual bool canBeCapturedBy(const UnitID &id) const override;
  virtual ~CapturableVehicle();
};

#endif //TALLERZ_CAPTURABLEVEHICLE_H
