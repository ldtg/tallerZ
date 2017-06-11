#ifndef TALLERZ_BUILDDATA_H
#define TALLERZ_BUILDDATA_H

#include <vector>
#include "common/Types/BuildType.h"
#include "common/Types/UnitType.h"
struct BuildData {
  BuildType type;
  unsigned short health;
  unsigned short size;
  std::vector<UnitType> fabricableUnits;
};

#endif //TALLERZ_BUILDDATA_H
