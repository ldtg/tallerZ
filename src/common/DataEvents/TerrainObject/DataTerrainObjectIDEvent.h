#ifndef TALLERZ_DATATERRAINOBJECTIDEVENT_H
#define TALLERZ_DATATERRAINOBJECTIDEVENT_H

#include <common/IDs/TerrainObjectID.h>
struct DataTerrainObjectIDEvent {
  TerrainObjectID id;
  DataTerrainObjectIDEvent(const TerrainObjectID &id);
  DataTerrainObjectIDEvent();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id);
  }
};

#endif //TALLERZ_DATATERRAINOBJECTIDEVENT_H
