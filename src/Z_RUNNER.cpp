//
// Created by darius on 22/05/17.
//

#include "Z_RUNNER.h"
Z_RUNNER::Z_RUNNER() {
}

void Z_RUNNER::run() {
  Game_Loader map_loader("mapa.json");

  Map map = map_loader.run();

  GameController gameController(map, map_loader.get_controller_units(),
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
}
Z_RUNNER::~Z_RUNNER() {
}


