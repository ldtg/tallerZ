#ifndef TALLERZ_CLIENTE_SOUNDPLAYER_H
#define TALLERZ_CLIENTE_SOUNDPLAYER_H

#include <cereal/types/vector.hpp>
#include <mutex>
#include "Sound.h"

class SoundPlayer : public Thread {
 private:
  std::vector<Sound*> sounds;
  bool open;
 public:
  SoundPlayer();
  void add(Sound *sound);

  virtual void run() override;
  void stop();
};

#endif //TALLERZ_CLIENTE_SOUNDPLAYER_H
