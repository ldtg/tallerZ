#ifndef TALLERZ_CLIENTE_OBJECTVIEWMOVE_H
#define TALLERZ_CLIENTE_OBJECTVIEWMOVE_H

#include <queue>
#include <client/model/MovementState.h>
#include "ViewPosition.h"
#include "ObjectView.h"
#include "Sprite.h"

/**
 * @class ObjectViewMove
 *  Encapsula la lógica de movimiento en la vista de aquellos objetos
 *  que se muevan, como las unidades y las balas, por lo que \todo objeto
 *  que se mueva debe heredar de esta clase.
 */
class ObjectViewMove {
 protected:
  Sprite *view;
  std::queue<ViewPosition> movements;
  bool lastMove;
  MovementState state;
  ObjectViewMove(Sprite *view);

 public:
  Position getPos() const;
  ViewPosition getViewPos() const;
  void addMove(const ViewPosition &pos);
  void setLastMove();
  virtual void walk(int rotation, const Position &posTo) = 0;
  virtual void still() = 0;
  /**
   * En caso que haya posiciones a las que moverse, mueve al objeto
   * teniendo en cuenta si cambio su rotación. Tambien se encarga de parar
   * al objeto, es decir que deje de moverse
   */
  virtual void update();
  virtual ~ObjectViewMove();
};

#endif //TALLERZ_CLIENTE_OBJECTVIEWMOVE_H
