#ifndef TALLERZ_CLIENTE_LASERHITVIEW_H
#define TALLERZ_CLIENTE_LASERHITVIEW_H

#include "ExplosionView.h"
#include "client/view/Sprite.h"

class LaserHitView : public ExplosionView {
 private:
  Sprite *explosion;

 public:
  LaserHitView(const Position &pos);
  ~LaserHitView();
  bool doCycle() const;
  void draw(SDL_Renderer *render, Camera &camera);
};

#endif //TALLERZ_CLIENTE_LASERHITVIEW_H
