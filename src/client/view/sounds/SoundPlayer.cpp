#include <common/Thread/Lock.h>
#include "SoundPlayer.h"

SoundPlayer::SoundPlayer() : open(true) {}

void SoundPlayer::add(Sound *sound) {
  if (sound == nullptr)
    return;

  sounds.push_back(sound);
}

void SoundPlayer::run() {
  while (open) {
    while (!sounds.empty()) {
//      std::cout << sounds.capacity() << std::endl;

      Sound *sound = sounds[0];
//      std::cout << sound->getPath() << std::endl;

      sound->play();
      delete sound;
      sounds.erase(sounds.begin());
    }
  }
}

void SoundPlayer::stop() {
  open = false;
}
