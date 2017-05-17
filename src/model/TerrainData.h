#ifndef TALLERZ_TERRAINDATA_H
#define TALLERZ_TERRAINDATA_H

#include "TerrainType.h"
struct TerrainData {
  TerrainType type;
  float terrainFactor;
  bool operator==(const TerrainData &other) const{
    return type == other.type && terrainFactor == other.terrainFactor;
  }
};

#endif //TALLERZ_TERRAINDATA_H
