#include "gtest/gtest.h"
#include "../../src/view/View.h"
#include "../../src/controller/Controller.h"
#include "../../src/model/Events/EventHandler.h"

#include <SDL2/SDL_image.h>
#include <thread>

#include <ctime>
#include <chrono>
#include <ratio>
#include <model/Data.h>
#include <model/UnitFactory.h>
#include <model/GameController.h>

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
    Player player("jugador1");
    Team team;
    team.addPlayer(&player);

/* ---------- UNIDADES ---------- */
    std::map<UnitID, Unit *> units;
    Unit *robotA;
    robotA = UnitFactory::createGruntDynamic(Position(50, 50), player, team);
    units.emplace(robotA->getId(), robotA);

/* ---------- CREACION MAPA ---------- */
    Map map(stdmap, 3, 3);
    map.addUnit(robotA->getId(), robotA->getUnitState());
    GameController gameController(map, units);

    EventHandler eventHandler;

    Model model(map, gameController);
    Window window;
    View view(map, eventHandler, window);

    eventHandler.setView(&view);
    eventHandler.setModel(&model);

    //Main loop flag
//  bool quit = false;
    //Event handler
    SDL_Event e;

    Controller controller(eventHandler);

    //While application is running
    while (!view.quit()) {
      auto begin = std::chrono::high_resolution_clock::now();

      //Handle events on queue
      std::vector<Event *> vec = gameController.tick();
      if (SDL_PollEvent(&e) != 0) {
        controller.handle(&e);
      }
      if (!vec.empty()) {
        for (auto item : vec) {
          eventHandler.add(item);
        }
      }
      view.update();

      auto end = std::chrono::high_resolution_clock::now();
      auto diff =
          std::chrono::duration_cast<std::chrono::duration<double>>(
              end - begin);
      std::this_thread::sleep_for(
          std::chrono::milliseconds(25) - diff);
    }

    delete (robotA);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
