#ifndef TALLERZ_CAPTURABLE_H
#define TALLERZ_CAPTURABLE_H

#include "Team.h"
#include "UnitID.h"
#include "BuildID.h"
#include "BuildState.h"
#include "UnitState.h"

class Capturable {
 public:
  virtual void capture(const UnitID &unitID,
                       Player &newOwner,
                       Team &ownerTeam) = 0;
  virtual Position getCapturePosition() const = 0;
  virtual std::map<BuildID, BuildState> getCapturedBuilds() const = 0;
  virtual std::map<UnitID, UnitState> getCapturedUnits() const = 0;
  virtual bool capturerDissapear() const = 0;
  virtual bool isRecapturable() const = 0;
  virtual bool canBeCapturedBy(const UnitID &id) const = 0;
};

#endif //TALLERZ_CAPTURABLE_H
