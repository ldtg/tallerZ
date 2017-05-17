#include "gtest/gtest.h"
#include "../../src/vista/Window.h"
#include "../../src/vista/Panel.h"
#include "../../src/vista/Image.h"
#include <SDL2/SDL_image.h>
#include <thread>
#include <ctime>

TEST(VistaTest, Window) {
  //Main loop flag
  bool quit = false;
  //Event handler
  SDL_Event e;

  Window window;
  Panel panel(window.getRender());
  ObjectMapaVista *objVista = new Image("../src/vista/images/terrain/land.png");
  ASSERT_TRUE(objVista!=NULL);
  objVista->setPos(50,50);
  panel.add(objVista);

  int fps = 60;

  //While application is running
  while( !quit ) {
    time_t _start = time(0);
    struct tm *start = localtime(&_start);

    //Handle events on queue
    while( SDL_PollEvent( &e ) != 0 ) {
      //User requests quit
      if( e.type == SDL_QUIT ) {
        quit = true;
      }
    }
    panel.draw();

    time_t _end = time(0);
    struct tm *end = localtime(&_start);

    int x = start->tm_sec + fps - end->tm_sec;
//    std::cout << x << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(x));
  }

}

