#include "Sound.h"

#include <chrono>
#include <thread>

Sound::Sound(const std::string &sound_file_path, unsigned int replays) {
  sound = Mix_LoadWAV(sound_file_path.c_str());
  if (sound == NULL){
    std::cout << "ERROR: " << Mix_GetError() << std::endl;
  }
  this->replays = replays;
  path = sound_file_path;
}

Sound::~Sound() {
//  Mix_FreeChunk(sound);
}

void Sound::play() {
  if (Mix_PlayChannel(-1,sound,replays) < 0) {
    //throw exception
    std::cout << "Error en play de Sound_event.h\n";
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(150));
}

const char* Sound::getPath() const {
  return path.c_str();
}
