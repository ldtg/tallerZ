//
// Created by darius on 26/05/17.
//

#include <gtest/gtest.h>
#include <random>
#include "map_generation/Generator.h"

TEST(Generator_frame_calculation_test,Generator){
  Generator generator(10,12,4,0,WINTER,20,3);
  assert(generator.frame == 5);
  Generator generator2(9,9,4,0,WINTER,20,3);
  assert(generator2.frame == 4);
}

TEST(Generator_position_calculation,Generator){
  Generator generator(10,12,9,0,WINTER,20,3);
  assert(generator.get_position(2,2) == 22);
  assert(generator.get_position(3,3) == 33);
}

TEST(Generator_enmarcado_test,Generator){
  Generator generator(10,12,9,0,WINTER,20,3);
  assert(generator.esta_encuadrado(0,1,1));
  assert(generator.esta_encuadrado(0,1,2));
  assert(!generator.esta_encuadrado(0,1,3));
  assert(!generator.esta_encuadrado(0,11,2));
}

TEST(Generator_territory_fill,Generator){
  Generator generator(10,12,9,0,WINTER,20,3);
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
  Generator generator(10,12,8,0,WINTER,20,3);

  assert(generator.fill_territory(0,15,0,0,0).tiles_left == 0);
  assert(generator.fill_territory(0,15,0,0,0).x == 5);
  assert(generator.fill_territory(0,15,0,0,0).y == 0);

  assert(generator.fill_territory(1,15,5,0,0).tiles_left == 0);
  assert(generator.fill_territory(1,15,5,0,0).x == 10);
  assert(generator.fill_territory(1,15,5,0,0).y == 0);

}

TEST(Generator_territory_fill_backwards_2,Generator){
  Generator generator(10,12,8,0,WINTER,20,3);

  assert(generator.fill_territory_backwards(1,15,9,3,1).tiles_left == 0);
  assert(generator.fill_territory_backwards(0,15,9,3,1).x == 4);
  assert(generator.fill_territory_backwards(0,15,9,3,1).y == 3);

  assert(generator.fill_territory_backwards(1,15,4,3,1).tiles_left == 0);
  assert(generator.fill_territory_backwards(1,15,4,3,1).x == -1);
  assert(generator.fill_territory_backwards(1,15,4,3,1).y == 3);

}
TEST(Generator_territory_fill_backwards,Generator){
  int territorios = 9;
  Generator generator(10,12,territorios,0,WINTER,20,3);
  assert(generator.fill_territory_backwards(1,9,9,3,1).tiles_left == 0);
  //std::cout << generator.fill_territory_backwards(1,9,9,3,1).y << std::endl;
  assert(generator.fill_territory_backwards(1,9,9,3,1).x == 6);
  //std::cout << generator.fill_territory_backwards(1,9,9,3,1).x << std::endl;
  assert(generator.fill_territory_backwards(1,9,9,3,1).y == 3);

  assert(generator.fill_territory_backwards(5,13,2,4,1).tiles_left == 5);
}

TEST(Generator_map_filling,Generator){
  Generator generator(15,15,7,0,WINTER,20,3);
  for (int i = 0; i < generator.tile_amount; i++){
    generator.map_positions->territory = -1;
  }

  generator.territory_distribution_algorithm();
  for (int j = generator.map_length -1; j > -1; j--){
    for (int i = 0; i < generator.map_width; i++){
      std::cout << generator.map_positions[generator.get_position(i,j)].territory << " ";
    }
    std::cout << '\n';
  }
}

