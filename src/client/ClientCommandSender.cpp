#include <iostream>
#include "ClientCommandSender.h"

ClientCommandSender::ClientCommandSender(Socket &socket,
                                         Queue<ClientCommand *> &queue)
    : socket(socket), queue(queue), open(true) {}

void ClientCommandSender::run() {
  try {
    while (open) {
      ClientCommand *cmd = queue.pop();
      if (cmd != nullptr) {
        CommandType type = cmd->getType();
        socket.send_tcp((char *) &type, sizeof(CommandType));
        socket.send_str_preconcatenated(cmd->getDataToSend().str());
        delete (cmd);
      } else {
        this->stop();
      }
    }
  } catch (const SocketException &e) {
    this->open = false;
  }
}

void ClientCommandSender::stop() {
  socket.shutdownConnection(ShutdownMode::WRITE);
  open = false;
}

bool ClientCommandSender::isOpen() const {
  return open;
}

ClientCommandSender::~ClientCommandSender() {
  while (!queue.empty()) {
    delete (queue.pop());
  }
}
