#ifndef TALLERZ_TERRITORY_H
#define TALLERZ_TERRITORY_H

#include "common/Map/Position.h"
#include "Player.h"
#include "Build.h"
#include "Capturable.h"

class Territory : public Capturable {
 private:
  std::vector<Build *> builds;
  Position flagPosition;
  Player *owner;
  Team team;
 public:
  Territory(const Position &flagPosition,
            const std::vector<Build *> &builds,
            Player *owner,
            Team team);
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
  virtual ~Territory();
};

#endif //TALLERZ_TERRITORY_H
