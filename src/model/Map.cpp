#include "Map.h"
#include "UnitNotFoundException.h"

Map::Map() {}

Map::Map(const std::map<Position, Tile> &map,
         unsigned short width,
         unsigned short height)
    : map(map), width(width), height(height) {}

Map::~Map() {}

std::vector<Tile> Map::getNeighbors(const Tile &tile) const {
  Position tilePosition = tile.getCenterPosition();
  tilePosition.mod(TILEWIDHT, TILEHEIGHT);
  std::vector<Tile> neighborsTiles;
  std::vector<Position> neighborsPos = tilePosition.getNeighbors();
  for (Position &pos : neighborsPos) {
    if (pos.isIn(width, height))
      neighborsTiles.push_back(map.at(pos));
  }
  return neighborsTiles;
}

Tile Map::getTile(const Position &position) const {
  Position pos = position;
  pos.mod(TILEWIDHT, TILEHEIGHT);
  return map.at(pos);
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
  Position actual = positionFrom;
  while (actual != positionTo) {
    actual.move(positionTo);
    if (!this->getTile(actual).isPassable())
      return false;
  }
  return true;
}

int Map::getWidht() const {
  return width;
}

int Map::getHeight() const {
  return height;
}

const std::map<Position, Tile> Map::getMap() const {
  return map;
}

const std::map<UnitID, UnitState> &Map::getUnits() const {
  return units;
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
  for (auto &par : units) {
    if (pos.equalDelta(par.second.position, range))
      return par.first;
  }
  throw UnitNotFoundException();
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

