#include <common/DataCommands/CommandType.h>
#include <server/model/Commands/serverCommand.h>
#include <server/model/Commands/serverCommandFactory.h>
#include "serverCommandReceiver.h"

serverCommandReceiver::serverCommandReceiver(Socket &socket,
                                     serverGameController &gc)
    : socketClient(socket), gameController(gc), open(true) {}
void serverCommandReceiver::run() {
  try {
    while (open) {
      CommandType type;
      socketClient.receive_tcp((char *) &type, sizeof(CommandType));
      std::string cmdstr(socketClient.rcv_str_preconcatenated());
      std::stringstream ss(cmdstr);
      serverCommand *sc = serverCommandFactory::createCommand(type, ss);
      sc->execute(gameController);
      delete (sc);
    }
  } catch (const SocketException &e) {
    this->stop();
  }
}
void serverCommandReceiver::stop() {
  open = false;
  socketClient.closeSocket();
}
bool serverCommandReceiver::isOpen() const {
  return open;
}
serverCommandReceiver::~serverCommandReceiver() {}