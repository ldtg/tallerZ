#ifndef TALLERZ_RIGHTCLICKEVENT_H
#define TALLERZ_RIGHTCLICKEVENT_H

#include <Events/Event.h>

class RightClickEvent : public Event {
   private:
    int x;
    int y;
   public:
    RightClickEvent(int x, int y);
    void process();
};

#endif //TALLERZ_RIGHTCLICKEVENT_H