//https://en.wikipedia.org/wiki/ANSI_escape_code
TEST(Generator_put_fort_randomly_in_territory,Generator){
  std::cout << "Generator\n";
  Generator generator(20,20,9,4,WINTER,20,3);
  std::cout << "Territory_distribution_algorithm\n";
  generator.territory_distribution_algorithm();
  std::cout << "Building_distribution_algorithm\n";
  generator.building_distribution_algorithm();
  int pos;
  std::cout << "\033[1;31mbold red text\033[0m\n";
  for (int j = generator.map_length -1; j > -1; j--){
    for (int i = 0; i < generator.map_width; i++){
      pos = generator.get_position(i,j);
      if(generator.map_positions[pos].fort){
        std::cout << "\033[1;31mF\033[0m" << " ";
      } else {
        if (generator.map_positions[pos].robot_factory){
          std::cout << "\033[1;32mf\033[0m" << " ";
        } else {
          if (generator.map_positions[pos].flag){
            std::cout << "\033[1;33mX\033[0m" << " ";
          } else {
            std::cout << generator.map_positions[generator.get_position(i,j)].territory << " ";
          }
        }
      }
    }
    std::cout << '\n';
  }

  for (auto i : generator.vertices){
    std::cout << "x : " << i.x << " y : " << i.y << '\n';
  }
}

TEST(trace_path_test_Generator_Test,Generator){
  Generator generator(40,40,9,4,WINTER,20,3);
  generator.territory_distribution_algorithm();
  generator.building_distribution_algorithm();
  generator.trace_paths();
  //generator.draw_line(generator.vertices[0],generator.vertices[1]);
  int pos;
  std::cout << "\033[1;31mbold red text\033[0m\n";
  for (int j = generator.map_length -1; j > -1; j--){
    for (int i = 0; i < generator.map_width; i++){
      pos = generator.get_position(i,j);
      if(generator.map_positions[pos].fort){
        std::cout << "\033[1;31mF\033[0m" << " ";
      } else {
        if (generator.map_positions[pos].robot_factory){
          std::cout << "\033[1;32mf\033[0m" << " ";
        } else {
          if (generator.map_positions[pos].flag){
            std::cout << "\033[1;33mX\033[0m" << " ";
          } else {
            if (generator.map_positions[pos].terrain_type == TerrainType ::ROAD){
              std::cout << "\033[1;31mc\033[0m" << " ";
            } else {
              std::cout << generator.map_positions[generator.get_position(i,j)].territory << " ";

            }
          }
        }
      }
    }
    std::cout << '\n';
  }
}

TEST(draw_rivers_test,Generator){
  Generator generator(40,40,9,4,WINTER,20,3);
  generator.set_water_lava_percentages(80,20);
  generator.territory_distribution_algorithm();
  generator.building_distribution_algorithm();
  generator.trace_paths();
  generator.trace_rivers();
  int pos;
  std::cout << "\033[1;31mbold red text\033[0m\n";
  for (int j = generator.map_length -1; j > -1; j--){
    for (int i = 0; i < generator.map_width; i++){
      pos = generator.get_position(i,j);
      if(generator.map_positions[pos].fort){
        std::cout << "\033[1;31mF\033[0m" << " ";
      } else {
        if (generator.map_positions[pos].robot_factory){
          std::cout << "\033[1;32mf\033[0m" << " ";
        } else {
          if (generator.map_positions[pos].flag){
            std::cout << "\033[1;33mX\033[0m" << " ";
          } else {
            if (generator.map_positions[pos].terrain_type == TerrainType ::ROAD){
              std::cout << "\033[1;31mc\033[0m" << " ";
            } else {
              if (generator.map_positions[pos].terrain_type == TerrainType ::WATER){
                std::cout << "\033[1;34mw\033[0m" << " ";
              } else {
                if (generator.map_positions[pos].bridge){
                  std::cout << "\033[1;36mB\033[0m" << " ";
                } else {
                  std::cout << generator.map_positions[pos].terrain_type << " ";
                }
              }
            }
          }
        }
      }
    }
    std::cout << '\n';
  }
}

