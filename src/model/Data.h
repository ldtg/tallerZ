#ifndef TALLERZ_DATA_H
#define TALLERZ_DATA_H

#include <cmath>
#include "Weapon.h"
#include "UnitData.h"
#include "TerrainData.h"
struct Data {
 public:
  double ticksPerSec;
  long miliSecsPerTick;
  Weapon bullet;
  Weapon flamethrower;
  Weapon sniperBullet;
  Weapon laser;
  Weapon rocket;
  UnitData grunt;
  UnitData jeep;
  TerrainData land;
  TerrainData water;
  TerrainData lava;
  TerrainData road;
  Data() {
    ticksPerSec = 120;
    miliSecsPerTick = (long) ((1 / ticksPerSec) * 1000);

    bullet.type = BULLET;
    bullet.damage = 2;
    bullet.isExplosive = false;

    grunt.type = UnitType::R_GRUNT;
    grunt.weapon = bullet;
    grunt.fireRatePerSec = 2;
    grunt.health = 60;
    grunt.range = 7;
    grunt.speed = 4;
    grunt.factoryRate = 3;
    grunt.factoryBaseTimeInSec = 575;
    grunt.factoryMinimunTechLevel = 1;

    jeep.type = UnitType::V_JEEP;
    jeep.weapon = bullet;
    jeep.fireRatePerSec = 6;
    jeep.health = 60;
    jeep.range = 6;
    jeep.speed = 8;
    jeep.factoryRate = 1;
    jeep.factoryBaseTimeInSec = 660;
    jeep.factoryMinimunTechLevel = 1;

    land.type = TerrainType::LAND;
    land.terrainFactor = 1;
    water.type = TerrainType::WATER;
    water.terrainFactor = 0.7;
    road.type = TerrainType::ROAD;
    road.terrainFactor = 1.5;
    lava.type = TerrainType::LAVA;
    lava.terrainFactor = 0.1; //no importa el valor
  }
  UnitData getData(UnitType type) {
    switch (type) {
      case R_GRUNT:return grunt;
      case V_JEEP:return jeep;
    }
  }
};
extern Data data;
#endif //TALLERZ_DATA_H
