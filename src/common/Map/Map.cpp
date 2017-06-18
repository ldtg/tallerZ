#include "Map.h"
#include "Exceptions/model_exceptions/UnitNotFoundException.h"

Map::Map() {}

Map::Map(const std::map<Position, Tile> &map,
         unsigned short width,
         unsigned short height)
    : map(map), width(width), height(height) {}

Map::Map(const std::map<Position, Tile> &map,
         const std::map<BuildID, BuildState> &builds,
         const std::map<TerrainObjectID, TerrainObjectState> &terrainObject,
         unsigned short width,
         unsigned short height)
    : map(map),
      builds(builds),
      terrainObject(terrainObject),
      width(width),
      height(height) {
  for (auto &build : builds) {
    Position pos = this->getTilePositionFromRealPosition(build.second.position);
    this->map.at(pos).makeNotPassable();
  }
  for (auto &tobj : terrainObject) {
    Position
        pos = this->getTilePositionFromRealPosition(tobj.second.centerPosition);
    if (!tobj.second.passable)
      this->map.at(pos).makeNotPassable();
  }

}

Map::Map(const std::map<Position, Tile> &map,
         const std::map<BuildID, BuildState> &builds,
         std::map<CapturableID, CapturableState> capturables,
         const std::map<TerrainObjectID, TerrainObjectState> &terrainObject,
         unsigned short width,
         unsigned short height)
    : map(map),
      builds(builds),
      capturables(capturables),
      terrainObject(terrainObject),
      width(width),
      height(height) {

  for (auto &build : builds) {
    Position pos = this->getTilePositionFromRealPosition(build.second.position);
    this->map.at(pos).makeNotPassable();
  }
  for (auto &tobj : terrainObject) {
    Position
        pos = this->getTilePositionFromRealPosition(tobj.second.centerPosition);
    if (!tobj.second.passable)
      this->map.at(pos).makeNotPassable();
  }
}

Map::Map(const std::map<Position, Tile> &map,
         const std::map<BuildID, BuildState> &builds,
         std::map<CapturableID, CapturableState> capturables,
         const std::map<TerrainObjectID, TerrainObjectState> &terrainObject,
         std::map<UnitID, UnitState> units,
         unsigned short width,
         unsigned short height) : map(map),
                                  builds(builds),
                                  capturables(capturables),
                                  terrainObject(terrainObject),
                                  width(width),
                                  height(height),
                                  units(units) {

  for (auto &build : builds) {
    Position pos = this->getTilePositionFromRealPosition(build.second.position);
    this->map.at(pos).makeNotPassable();
  }
  for (auto &tobj : terrainObject) {
    Position
        pos = this->getTilePositionFromRealPosition(tobj.second.centerPosition);
    if (!tobj.second.passable)
      this->map.at(pos).makeNotPassable();
  }
}

Map::Map(const std::map<Position, Tile> &map,
         const std::map<BuildID, BuildState> &builds,
         std::map<CapturableID, CapturableState> capturables,
         unsigned short width,
         unsigned short height) : map(map),
                                  builds(builds),
                                  capturables(capturables),
                                  width(width),
                                  height(height) {
  for (auto &build : builds) {
    Position pos = this->getTilePositionFromRealPosition(build.second.position);
    this->map.at(pos).makeNotPassable();
  }

}

Map::~Map() {}

std::vector<Tile> Map::getNeighbors(const Tile &tile) const {
  Position tilePosition = tile.getCenterPosition();
  tilePosition.mod(TILEWIDHT, TILEHEIGHT);
  std::vector<Tile> neighborsTiles;
  std::vector<Position>
      straighNeighborsPos = tilePosition.getStraighNeighbors();
  std::vector<Position>
      diagonalNeighborsPos = tilePosition.getDiagonalNeighbors();
  for (Position &pos : straighNeighborsPos) {
    if (pos.isIn(width, height)) {
      neighborsTiles.push_back(map.at(pos));
    }
  }
  for (Position &pos : diagonalNeighborsPos) {
    if (pos.isIn(width, height) && diagPassable(tilePosition, pos)) {
      neighborsTiles.push_back(map.at(pos));
    }
  }
  return neighborsTiles;
}

Tile Map::getTile(const Position &position) const {
  return map.at(this->getTilePositionFromRealPosition(position));
}

bool Map::isUnitIn(const Position &position) const {
  for (auto const &unit : units) {
    Position curPos = unit.second.position;
    bool
        in = position.isIn(UNITWIDHT, UNITHEIGHT, curPos.getX(), curPos.getY());
    if (in)
      return true;
  }
  return false;
}

std::pair<UnitID, UnitState> Map::getUnit(const Position &position) {
  for (auto const &unit : units) {
    Position curPos = unit.second.position;
    bool
        in = position.isIn(UNITWIDHT, UNITHEIGHT, curPos.getX(), curPos.getY());
    if (in)
      return unit;
  }
}

bool Map::canPass(const Position &positionFrom,
                  const Position &positionTo) const {
  return this->getTile(positionTo).isPassable();
}

int Map::getWidht() const {
  return width * TILEWIDHT;
}

int Map::getHeight() const {
  return height * TILEHEIGHT;
}

const std::map<Position, Tile> &Map::getMap() const {
  return map;
}

