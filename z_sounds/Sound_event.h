//
// Created by darius on 05/05/17.
//

/*
 * Primera aproximacion.
 *
 * Tutorial seguido: https://www.youtube.com/watch?v=94pPyuS1E_M
 *
 * INSTALAR SDL2:
 *      sudo apt-get install libsdl2-2.0
 *      sudo apt-get update
 *      sudo apt-get upgrade libsdl2-2.0
 *
 * Referencia: http://soundprogramming.net/programming/tutorial-using-sdl2-and-sdl_mixer-to-play-samples/
 */

#ifndef Z_SOUND_EVENT_H
#define Z_SOUND_EVENT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>

#define ERROR -1

class Sound_event {
 protected:
  Mix_Chunk *sound;
  int replays;

 public:
  Sound_event(char *sound_file_path, unsigned int replays);

  void play();

  ~Sound_event();
};

#endif //Z_SOUND_EVENT_H
