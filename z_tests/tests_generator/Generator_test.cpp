//
// Created by darius on 26/05/17.
//

#include <gtest/gtest.h>
#include "map_generation/Generator.h"

TEST(Generator_frame_calculation_test,Generator){
  Generator generator(10,12,4);
  assert(generator.frame == 5);
  Generator generator2(9,9,4);
  assert(generator2.frame == 4);
}

TEST(Generator_position_calculation,Generator){
  Generator generator(10,12,9);
  assert(generator.get_position(2,2) == 22);
  assert(generator.get_position(3,3) == 33);
}

TEST(Generator_enmarcado_test,Generator){
  Generator generator(10,12,9);
  assert(generator.esta_encuadrado(0,1,1));
  assert(generator.esta_encuadrado(0,1,2));
  assert(!generator.esta_encuadrado(0,1,3));
  assert(!generator.esta_encuadrado(0,11,2));
}

TEST(Generator_territory_fill,Generator){
  Generator generator(10,12,9);
  int territory = 3;
  int tile_amount = 13;
  int x = 8;
  int y = 2;
  int frame = 3;
  int frame_number = 0;

  assert(generator.fill_territory(0,13,0,0,0).tiles_left == 0);
  assert(generator.fill_territory(0,13,0,0,0).x == 4);
  assert(generator.fill_territory(0,13,0,0,0).y == 1);

  assert(generator.fill_territory(0,13,8,2,0).tiles_left == 9);
  assert(generator.fill_territory(0,13,8,2,0).x == 10);
  assert(generator.fill_territory(0,13,8,2,0).y == 0);
}

TEST(Generator_territory_fill2,Generator){
  Generator generator(10,12,8);

  assert(generator.fill_territory(0,15,0,0,0).tiles_left == 0);
  assert(generator.fill_territory(0,15,0,0,0).x == 5);
  assert(generator.fill_territory(0,15,0,0,0).y == 0);

  assert(generator.fill_territory(1,15,5,0,0).tiles_left == 0);
  assert(generator.fill_territory(1,15,5,0,0).x == 10);
  assert(generator.fill_territory(1,15,5,0,0).y == 0);

}

TEST(Generator_territory_fill_backwards_2,Generator){
  Generator generator(10,12,8);

  assert(generator.fill_territory_backwards(1,15,9,3,1).tiles_left == 0);
  assert(generator.fill_territory_backwards(0,15,9,3,1).x == 4);
  assert(generator.fill_territory_backwards(0,15,9,3,1).y == 3);

  assert(generator.fill_territory_backwards(1,15,4,3,1).tiles_left == 0);
  assert(generator.fill_territory_backwards(1,15,4,3,1).x == -1);
  assert(generator.fill_territory_backwards(1,15,4,3,1).y == 3);

}
TEST(Generator_territory_fill_backwards,Generator){
  int territorios = 9;
  Generator generator(10,12,territorios);
  assert(generator.fill_territory_backwards(1,9,9,3,1).tiles_left == 0);
  //std::cout << generator.fill_territory_backwards(1,9,9,3,1).y << std::endl;
  assert(generator.fill_territory_backwards(1,9,9,3,1).x == 6);
  //std::cout << generator.fill_territory_backwards(1,9,9,3,1).x << std::endl;
  assert(generator.fill_territory_backwards(1,9,9,3,1).y == 3);

  assert(generator.fill_territory_backwards(5,13,2,4,1).tiles_left == 5);
}

TEST(Generator_map_filling,Generator){
  Generator generator(27,42,10);
  for (int i = 0; i < generator.tile_amount; i++){
    generator.map_territories->territory = -1;
  }

  generator.territory_distribution_algorithm();
  for (int j = generator.map_length -1; j > -1; j--){
    for (int i = 0; i < generator.map_width; i++){
      std::cout << generator.map_territories[generator.get_position(i,j)].territory << " ";
    }
    std::cout << '\n';
  }
}
