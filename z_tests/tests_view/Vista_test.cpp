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

/* ---------- UNIDADES ---------- */
    std::map<UnitID, Unit *> units;

    Unit *robotA;
    robotA = UnitFactory::createGruntDynamic(Position(50, 50));
    units.emplace(robotA->getId(), robotA);

    Unit *robotB;
    robotB = UnitFactory::createGruntDynamic(Position(150, 150));
    units.emplace(robotB->getId(), robotB);

/* ---------- CREACION MAPA ---------- */
    Map map(stdmap, 3, 3);
    map.addUnit(robotA->getId(), robotA->getUnitState());
    map.addUnit(robotB->getId(), robotB->getUnitState());
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
//      auto begin = std::chrono::high_resolution_clock::now();

      //Handle events on queue
      std::vector<Event *> events = gameController.tick();
      if (SDL_PollEvent(&e) != 0) {
        controller.handle(&e);
      }
      if (!events.empty()) {
        for (auto event : events) {
          eventHandler.add(event);
        }
      }
      view.update();

//      auto end = std::chrono::high_resolution_clock::now();
//      auto diff =
//          std::chrono::duration_cast<std::chrono::duration<double>>(end - begin);
//      std::this_thread::sleep_for(
//          std::chrono::milliseconds(25) - diff);
    }

    delete (robotB);
    delete (robotA);
  } catch (const std::exception& e){
    std::cout << e.what() << std::endl;
  }
}
