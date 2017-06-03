#include "gtest/gtest.h"
#include "view/View.h"
#include "controller/Controller.h"
#include "model/Events/EventHandler.h"

#include <SDL2/SDL_image.h>
#include <thread>

#include <ctime>
#include <chrono>
#include <ratio>
#include <model/Data.h>
#include <model/UnitFactory.h>
#include <model/GameController.h>
#include <storage/Map_Loader.h>

TEST(VistaTest, Window) {

  try {
/* ---------- TERRENOS ---------- */
    std::map<Position, Tile> stdmap;
    stdmap.emplace(Position(0, 0), Tile(Position(50, 50), data.land));
    stdmap.emplace(Position(1, 0), Tile(Position(150, 50), data.land));
    stdmap.emplace(Position(2, 0), Tile(Position(250, 50), data.land));

    stdmap.emplace(Position(0, 1), Tile(Position(50, 150), data.land));
    stdmap.emplace(Position(1, 1), Tile(Position(150, 150), data.land));
    stdmap.emplace(Position(2, 1), Tile(Position(250, 150), data.land));

    stdmap.emplace(Position(0, 2), Tile(Position(50, 250), data.land));
    stdmap.emplace(Position(1, 2), Tile(Position(150, 250), data.land));
    stdmap.emplace(Position(2, 2), Tile(Position(250, 250), data.land));

/* ---------- EQUIPOS ---------- */
    Player player(PlayerColor::RED);
    Team team;
    team.addPlayer(&player);
//    player.addTerritory();
    Player player2(PlayerColor::BLUE);
    Team team2;
    team2.addPlayer(&player2);

/* ---------- UNIDADES ---------- */
    std::map<UnitID, Unit *> units;

    Unit *robotA;
    robotA = UnitFactory::createGruntDynamic(Position(200, 100), player, team);
    units.emplace(robotA->getId(), robotA);

    Unit *robotB;
    robotB =
        UnitFactory::createGruntDynamic(Position(200, 200), player2, team2);
    units.emplace(robotB->getId(), robotB);

    Unit *vehicle;
    vehicle = UnitFactory::createJeepDynamic(Position(100, 200), player, team);
    units.emplace(vehicle->getId(), vehicle);

/* ---------- EDIFICIOS ---------- */

    Build *build = new Build(data.fort, Position(50, 50), player, team, 3);

    std::map<BuildID, BuildState> buildmap;
    buildmap.emplace(build->getId(), build->getBuildState());

    std::map<BuildID, Build *> builds;
    builds.emplace(build->getId(), build);

/* ---------- CREACION MAPA ---------- */
    Map map(stdmap, buildmap, 3, 3);

    map.addUnit(robotA->getId(), robotA->getUnitState());
    map.addUnit(robotB->getId(), robotB->getUnitState());
    map.addUnit(vehicle->getId(), vehicle->getUnitState());

    GameController gameController(map, units, builds);

    EventHandler eventHandler;

    Model model(map, gameController);
    Window window;
    View view(map, eventHandler, window);

    eventHandler.setView(&view);
    eventHandler.setModel(&model);

    SDL_Event e;

    Controller controller(eventHandler);

    //While application is running
    while (!view.quit()) {

      std::vector<Event *> events = gameController.tick();
      while (SDL_PollEvent(&e) != 0) {
        controller.handle(&e);
      }

      if (!events.empty()) {
        for (auto event : events) {
          eventHandler.add(event);
        }
      }
      view.update();
    }
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

TEST(VistaTest_Usando_Map_Loader, Window){
  Map_Loader map_loader("mapa.json");
  map_loader.load_file();
  map_loader.load_configuration();
  map_loader.set_players();
  map_loader.set_teams();
  map_loader.build_map();
  Map map(map_loader.get_loaded_map(), map_loader.get_buildmap(), 4, 4);

  std::map<UnitID, Unit *> units;
  GameController gameController(map, units, map_loader.get_builds());

  EventHandler eventHandler;

  Model model(map, gameController);
  Window window;
  View view(map, eventHandler, window);

  eventHandler.setView(&view);
  eventHandler.setModel(&model);

  SDL_Event e;

  Controller controller(eventHandler);

  //While application is running
  while (!view.quit()) {

    std::vector<Event *> events = gameController.tick();
    while (SDL_PollEvent(&e) != 0) {
      controller.handle(&e);
    }

    if (!events.empty()) {
      for (auto event : events) {
        eventHandler.add(event);
      }
    }
    view.update();
  }
}
