#ifndef TALLERZ_TERRAINOBJECTID_H
#define TALLERZ_TERRAINOBJECTID_H

#include <common/Types/TerrainObjectType.h>
class TerrainObjectID {
  static unsigned long nextid;
 private:
  TerrainObjectType type;
  unsigned long id;
 public:
  explicit TerrainObjectID(const TerrainObjectType &type);
  TerrainObjectID();
  bool operator<(const TerrainObjectID &other) const;
  bool operator==(const TerrainObjectID &other) const;
  bool operator!=(const TerrainObjectID &other) const;
  TerrainObjectType getType() const;
  unsigned long getID() {return id;}

  template<class Archive>
  void serialize(Archive &archive) {
    archive(type, id);
  }
};

#endif //TALLERZ_TERRAINOBJECTID_H
