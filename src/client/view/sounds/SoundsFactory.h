#ifndef TALLERZ_CLIENTE_SOUNDSFACTORY_H
#define TALLERZ_CLIENTE_SOUNDSFACTORY_H

#include <common/Types/WeaponType.h>
#include <common/Types/UnitType.h>
#include <common/Types/CapturableType.h>
#include <common/Types/BuildType.h>
#include "Sound.h"

class SoundsFactory {
 public:
  static Sound *getBulletFireSound(WeaponType type);
  static Sound *getBulletHitSound(WeaponType type);
  static Sound *getUnitCreateSound(UnitType type);
  static Sound *getCapturedSound(CapturableType type);
  static Sound *getBuildDestroyedSound();
  static Sound *getTargetDestroyedSound();
};

#endif //TALLERZ_CLIENTE_SOUNDSFACTORY_H
