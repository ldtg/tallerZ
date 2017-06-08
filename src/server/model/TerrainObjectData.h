#ifndef TALLERZ_TERRAINOBJECTDATA_H
#define TALLERZ_TERRAINOBJECTDATA_H

#include "common/Types/TerrainObjectType.h"
struct TerrainObjectData {
  TerrainObjectType type;
  unsigned short health;
  unsigned short size;
  bool passable;
};

#endif //TALLERZ_TERRAINOBJECTDATA_H
