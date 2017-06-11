#include <server/model/Events/serverEvent.h>
#include "serverEventSender.h"
serverEventSender::serverEventSender(const std::vector<Socket *> &clients,
                                     Queue<serverEvent *> &queue) : clients(
    clients), queue(queue), open(true) {}
void serverEventSender::run() {
  try {
    while (open) {
      serverEvent *sev = queue.pop();
      for (Socket *sck : clients) {
        EventType type = sev->getType();
        sck->send_tcp((char *) &type, sizeof(EventType));
        sck->send_str_preconcatenated(sev->getDataToSend().str());
      }
      if (sev->getType() == G_ENDGAME) {
        open = false;
      }
      delete (sev);
    }
  } catch (const SocketException &e) {
    this->stop();
  }

}
void serverEventSender::stop() {
  open = false;
}
bool serverEventSender::isOpen() const {
  return open;
}
serverEventSender::~serverEventSender() {
}
