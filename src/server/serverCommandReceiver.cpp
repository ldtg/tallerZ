#include <common/DataCommands/CommandType.h>
#include <server/model/Commands/serverCommand.h>
#include <server/model/Commands/serverCommandFactory.h>
#include <iostream>
#include "serverCommandReceiver.h"

serverCommandReceiver::serverCommandReceiver(Socket &socket,
                                             serverGameController &gc)
    : socketClient(socket), gameController(gc), open(true) {}
void serverCommandReceiver::run() {
  serverCommand *sc;
  CommandType type;
  try {
    while (open) {
      socketClient.receive_tcp((char *) &type, sizeof(CommandType));
      std::string cmdstr(socketClient.rcv_str_preconcatenated());
      std::stringstream ss(cmdstr);
      sc = serverCommandFactory::createCommand(type, ss);
      sc->execute(gameController);
      delete (sc);
    }
  } catch (const std::exception &e) {
    std::cerr << "Error en serverCommandReceiver::run(): " << e.what();
    this->stop();
  }
}
void serverCommandReceiver::stop() {
  //no tiene que hacer shutdown porque es socket de receive
  open = false;
}
bool serverCommandReceiver::isOpen() const {
  return open;
}
serverCommandReceiver::~serverCommandReceiver() {}
