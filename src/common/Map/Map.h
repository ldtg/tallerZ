#ifndef TALLERZ_MAP_H
#define TALLERZ_MAP_H

#include <cereal/types/map.hpp>
#include <common/IDs/BulletID.h>
#include <common/States/BulletState.h>
#include <common/IDs/BuildID.h>
#include <common/States/BuildState.h>
#include <common/IDs/TerrainObjectID.h>
#include <common/States/TerrainObjectState.h>
#include <common/IDs/CapturableID.h>
#include <common/States/CapturableState.h>
#include "Tile.h"

class Map {
 private:
  //guarda los nros de tiles ej: tile (0,0) va de 0<x<100.
  std::map<Position, Tile> map;
  std::map<UnitID, UnitState> units;
  std::map<BulletID, BulletState> bullets;
  std::map<BuildID, BuildState> builds;
  std::map<TerrainObjectID, TerrainObjectState> terrainObject;
  std::map<CapturableID, CapturableState> capturables;
  int width;
  int height;

  Position getTilePositionFromRealPosition(Position position) const;
  bool diagPassable(const Position &center, const Position &diag) const;

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

  Map(const std::map<Position, Tile> &map,
      const std::map<BuildID, BuildState> &builds,
      std::map<CapturableID, CapturableState> capturables,
      unsigned short width,
      unsigned short height);

  Map(const std::map<Position, Tile> &map,
      const std::map<BuildID, BuildState> &builds,
      const std::map<TerrainObjectID, TerrainObjectState> &terrainObject,
      unsigned short width,
      unsigned short height);

  Map(const std::map<Position, Tile> &map,
      const std::map<BuildID, BuildState> &builds,
      std::map<CapturableID, CapturableState> capturables,
      const std::map<TerrainObjectID, TerrainObjectState> &terrainObject,
      unsigned short width,
      unsigned short height);

  Map(const std::map<Position, Tile> &map,
      const std::map<BuildID, BuildState> &builds,
      std::map<CapturableID, CapturableState> capturables,
      const std::map<TerrainObjectID, TerrainObjectState> &terrainObject,
      std::map<UnitID, UnitState> units,
      unsigned short width,
      unsigned short height); //El que usa Game_Loader

  ~Map();

  std::vector<Tile> getNeighbors(const Tile &tile) const;

  void addUnit(const UnitID &unitID, const UnitState &unitState);
  void removeUnit(const UnitID &unitID);
  void updateUnit(const UnitID &unitID, const UnitState &unitState);

  void addBullet(const BulletID &bulletID, const BulletState &bulletState);
  void removeBullet(const BulletID &bulletID);
  void updateBullet(const BulletID &bulletID, const BulletState &bulletState);

  void updateBuild(const BuildID &buildID, const BuildState &buildState);

  void updateTerrainObject(const TerrainObjectID &id,
                           const TerrainObjectState &newState);
  void removeTerrainObject(const TerrainObjectID &id);

  void updateCapturable(const CapturableID &id, const CapturableState &state);
  void removeCapturable(const CapturableID &id);

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
  const std::map<CapturableID, CapturableState> &getCapturables() const;

  const std::map<TerrainObjectID,
                 TerrainObjectState> &getTerrainObjects() const;

  UnitID getUnitIDFromPosition(const Position &pos, unsigned short range) const;
  BuildID getBuildIDFromPosition(const Position &pos,
                                 unsigned short range) const;
  CapturableID getCapturableIDFromPosition(const Position &pos,
                                           unsigned short range) const;
  TerrainObjectID getTerrainObjectIDFromPosition(const Position &pos,
                                                 unsigned short range) const;


  UnitState getUnitState(const UnitID &unitID) const;
  BuildState getBuildState(const BuildID &buildID) const;
  BulletState getBulletState(const BulletID &bulletID) const;
  Position getNeighborFreePos(const Position &tileCenterPos);
  //Para crear el mapa
  void setUnits(const std::map<UnitID, UnitState> &units);
  int getWidht() const;
  int getHeight() const;
  template<class Archive>
  void serialize(Archive &archive) {
    archive(map,
            units,
            bullets,
            builds,
            terrainObject,
            capturables,
            width,
            height);
  }
  Position getFortPos(const PlayerID &id);
};

#endif //TALLERZ_MAP_H
