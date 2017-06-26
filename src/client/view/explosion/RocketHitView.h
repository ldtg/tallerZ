#ifndef TALLERZ_CLIENTE_ROCKETHITVIEW_H
#define TALLERZ_CLIENTE_ROCKETHITVIEW_H

#include "ExplosionView.h"
#include "client/view/Sprite.h"

class RocketHitView : public ExplosionView {
 private:
  Sprite *explosion1;
 public:
  RocketHitView(const Position &pos);
  virtual ~RocketHitView();
  bool doCycle() const;
  void draw(SDL_Renderer *render, Camera &camera);
};

#endif //TALLERZ_CLIENTE_ROCKETHITVIEW_H
