#include "clientCommandSender.h"

clientCommandSender::clientCommandSender(Socket &socket,
                                         Queue<clientCommand *> &queue)
    : socket(socket), queue(queue), open(true) {}

void clientCommandSender::run() {
  try {
    while (open) {
      clientCommand *cmd = queue.pop();

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

void clientCommandSender::stop() {
  socket.shutdownConnection(ShutdownMode::WRITE);
  open = false;
}

bool clientCommandSender::isOpen() const {
  return open;
}

clientCommandSender::~clientCommandSender() {
  while (!queue.empty()) {
    delete (queue.pop());
  }
}
