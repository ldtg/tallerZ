#ifndef TALLERZ_MOVEMENTSTATE_H
#define TALLERZ_MOVEMENTSTATE_H

enum MovementStateEnum { STILL, CAPTURING, MOVING, HUNTING };
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
  bool isStill() const{
    return movementState == STILL;
  }
  bool isMoving() const{
    return movementState == MOVING;
  }
  bool isHunting() const{
    return movementState == HUNTING;
  }
  bool isCapturing() const{
    return movementState == CAPTURING;
  }
};
#endif //TALLERZ_MOVEMENTSTATE_H
