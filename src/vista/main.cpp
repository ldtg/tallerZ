#include <SDL2/SDL_image.h>
#include "Window.h"
#include "Sprite.h"

int main( int argc, char* args[] ) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    Window window;

    Sprite explocion("images/tank_missile_explosion1_n", 12);
    window.load(&explocion);

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
        window.draw();
//        sprite.move(-1, 1);
    }

    IMG_Quit();
    SDL_Quit();
}

