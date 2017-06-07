#ifndef TALLERZ_MOVEMENTSTATE_H
#define TALLERZ_MOVEMENTSTATE_H

enum MovementStateEnum { STILL, CAPTURING, MOVING, HUNTING, AUTOATTACKING };
struct MovementState {
 private:
  MovementStateEnum movementState;
 public:
  MovementState() {
    movementState = STILL;
  }
  void still() {
    movementState = STILL;
  }
  void moving() {
    movementState = MOVING;
  }
  void capturing() {
    movementState = CAPTURING;
  }
  void hunting() {
    movementState = HUNTING;
  }
  void autoAttacking() {
    movementState = AUTOATTACKING;
  }
  bool isStill() const {
    return movementState == STILL;
  }
  bool isMoving() const {
    return movementState == MOVING;
  }
  bool isHunting() const {
    return movementState == HUNTING;
  }
  bool isCapturing() const {
    return movementState == CAPTURING;
  }
  bool isAutoAttacking() const {
    return movementState == AUTOATTACKING;
  }
};
#endif //TALLERZ_MOVEMENTSTATE_H
