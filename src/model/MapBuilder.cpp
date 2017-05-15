#include "MapBuilder.h"
#include "Land.h"
#include "Grunt.h"
#include <iostream>
#include <utility>

std::map<Position, Tile> MapBuilder::build() {
    std::map<Position, Tile> map;
    width = 14;
    height = 8;


    for (int x=0; x <= width; x++) {
        for (int y = 0; y <= height; y++) {
            Position pos(x, y);
            ObjectMap *land = new Land("land");
            Tile tile(pos, land, NULL);
            map.insert(std::pair<Position, Tile>(pos, tile));
        }
    }

/*
    Position pos1(0, 0);
    ObjectMap *land1 = new Land("land");
//    ObjectMap *grunt1 = new Grunt("grunt");
    Tile tile1(pos1, land1, NULL);

    map.insert(std::pair<Position, Tile>(pos1, tile1));
*/
    return std::move(map);
}

int MapBuilder::getWidht() const {
    return width;
}

int MapBuilder::getHeight() const {
    return height;
}
