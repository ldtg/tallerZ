#ifndef TALLERZ_TERRAINOBJECTSTATE_H
#define TALLERZ_TERRAINOBJECTSTATE_H

#include <common/Map/Position.h>
struct TerrainObjectState {
 public:
  Position centerPosition;
  unsigned short size;
  unsigned short health;
  bool passable;
  TerrainObjectState() {};
  TerrainObjectState(const Position &position,
                     unsigned short size,
                     unsigned short health,
                     bool passable);
  template<class Archive>
  void serialize(Archive &archive) {
    archive(centerPosition, size, health, passable);
  }
};

#endif //TALLERZ_TERRAINOBJECTSTATE_H
