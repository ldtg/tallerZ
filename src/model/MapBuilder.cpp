#include "MapBuilder.h"
#include "Land.h"

std::map<Position, Tile> MapBuilder::build() {
    std::map<Position, Tile> map;
    width = 14;
    height = 8;

    for (int x=0; x <= width; x++) {
        for (int y = 0; y <= height; y++) {
            Position pos(x, y);
            ObjectMap *land = new Land("land");
            Tile tile(pos, land);

            map.insert(std::pair<Position, Tile>(pos, tile));
        }
    }

    return std::move(map);
}

int MapBuilder::getWidht() const {
    return width;
}

int MapBuilder::getHeight() const {
    return height;
}
