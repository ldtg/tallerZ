#ifndef TALLERZ_CLIENTE_FIREHITVIEW_H
#define TALLERZ_CLIENTE_FIREHITVIEW_H

#include "ExplosionView.h"
#include "client/view/Sprite.h"

class FireHitView : public ExplosionView {
 private:
  Sprite *explosion1;
  Sprite *explosion2;

 public:
  FireHitView(const Position &pos);
  ~FireHitView();
  bool doCycle() const;
  void draw(SDL_Renderer *render, Camera &camera);
};

#endif //TALLERZ_CLIENTE_FIREHITVIEW_H
