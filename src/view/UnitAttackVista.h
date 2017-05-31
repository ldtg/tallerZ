#ifndef TALLERZ_UNITATTACKVISTA_H
#define TALLERZ_UNITATTACKVISTA_H

#include "Sprite.h"

class UnitAttackVista : public Sprite {
 public:
  UnitAttackVista(const char *file, int num_frames, int speed);
  void draw(SDL_Renderer *render);
};

#endif //TALLERZ_UNITATTACKVISTA_H
