#include <server/model/Events/ServerEvent.h>
#include <iostream>
#include "EventSender.h"
EventSender::EventSender(const std::vector<Socket *> &clients,
                                     Queue<ServerEvent *> &queue) : clients(
    clients), queue(queue), open(true) {}

void EventSender::run() {
  while (open) {
    ServerEvent *sev = queue.pop();
    if (sev != nullptr) {
      for (auto iterator = clients.begin(); iterator != clients.end();) {
        try {
          Socket *cli = *iterator;
          EventType type = sev->getType();
          cli->send_tcp((char *) &type, sizeof(EventType));
          cli->send_str_preconcatenated(sev->getDataToSend().str());
          ++iterator;
        } catch (const SocketException &e) {
          //cli desconectado
          iterator = clients.erase(iterator);
        }
      }
      delete (sev);
    } else {
      this->open = false;
    }
  }
}

void EventSender::stop() {
  for (Socket *cli :clients) {
    cli->shutdownConnection(ShutdownMode::WRITE);
  }
  this->open = false;
}

bool EventSender::isOpen() const {
  return open;
}

EventSender::~EventSender() {}

