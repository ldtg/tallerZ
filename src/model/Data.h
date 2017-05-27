#ifndef TALLERZ_DATA_H
#define TALLERZ_DATA_H

#include <cmath>
#include "Weapon.h"
#include "UnitData.h"
#include "TerrainData.h"

struct Data {
 public:
  unsigned short ticksPerSec;
  unsigned long miliSecsPerTick;
  UnitType defaultDriver;
  Weapon bullet;
  Weapon flamethrower;
  Weapon sniperBullet;
  Weapon laser;
  Weapon rocket;
  UnitData grunt;
  UnitData tough;
  UnitData jeep;
  TerrainData land;
  TerrainData water;
  TerrainData lava;
  TerrainData road;

  Data() {
    ticksPerSec = 35;
    miliSecsPerTick = (unsigned long) ((1 / (double) ticksPerSec) * 1000);
    defaultDriver = R_GRUNT;
    bullet.type = WeaponType::BULLET;
    bullet.damage = 2;
    bullet.isExplosive = false;
    bullet.speed = 0; //llega instantaneamente
    rocket.type = WeaponType::ROCKET;
    rocket.damage = 25;
    rocket.isExplosive = true;
    rocket.speed = 13; // 12 es la veloc max del vehiculo mas rapido creo

    grunt.type = UnitType::R_GRUNT;
    grunt.weapon = bullet;
    grunt.ticksUntilFire =
        (unsigned short) std::lround((double) ticksPerSec / 2);
    grunt.health = 60;
    grunt.range = 7;
    grunt.speed = 4;
    grunt.factoryRate = 3;
    grunt.factoryBaseTimeInSec = 575;
    grunt.factoryMinimunTechLevel = 1;

    tough.type = UnitType::R_TOUGH;
    tough.weapon = rocket;
    tough.ticksUntilFire =
        (unsigned short) std::lround((double) ticksPerSec / 2);
    tough.health = 300;
    tough.range = 5;
    tough.speed = 4;
    tough.factoryRate = 2;
    tough.factoryBaseTimeInSec = 742;
    tough.factoryMinimunTechLevel = 2;

    jeep.type = UnitType::V_JEEP;
    jeep.weapon = bullet;
    jeep.ticksUntilFire =
        (unsigned short) std::lround((double) ticksPerSec / 6);
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
