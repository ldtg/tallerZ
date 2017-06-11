#ifndef TALLERZ_CAMERAMOVE_H
#define TALLERZ_CAMERAMOVE_H

#include <client/model/Events/Event.h>

class CameraMove : public Event {
 private:
  int x;
  int y;
 public:
  CameraMove(int x, int y);
  void process();
};

#endif //TALLERZ_CAMERAMOVE_H
