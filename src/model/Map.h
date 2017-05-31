#ifndef TALLERZ_MAP_H
#define TALLERZ_MAP_H

#include "Position.h"
#include "Tile.h"
#include "Weapon.h"
#include "Unit.h"
#include "BulletState.h"
#include "BuildState.h"
#include "BuildID.h"
#include <vector>
#include <map>
#include <string>

class Map {
 private:
  //guarda los nros de tiles ej: tile 0,0 va de 0<x<100.
  std::map<Position, Tile> map;
  std::map<UnitID, UnitState> units;
  std::map<BulletID, BulletState> bullets;
  std::map<BuildID, BuildState> builds;
  //std::map<Position> flags; no se si va a ir asi
  int width;
  int height;
  Position getTilePositionFromRealPosition(Position position) const;

 public:
  Map();
  //Para mapas de prueba sin edificios
  Map(const std::map<Position, Tile> &map,
      unsigned short width,
      unsigned short height);

  Map(const std::map<Position, Tile> &map,
      const std::map<BuildID, BuildState> &builds,
      unsigned short width,
      unsigned short height);
  ~Map();

  std::vector<Tile> getNeighbors(const Tile &tile) const;

  void addUnit(const UnitID &unitID, const UnitState &unitState);
  void removeUnit(const UnitID &unitID);
  void updateUnit(const UnitID &unitID, const UnitState &unitState);

  void addBullet(const BulletID &bulletID, const BulletState &bulletState);
  void removeBullet(const BulletID &bulletID);
  void updateBullet(const BulletID &bulletID, const BulletState &bulletState);

  void updateBuild(const BuildID &buildID, const BuildState &buildState);

  Tile getTile(const Position &position) const;
  std::pair<UnitID, UnitState> getUnit(const Position &position);
  bool isUnitIn(const Position &position) const;

  // para saber si se puede mover o atacar desde esa posicion
  // hasta la otra (no hay nada en el medio onda estructuras o algo)
  bool canPass(const Position &positionFrom,
               const Position &positionTo) const;

  //Metodos para dibujar mapa
  const std::map<Position, Tile> &getMap() const;
  const std::map<UnitID, UnitState> &getUnits() const;
  const std::map<BuildID, BuildState> &getBuilds() const;

  UnitID getUnitIDFromPosition(const Position &pos, unsigned short range) const;
  BuildID getBuildIDFromPosition(const Position &pos, unsigned short range) const;
  UnitState getUnitState(const UnitID &unitID) const;

  //Para crear el mapa
  void setUnits(const std::map<UnitID, UnitState> &units);
  int getWidht() const;
  int getHeight() const;

};

#endif //TALLERZ_MAP_H
