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
#include <controller/MouseState.h>
#include <model/CapturableVehicle.h>
#include <model/GaiaPlayer.h>
#include <model/Territory.h>

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

    stdmap.emplace(Position(3, 0), Tile(Position(350, 50), data.lava));
    stdmap.emplace(Position(3, 1), Tile(Position(350, 150), data.lava));
    stdmap.emplace(Position(3, 2), Tile(Position(350, 250), data.lava));
    stdmap.emplace(Position(3, 3), Tile(Position(350, 350), data.lava));

    stdmap.emplace(Position(0, 3), Tile(Position(50, 350), data.land));
    stdmap.emplace(Position(1, 3), Tile(Position(150, 350), data.lava));
    stdmap.emplace(Position(2, 3), Tile(Position(250, 350), data.lava));

    stdmap.emplace(Position(0, 4), Tile(Position(50, 450), data.land));
    stdmap.emplace(Position(1, 4), Tile(Position(150, 450), data.land));
    stdmap.emplace(Position(2, 4), Tile(Position(250, 450), data.land));
    stdmap.emplace(Position(3, 4), Tile(Position(350, 450), data.land));
    stdmap.emplace(Position(4, 4), Tile(Position(450, 450), data.land));

    stdmap.emplace(Position(4, 0), Tile(Position(450, 50), data.land));
    stdmap.emplace(Position(4, 1), Tile(Position(450, 150), data.land));
    stdmap.emplace(Position(4, 2), Tile(Position(450, 250), data.land));
    stdmap.emplace(Position(4, 3), Tile(Position(450, 350), data.land));
    stdmap.emplace(Position(4, 4), Tile(Position(450, 450), data.land));

/* ---------- EQUIPOS ---------- */
    Player player(BLUE);
    Team team;
    team.addPlayer(&player);
//    player.addTerritory();

    Player player2(RED);
    Team team2;
    team2.addPlayer(&player2);

    GaiaPlayer gaia;
    team2.addPlayer(&gaia);

/* ---------- UNIDADES ---------- */
    std::map<UnitID, Unit *> units;

    Unit *robotA;
    robotA = UnitFactory::createGruntDynamic(Position(200, 100), player, team);
    units.emplace(robotA->getId(), robotA);

    Unit *robotB;
    robotB =
        UnitFactory::createGruntDynamic(Position(200, 200), player2, team2);
    units.emplace(robotB->getId(), robotB);

    Unit *robotC;
    robotC = UnitFactory::createToughDynamic(Position(100, 100), player2, team2);
    units.emplace(robotC->getId(), robotC);

    Unit *robotD;
    robotD = UnitFactory::createUnitDynamic(Position(50, 300), R_PYRO, player, team);
    units.emplace(robotD->getId(), robotD);

    Vehicle *vehicle;
    vehicle = UnitFactory::createJeepDynamic(Position(125, 225), gaia, team2);
    units.emplace(vehicle->getId(), vehicle);

/* ---------- EDIFICIOS ---------- */

    Build *build = new Build(data.fort, Position(50, 50), player, team, 3);

    std::map<BuildID, BuildState> buildmap;
    buildmap.emplace(build->getId(), build->getBuildState());

    std::map<BuildID, Build *> builds;
    builds.emplace(build->getId(), build);

/* ---------- CAPTURABLES ---------- */

    Capturable *capturableJeep = new CapturableVehicle(*vehicle);

    std::map<CapturableID, Capturable *> capturables;
    capturables.emplace(capturableJeep->getID(), capturableJeep);

    std::map<CapturableID, CapturableState> capmap;
    capmap.emplace(capturableJeep->getID(), capturableJeep->getCapturableState());

    std::vector<Build *> buildsT;
//    buildsT.push_back(build);

    Capturable *terrain = new Territory(Position(150, 50), buildsT, gaia, team2);
    capturables.emplace(terrain->getID(), terrain);
    capmap.emplace(terrain->getID(), terrain->getCapturableState());

/* ---------- CREACION MAPA ---------- */
    Map map(stdmap, buildmap, capmap,5, 5);

    map.addUnit(robotA->getId(), robotA->getUnitState());
    map.addUnit(robotB->getId(), robotB->getUnitState());
    map.addUnit(robotC->getId(), robotC->getUnitState());
    map.addUnit(robotD->getId(), robotD->getUnitState());
//    map.addUnit(vehicle->getId(), vehicle->getUnitState());

    GameController gameController(map, units, builds, capturables);

    EventHandler eventHandler;
    Camera camera(WINDOWWIDTH, WINDOWHEIGHT);

    Model model(map, gameController, camera);
    View view(map, eventHandler, camera);

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
      // Chequeo pos del mouse para saber
      // si se debe mover camara.
      controller.checkMouseState(&e);

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
  Map map(map_loader.get_loaded_map(), map_loader.get_buildmap(),
          map_loader.get_configuration().map_width,
          map_loader.get_configuration().map_length);

  std::map<UnitID, Unit *> units;
  GameController gameController(map, units, map_loader.get_builds());

  Camera camera(WINDOWWIDTH, WINDOWHEIGHT);
  EventHandler eventHandler;

  Model model(map, gameController, camera);
  View view(map, eventHandler, camera);

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
    // Chequeo pos del mouse para saber
    // si se debe mover camara.
    controller.checkMouseState(&e);

    if (!events.empty()) {
      for (auto event : events) {
        eventHandler.add(event);
      }
    }
    view.update();
  }
}
