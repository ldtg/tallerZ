//
// Created by darius on 09/05/17.
//

#include "../../src/model/Position.h"
#include "../../src/model/Tile.h"
#include "../../src/storage/Store_map.h"
#include "gtest/gtest.h"

class store_map_tests : public ::testing::Test{
public:
    Position *position;
    Tile *tile;
    std::map<Position, Tile> map;

    store_map_tests() : Test(){
        this->position = new Position(10,20);
        this->tile = new Tile(*this->position,LAVA);
        map[*position] = *tile;
    }

    ~store_map_tests(){
        delete this->position;
        delete this->tile;
    }
};

TEST_F(store_map_tests, test_json_formato){
    Store_map("archivo.json",this->map)();
    EXPECT_EQ(1,1);
}
