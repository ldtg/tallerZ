#ifndef TALLERZ_DATA_H
#define TALLERZ_DATA_H

#include "Weapon.h"
#include "UnitData.h"
#include "TerrainData.h"
struct Data {
 public:
  Weapon bullet;
  Weapon flamethrower;
  Weapon sniperBullet;
  Weapon laser;
  Weapon rocket;
  UnitData grunt;
  TerrainData land;
  TerrainData water;
  TerrainData lava;
  TerrainData road;
  Data() {
    bullet.type = BULLET;
    bullet.damage = 2;
    bullet.isExplosive = false;
    grunt.type = UnitType::R_GRUNT;
    grunt.weapon = bullet;
    grunt.health = 60;
    grunt.range = 7;
    grunt.speed = 4;
    grunt.factoryRate = 3;
    grunt.factoryBaseTimeInSec = 575;
    grunt.factoryMinimunTechLevel = 1;
    land.type = TerrainType::LAND;
    land.terrainFactor = 1;
    water.type = TerrainType::WATER;
    water.terrainFactor = 0.7;
    water.type = TerrainType::ROAD;
    water.terrainFactor = 1.5;
    lava.type = TerrainType::LAVA;
    lava.terrainFactor = 0.1; //no importa el valor
  }
};
extern Data data;
#endif //TALLERZ_DATA_H
