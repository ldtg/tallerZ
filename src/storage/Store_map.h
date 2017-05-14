#ifndef TALLERZ_MAP_STORAGE_H
#define TALLERZ_MAP_STORAGE_H

#include <map>
#include <tuple>
#include <iostream>
#include "../../json/src/json.hpp"
#include "../model/Position.h"
#include "../model/Tile.h"

using json = nlohmann::json;

class Store_map {
private:
    std::string file_name;
    std::map<Position,Tile>& map;
    json j;

public:
    /*
     * { position : {int x, int y} , terrain_type : LAVA , empty : true }
     */
    Store_map(std::string file_name, std::map<Position,Tile>& map) :
            file_name(file_name) , map(map) {}

    void operator()(){
        coordinates_t coord;
        for (auto a : this->map){
            coord = a.first.getCoordinates();
            j["position"] = { std::get<0>(coord), std::get<1>(coord)};
            j["terrain_type"] = a.second.getTerrainType();
            j["empty"] = a.second.isEmpty();
        }
        std::cout << j << std::endl;
    }
};


#endif //TALLERZ_MAP_STORAGE_H
