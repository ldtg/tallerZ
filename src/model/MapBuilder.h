#ifndef TALLERZ_MAPBUILDER_H
#define TALLERZ_MAPBUILDER_H

#include "Position.h"
#include "Tile.h"

class MapBuilder {
    private:
        int width;
        int height;
    public:
//        std::map<Position, Tile> build();
        void build(std::map<Position, Tile> &map);
        int getWidht() const;
        int getHeight() const;
};


#endif //TALLERZ_MAPBUILDER_H
