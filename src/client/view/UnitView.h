#ifndef TALLERZ_ROBOTVIEW_H
#define TALLERZ_ROBOTVIEW_H

#include <common/Types/UnitType.h>
#include <queue>
#include "Sprite.h"
#include "ObjectViewMove.h"

class UnitView : public ObjectViewMove {
 private:
//  Sprite *view;
//  std::queue<ViewPosition> movements;
  UnitType type;
  std::string color;

 public:
  UnitView(UnitType type, std::string &color, Position pos,
           std::string &action, std::string &rotation);
  ~UnitView();
//  Position getPos() const;
//  ViewPosition getViewPos() const;
//  void addMove(const ViewPosition &pos);
  void walk(int rotation, const Position &posTo);
  void still();
  void fire(const Position &huntedPos);
//  void update();
  Sprite* getView() const;
  std::string getColor() const;
};

#endif //TALLERZ_ROBOTVIEW_H