TEST(put_rocks_test,Generator){
  Generator generator(40,40,9,4,WINTER,20,3);
  generator.set_water_lava_percentages(80,20);
  generator.territory_distribution_algorithm();
  generator.building_distribution_algorithm();
  generator.trace_paths();
  generator.trace_rivers();
  generator.put_rocks();
  int pos;
  std::cout << "\033[1;31mbold red text\033[0m\n";
  for (int j = generator.map_length -1; j > -1; j--){
    for (int i = 0; i < generator.map_width; i++){
      pos = generator.get_position(i,j);
      if(generator.map_positions[pos].fort){
        std::cout << "\033[1;31mF\033[0m" << " ";
      } else {
        if (generator.map_positions[pos].robot_factory){
          std::cout << "\033[1;32mf\033[0m" << " ";
        } else {
          if (generator.map_positions[pos].flag){
            std::cout << "\033[1;33mX\033[0m" << " ";
          } else {
            if (generator.map_positions[pos].terrain_type == TerrainType ::ROAD){
              std::cout << "\033[1;31mc\033[0m" << " ";
            } else {
              if (generator.map_positions[pos].terrain_type == TerrainType ::WATER){
                std::cout << "\033[1;34mw\033[0m" << " ";
              } else {
                if (generator.map_positions[pos].bridge){
                  std::cout << "\033[1;36mB\033[0m" << " ";
                } else {
                  if (generator.map_positions[pos].rock){
                    std::cout << "\033[1;40mR\033[0m" << " ";
                  } else {
                    std::cout << generator.map_positions[pos].terrain_type << " ";
                  }
                }
              }
            }
          }
        }
      }
    }
    std::cout << '\n';
  }
}

TEST(put_vehicles_test,Generator){
  Generator generator(12,12,9,4,DUSTY,0,3);
  generator.set_water_lava_percentages(0,0);
  generator.territory_distribution_algorithm();
  generator.building_distribution_algorithm();
  generator.trace_paths();
  //generator.trace_rivers();
  //generator.set_rocks_percentages(0,0);
  //generator.put_rocks();
  //generator.put_vehicles();
  int pos;
  std::cout << "\033[1;31mbold red text\033[0m\n";
  for (int j = generator.map_length -1; j > -1; j--){
    for (int i = 0; i < generator.map_width; i++){
      pos = generator.get_position(i,j);
      if(generator.map_positions[pos].fort){
        std::cout << "\033[1;31mF\033[0m" << " ";
      } else {
        if (generator.map_positions[pos].robot_factory){
          std::cout << "\033[1;32mf\033[0m" << " ";
        } else {
          if (generator.map_positions[pos].vehicle_factory){
            std::cout << "\033[1;32mq\033[0m" << " ";
          } else {
            if (generator.map_positions[pos].flag){
              std::cout << "\033[1;33mX\033[0m" << " ";
            } else {
              if (generator.map_positions[pos].bridge){
                std::cout << "\033[1;36mB\033[0m" << " ";
              } else {
                if (generator.map_positions[pos].terrain_type == TerrainType ::LAVA){
                  std::cout << "\033[1;34mw\033[0m" << " ";
                } else {
                  if (generator.map_positions[pos].terrain_type == TerrainType ::ROAD){
                    std::cout << "\033[1;31mc\033[0m" << " ";
                  } else {
                    if (generator.map_positions[pos].rock){
                      std::cout << "\033[1;40mR\033[0m" << " ";
                    } else {
                      if (generator.map_positions[pos].vehicle){
                        std::cout << "\033[1;41mV\033[0m" << " ";
                      } else {
                        std::cout << generator.map_positions[pos].territory<< " ";
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    std::cout << '\n';
  }
}
TEST(calc_water_or_lava_tile_amount,Generator){
  Generator generator(40,40,9,4,WINTER,20,3);
  std::cout << generator.tile_amount << std::endl;
  generator.territory_distribution_algorithm();
  std::cout << generator.calc_tile_amount(10, 80) << std::endl;
}

TEST(Put_flag,Position){

  Position pos = Position(0,0);
  std::vector<Position> neighbors = pos.getNeighbors();
  std::vector<Position>::iterator it;
  for (it = neighbors.begin(); it != neighbors.end(); it++){
    std::cerr << "x: " << it->getX() << " y: " << it->getY() << "\n";
  }

}























TEST(random_generator,Generator){
  double dice_roll;
  for (int i = 0; i< 10; i++){
    dice_roll = ((double)rand()/RAND_MAX);
    std::cout << dice_roll<< std::endl;
  }
}