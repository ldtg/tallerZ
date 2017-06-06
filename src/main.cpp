
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
#include <storage/Game_Loader.h>
#include <controller/MouseState.h>
#include <model/CapturableVehicle.h>
#include <model/GaiaPlayer.h>
#include <model/Territory.h>

//Variables globales para los tests de front end
//(hace falta para usar Gtk::Application). DU not tuch
int my_argc;
char **my_argv;

int main(int argc, char *argv[]) {
//  int warning;
//  testing::InitGoogleTest(&argc, argv);
//  my_argc = argc;
//  my_argv = argv;
//
//  warning = RUN_ALL_TESTS();

  Game_Loader map_loader("mapa.json");

  Map map = map_loader.run();

  GameController gameController(map, map_loader.get_controller_units(),
                                map_loader.get_builds());

  GameController _gameController(map, map_loader.get_controller_units(),
                                 map_loader.get_builds(),
                                 map_loader.get_controller_capturables(),
                                 map_loader.get_controller_terrainObjects(),
                                 map_loader.get_players(),
                                 map_loader.get_teams());
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
  return 0;
}


