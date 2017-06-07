#ifndef TALLERZ_CAPTURABLE_H
#define TALLERZ_CAPTURABLE_H

#include "Team.h"
#include "common/IDs/UnitID.h"
#include "common/IDs/BuildID.h"
#include "common/States/BuildState.h"
#include "common/States/UnitState.h"
#include "common/States/CapturableState.h"
#include "common/IDs/CapturableID.h"

class Capturable {
 protected:
  CapturableID id;
  Capturable(const CapturableType &type);
 public:
  virtual void capture(const UnitID &unitID,
                       Player *newOwner, const
                       Team &ownerTeam) = 0;
  virtual Position getCapturePosition() const = 0;
  virtual std::map<BuildID, BuildState> getCapturedBuilds() const = 0;
  virtual std::map<UnitID, UnitState> getCapturedUnits() const = 0;
  virtual bool capturerDissapear() const = 0;
  virtual bool isRecapturable() const = 0;
  virtual bool canBeCapturedBy(const UnitID &id) const = 0;
  virtual CapturableState getCapturableState() const = 0;
  virtual CapturableID getID() const;
};

#endif //TALLERZ_CAPTURABLE_H
