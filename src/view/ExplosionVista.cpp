#include "ExplosionVista.h"

ExplosionVista::ExplosionVista(const char *file, int num_frames, int speed)
    : Sprite(file, num_frames, speed, 0) {}

void ExplosionVista::finishExplosion(View *view) {}
