#ifndef TALLERZ_UNITCREATEVISTA_H
#define TALLERZ_UNITCREATEVISTA_H

#include "ExplosionVista.h"

class UnitCreateVista : public ExplosionVista {
 private:
//  UnitID id;
//  Position pos;
 public:
  UnitCreateVista(const char *file, int num_frames, int speed);
  void finishExplosion(View *view);
};

#endif //TALLERZ_UNITCREATEVISTA_H
