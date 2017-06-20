#ifndef TALLERZ_ROBOTVIEW_H
#define TALLERZ_ROBOTVIEW_H

#include <common/Types/UnitType.h>
#include <queue>
#include "Sprite.h"
#include "ObjectViewMove.h"

class UnitView : public ObjectViewMove {
 protected:
  UnitType type;
  std::string color;

 public:
  UnitView(UnitType type, std::string &color, Position pos,
           std::string &action, std::string &rotation);
  virtual ~UnitView();
  virtual void walk(int rotation, const Position &posTo);
  virtual void still();
  virtual void fire(const Position &huntedPos);
  Sprite* getView() const;
  std::string getColor() const;

  virtual void draw(SDL_Renderer *render, Camera &camera);
};

#endif //TALLERZ_ROBOTVIEW_H
