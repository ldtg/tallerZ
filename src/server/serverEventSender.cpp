#include <server/model/Events/serverEvent.h>
#include <iostream>
#include "serverEventSender.h"
serverEventSender::serverEventSender(const std::vector<Socket *> &clients,
                                     Queue<serverEvent *> &queue) : clients(
    clients), queue(queue), open(true) {}

void serverEventSender::run() {
  while (open) {
    serverEvent *sev = queue.pop();
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

void serverEventSender::stop() {
  for (Socket *cli :clients) {
    cli->shutdownConnection(ShutdownMode::WRITE);
  }
  this->open = false;
}

bool serverEventSender::isOpen() const {
  return open;
}

serverEventSender::~serverEventSender() {}

