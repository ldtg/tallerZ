#include <client/model/Events/EventFactory.h>
#include "ClientEventReceiver.h"
ClientEventReceiver::ClientEventReceiver(Socket &srvSocket,
                                         Queue<Event *> &queue) : srvSocket(
    srvSocket), queue(queue), open(true) {}
void ClientEventReceiver::run() {
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
    this->stop();
  }
}
void ClientEventReceiver::stop() {
  open = false;
  srvSocket.shutdownConnection(ShutdownMode::WRITE);
  while (!queue.empty()) {
    delete (queue.pop());
  }
}
bool ClientEventReceiver::isOpen() const {
  return open;
}

ClientEventReceiver::~ClientEventReceiver() {
  while (!queue.empty()) {
    delete (queue.pop());
  }
}
