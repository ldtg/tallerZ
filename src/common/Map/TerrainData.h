#ifndef TALLERZ_TERRAINDATA_H
#define TALLERZ_TERRAINDATA_H

#include "common/Types/TerrainType.h"
struct TerrainData {
  TerrainType type;
  float terrainFactor;
  bool operator==(const TerrainData &other) const {
    return type == other.type && terrainFactor == other.terrainFactor;
  }
  bool operator!=(const TerrainData &other) const {
    return !this->operator==(other);
  }
};

#endif //TALLERZ_TERRAINDATA_H
