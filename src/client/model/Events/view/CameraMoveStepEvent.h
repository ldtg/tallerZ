#ifndef TALLERZ_CAMERAMOVESTEPEVENT_H
#define TALLERZ_CAMERAMOVESTEPEVENT_H

#include <client/model/Events/Event.h>

class CameraMoveStepEvent : public Event {
 private:
  Camera& camera;
  int x;
  int y;
 public:
  CameraMoveStepEvent(Camera &camera, int x, int y);
  void process();
};

#endif //TALLERZ_CAMERAMOVESTEPEVENT_H
