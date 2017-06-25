#ifndef TALLERZ_BUILDDATA_H
#define TALLERZ_BUILDDATA_H

#include <vector>
#include "common/Types/BuildType.h"
#include "common/Types/UnitType.h"
//Contiene los parámetros iniciales para un tipo de edificio.
struct BuildData {
  BuildType type;
  unsigned short health;
  unsigned short size;
};

#endif //TALLERZ_BUILDDATA_H
