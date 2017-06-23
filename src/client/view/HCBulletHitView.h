#ifndef TALLERZ_CLIENTE_HCBULLETHITVIEW_H
#define TALLERZ_CLIENTE_HCBULLETHITVIEW_H

#include "ExplosionView.h"
#include "Sprite.h"

class HCBulletHitView : public ExplosionView {
 private:
  Sprite *explosion1;
  Sprite *explosion2;

 public:
  HCBulletHitView(Position &pos);
  ~HCBulletHitView();
  bool doCycle() const;
  void draw(SDL_Renderer *render, Camera &camera);
};

#endif //TALLERZ_CLIENTE_HCBULLETHITVIEW_H
