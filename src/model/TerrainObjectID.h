#ifndef TALLERZ_TERRAINOBJECTID_H
#define TALLERZ_TERRAINOBJECTID_H

#include "TerrainObjectType.h"
class TerrainObjectID {
  static unsigned long nextid;
 private:
  const TerrainObjectType type;
  const unsigned long id;
 public:
  explicit TerrainObjectID(const TerrainObjectType &type);
  bool operator<(const TerrainObjectID &other) const;
  bool operator==(const TerrainObjectID &other) const;
  bool operator!=(const TerrainObjectID &other) const;
  TerrainObjectType getType() const;
};

#endif //TALLERZ_TERRAINOBJECTID_H
