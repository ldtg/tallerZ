#ifndef TALLERZ_CLIENTE_SOUND_H
#define TALLERZ_CLIENTE_SOUND_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <common/Thread/Thread.h>

class Sound {
 protected:
  Mix_Chunk *sound;
  int replays;
  std::string path;

 public:
  Sound(const std::string &sound_file_path, unsigned int replays);
  void play();
  const char* getPath() const;
  ~Sound();
};

#endif //TALLERZ_CLIENTE_SOUND_H
