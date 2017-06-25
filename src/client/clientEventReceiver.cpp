#include <client/model/Events/EventFactory.h>
#include "clientEventReceiver.h"
clientEventReceiver::clientEventReceiver(Socket &srvSocket,
                                         Queue<Event *> &queue) : srvSocket(
    srvSocket), queue(queue), open(true) {}
void clientEventReceiver::run() {
  try {
    while (open) {
      EventType type;
      srvSocket.receive_tcp((char *) &type, sizeof(EventType));
      std::string str = srvSocket.rcv_str_preconcatenated();
      std::stringstream ss(str);
      Event *ev = EventFactory::createEvent(type, ss);
      queue.push(ev);
    }
  } catch (const SocketException &e) {
    this->open = false;
  }
}
void clientEventReceiver::stop() {
  open = false;
  srvSocket.shutdownConnection(ShutdownMode::WRITE);
}
bool clientEventReceiver::isOpen() const {
  return open;
}
clientEventReceiver::~clientEventReceiver() {}
