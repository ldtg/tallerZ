#include "TerrainObjectID.h"
unsigned long TerrainObjectID::nextid = 0;

TerrainObjectID::TerrainObjectID(const TerrainObjectType &type)
    : id(nextid), type(type) {
  nextid++;
}

bool TerrainObjectID::operator<(const TerrainObjectID &other) const {
  return this->id < other.id;
}
bool TerrainObjectID::operator==(const TerrainObjectID &other) const {
  return this->id == other.id;
}
bool TerrainObjectID::operator!=(const TerrainObjectID &other) const {
  return !this->operator==(other);
}
TerrainObjectType TerrainObjectID::getType() const {
  return type;
}
TerrainObjectID::TerrainObjectID() {}
