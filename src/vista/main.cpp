#include <SDL2/SDL_image.h>
#include "Window.h"
#include "Image.h"

int main( int argc, char* args[] ) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    Image image("AltoTemplario.png");
//    Sprite sprite("foo.png", 4);
    Sprite sprite("d.png", 9);

    Window window;
    window.load_image(std::move(image));
//    window.load_sprite(std::move(sprite));
    window.load_sprite(&sprite);

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
//        sprite.move(-1, 0);
    }

    IMG_Quit();
    SDL_Quit();
}

