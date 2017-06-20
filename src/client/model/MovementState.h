#ifndef TALLERZ_MOVEMENTSTATE_H
#define TALLERZ_MOVEMENTSTATE_H

enum MovementStateEnum { STILL, CAPTURING, MOVING, ATTACKING };
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
  void attacking() {
    movementState = ATTACKING;
  }
  bool isStill() const {
    return movementState == STILL;
  }
  bool isMoving() const {
    return movementState == MOVING;
  }
  bool isAttacking() const {
    return movementState == ATTACKING;
  }
  bool isCapturing() const {
    return movementState == CAPTURING;
  }
};
#endif //TALLERZ_MOVEMENTSTATE_H
