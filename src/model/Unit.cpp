#include "Unit.h"
Position Unit::getcurrentPosition() const {
  return this->currentPosition;
}
void Unit::setMovements(std::queue<Movement> moves) {
  this->movements = moves;
}
Position Unit::move() {
  if (!movements.empty()){
    currentPosition = currentPosition.move(movements.back());
    movements.pop();
  }
  return currentPosition;
}
