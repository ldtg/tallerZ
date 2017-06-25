#ifndef TALLERZ_CLIENTE_DEATHVIEW_H
#define TALLERZ_CLIENTE_DEATHVIEW_H

#include "client/view/unit/UnitView.h"
#include "ExplosionView.h"

class UnitDeathView : public ExplosionView {
 private:
  Sprite *deathView;
 public:
  UnitDeathView(UnitType type, const UnitView *unitView);
  virtual ~UnitDeathView();
  bool doCycle() const;
  void draw(SDL_Renderer *render, Camera &camera);
};

#endif //TALLERZ_CLIENTE_DEATHVIEW_H
