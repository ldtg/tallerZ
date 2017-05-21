/*
#include "gtest/gtest.h"
#include "../../src/view/Vista.h"
#include "../../src/controller/Controller.h"
#include <SDL2/SDL_image.h>
#include <thread>

#include <ctime>
#include <chrono>
#include <ratio>

TEST(VistaTest, Window) {

  */
/* ---------- TERRENOS ---------- *//*


  TerrainData td = {TerrainType::LAND, 1.0};
  Tile tile_1(Position(0, 0), td);
  Tile tile_2(Position(0, 100), td);
  Tile tile_3(Position(0, 200), td);
  Tile tile_4(Position(0, 300), td);

  Tile tile_7(Position(100, 0), td);
  Tile tile_8(Position(100, 100), td);
  Tile tile_9(Position(100, 200), td);
  Tile tile_10(Position(100, 300), td);

  Tile tile_11(Position(200, 0), td);
  Tile tile_12(Position(200, 100), td);
  Tile tile_13(Position(200, 200), td);
  Tile tile_14(Position(200, 300), td);

  Tile tile_15(Position(300, 0), td);
  Tile tile_16(Position(300, 100), td);
  Tile tile_17(Position(300, 200), td);
  Tile tile_18(Position(300, 300), td);

  std::map<Position, Tile> stdmap;

  stdmap.emplace(Position(0, 0), tile_1);
  stdmap.emplace(Position(0, 100), tile_2);
  stdmap.emplace(Position(0, 200), tile_3);
  stdmap.emplace(Position(0, 300), tile_4);

  stdmap.emplace(Position(100, 0), tile_7);
  stdmap.emplace(Position(100, 100), tile_8);
  stdmap.emplace(Position(100, 200), tile_9);
  stdmap.emplace(Position(100, 300), tile_10);

  stdmap.emplace(Position(200, 0), tile_11);
  stdmap.emplace(Position(200, 100), tile_12);
  stdmap.emplace(Position(200, 200), tile_13);
  stdmap.emplace(Position(200, 300), tile_14);

  stdmap.emplace(Position(300, 0), tile_15);
  stdmap.emplace(Position(300, 100), tile_16);
  stdmap.emplace(Position(300, 200), tile_17);
  stdmap.emplace(Position(300, 300), tile_18);

  */
/* ---------- UNIDADES ---------- *//*


  UnitID id(UnitType::R_GRUNT);
  Weapon w = {WeaponType::BULLET, 1, false};
  UnitState us = {100, w, Position(50, 50)};

  std::map<UnitID, UnitState> units;
  units.emplace(id, us);

  */
/* ---------- CREACION MAPA ---------- *//*


  Map myMap(stdmap, 640, 480);
  myMap.setUnits(units);

  Vista vista(myMap);


  //Main loop flag
//  bool quit = false;
  //Event handler
  SDL_Event e;

  Controller controller(vista);

  //While application is running
  while(!vista.quit()) {

    //Handle events on queue
    while( SDL_PollEvent( &e ) != 0 ) {
      controller.handle(&e);
*/
/*
      //User requests quit
      if (e.type == SDL_QUIT) {
        quit = true;
      }
      if (e.type == SDL_MOUSEBUTTONUP) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        std::cout << "(" << x << "," << y << ")" << std::endl;
      }
*//*

    }
    vista.update();
  }
}
*/
