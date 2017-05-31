#ifndef TALLERZ_EXPLOSIONVISTA_H
#define TALLERZ_EXPLOSIONVISTA_H

#include "Sprite.h"
#include "View.h"

class ExplosionVista : public Sprite {
 public:
  ExplosionVista(const char *file, int num_frames, int speed);
  virtual void finishExplosion(View *view);
};

#endif //TALLERZ_EXPLOSIONVISTA_H
