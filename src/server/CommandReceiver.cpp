#include <common/Types/CommandType.h>
#include <server/model/Commands/Command.h>
#include <server/model/Commands/CommandFactory.h>
#include <iostream>
#include "CommandReceiver.h"

serverCommandReceiver::serverCommandReceiver(Socket &socket,
                                             GameController &gc,
                                             const PlayerID &id)
    : socketClient(socket), gameController(gc), open(true), id(id) {}

void serverCommandReceiver::run() {
  try {
    while (open) {
      CommandType type;
      socketClient.receive_tcp((char *) &type, sizeof(CommandType));
      std::string cmdstr(socketClient.rcv_str_preconcatenated());
      std::stringstream ss(cmdstr);
      Command *sc = CommandFactory::createCommand(type, ss);
      sc->execute(gameController);
      delete (sc);
    }
  } catch (const SocketException &e) {
    gameController.playerDisconnected(id);
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
