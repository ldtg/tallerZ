#ifndef TALLERZ_DATATERRAINOBJECTIDEVENT_H
#define TALLERZ_DATATERRAINOBJECTIDEVENT_H

#include <common/IDs/TerrainObjectID.h>
struct dataTerrainObjectIDEvent {
  TerrainObjectID id;
  dataTerrainObjectIDEvent(const TerrainObjectID &id);
  dataTerrainObjectIDEvent();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id);
  }
};

#endif //TALLERZ_DATATERRAINOBJECTIDEVENT_H