const std::map<UnitID, UnitState> &Map::getUnits() const {
  return units;
}

const std::map<BuildID, BuildState> &Map::getBuilds() const {
  return builds;
}

const std::map<CapturableID, CapturableState> &Map::getCapturables() const {
  return capturables;
}

const std::map<TerrainObjectID,
               TerrainObjectState> &Map::getTerrainObjects() const {
  return terrainObject;
}

void Map::setUnits(const std::map<UnitID, UnitState> &units) {
  Map::units = units;
}

void Map::addUnit(const UnitID &unitID, const UnitState &unitState) {
  units.emplace(unitID, unitState);
}

void Map::removeUnit(const UnitID &unitID) {
  units.erase(unitID);
}

UnitState Map::getUnitState(const UnitID &unitID) const {
  return units.at(unitID);
}

UnitID Map::getUnitIDFromPosition(const Position &pos,
                                  unsigned short range) const {
  std::map<unsigned short, UnitID> aux;
  for (auto &par : units) {
    if (pos.equalDelta(par.second.position, range))
      aux.emplace(pos.chebyshevDistance(par.second.position), par.first);
  }
  if (!aux.empty())
    return aux.begin()->second;
  throw UnitNotFoundException("unidad no encontrada");
}

BuildID Map::getBuildIDFromPosition(const Position &pos,
                                    unsigned short range) const {
  for (auto &par : builds) {
    if (pos.equalDelta(par.second.position.add(range, range), range))
      return par.first;
  }
  throw UnitNotFoundException("edificio no encontrado");
}

CapturableID Map::getCapturableIDFromPosition(const Position &pos,
                                              unsigned short range) const {
  for (auto &par : capturables) {
    if (pos.equalDelta(par.second.pos, range))
      return par.first;
  }
  throw UnitNotFoundException("capturable no encontrado");
}

TerrainObjectID Map::getTerrainObjectIDFromPosition(const Position &pos,
                                                    unsigned short range) const {
  for (auto &par : terrainObject) {
    if (pos.equalDelta(par.second.centerPosition, range))
      return par.first;
  }
  throw UnitNotFoundException("terrainObject no encontrado");
}

void Map::updateUnit(const UnitID &unitID, const UnitState &unitState) {
  this->removeUnit(unitID);
  this->addUnit(unitID, unitState);
}

void Map::addBullet(const BulletID &bulletID, const BulletState &bulletState) {
  bullets.emplace(bulletID, bulletState);
}

void Map::removeBullet(const BulletID &bulletID) {
  bullets.erase(bulletID);
}

void Map::updateBullet(const BulletID &bulletID,
                       const BulletState &bulletState) {
  this->removeBullet(bulletID);
  this->addBullet(bulletID, bulletState);
}

Map::Map(const std::map<Position, Tile> &map,
         const std::map<BuildID, BuildState> &builds,
         unsigned short width,
         unsigned short height)
    : map(map), builds(builds), width(width), height(height) {
  for (auto &build : builds) {
    Position pos = this->getTilePositionFromRealPosition(build.second.position);
    this->map.at(pos).makeNotPassable();
  }

}

void Map::updateBuild(const BuildID &buildID, const BuildState &buildState) {
  this->builds.erase(buildID);
  this->builds.emplace(buildID, buildState);
  if (buildState.health == 0) {
    Tile &tile =
        this->map.at(getTilePositionFromRealPosition(buildState.position));
    tile.makeNotPassable();
  }
}
Position Map::getTilePositionFromRealPosition(Position position) const {
  position.mod(TILEWIDHT, TILEHEIGHT);
  return position;
}
void Map::updateTerrainObject(const TerrainObjectID &id,
                              const TerrainObjectState &newState) {
  terrainObject.erase(id);
  terrainObject.emplace(id, newState);
  if (!newState.passable)
    map.at(this->getTilePositionFromRealPosition(newState.centerPosition)).makeNotPassable();
  else
    map.at(this->getTilePositionFromRealPosition(newState.centerPosition)).makePassable();
}
void Map::updateCapturable(const CapturableID &id,
                           const CapturableState &state) {
  capturables.erase(id);
  capturables.emplace(id, state);

}
void Map::removeCapturable(const CapturableID &id) {
  capturables.erase(id);
}
Position Map::getNeighborFreePos(const Position &tileC) {
  for (Tile &tile : this->getNeighbors(this->getTile(tileC))) {
    if (tile.isPassable()) {
      return tile.getCenterPosition();
    }
  }
}
bool Map::diagPassable(const Position &center, const Position &diag) const {
  std::vector<Position> diagNeigh = center.getNeighborsOfDiagonal(diag);
  bool passable = true;
  for (Position &pDiag : diagNeigh) {
    if (!map.at(pDiag).isPassable())
      passable = false;
  }
  return passable;
}


BuildState Map::getBuildState(const BuildID &buildID) const {
  return builds.at(buildID);
}

BulletState Map::getBulletState(const BulletID &bulletID) const {
  return bullets.at(bulletID);
}

void Map::removeTerrainObject(const TerrainObjectID &id) {
  terrainObject.erase(id);
}
Position Map::getFortPos(const PlayerID &id) {
  for (auto &par :builds) {
    if (par.second.owner == id && par.first.getType() == BuildType::FORT) {
      return par.second.position;
    }
  }
}

