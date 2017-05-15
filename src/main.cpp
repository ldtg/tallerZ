#include <SDL2/SDL_image.h>
#include "vista/Vista.h"
#include "model/Map.h"

int main( int argc, char* args[] ) {
/*
    Window window;
    Sprite explocion("images/tank_missile_explosion1_n", 12);
    window.load(&explocion);
*/
    Map map;
    Vista vista(map);

    //Main loop flag
    bool quit = false;
    //Event handler
    SDL_Event e;

    //While application is running
    while( !quit ) {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 ) {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }
        vista.update();

//        window.draw();
//        sprite.move(-1, 1);
    }
}

