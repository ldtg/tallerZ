#ifndef TALLERZ_DATACAPTUREEVENT_H
#define TALLERZ_DATACAPTUREEVENT_H

#include <common/IDs/UnitID.h>
#include <common/IDs/CapturableID.h>
#include <common/Map/Position.h>
#include <common/IDs/BuildID.h>
#include <common/States/BuildState.h>
#include <map>
#include <common/States/UnitState.h>
#include <cereal/types/map.hpp>
struct dataCaptureEvent {
  UnitID capturer;
  CapturableID captured;
  Position capturedPosition;
  std::map<BuildID, BuildState> capturedBuilds;
  std::map<UnitID, UnitState> capturedUnits;
  bool capturerDissapear;
  dataCaptureEvent(const UnitID &capturer,
                   const CapturableID &captured,
                   const Position &capturedPosition,
                   const std::map<BuildID, BuildState> &capturedBuilds,
                   const std::map<UnitID, UnitState> &capturedUnits,
                   bool capturerDissapear);
  dataCaptureEvent();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(capturer,
            captured,
            capturedPosition,
            capturedBuilds,
            capturedUnits,
            capturerDissapear);
  }
};

#endif //TALLERZ_DATACAPTUREEVENT_H
