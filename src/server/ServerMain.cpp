#include <common/Socket/Socket.h>
#include <iostream>
#include <vector>
#include <common/DataClientServerMessages/DataClientConnectedMessage.h>
#include <storage/Game_Loader.h>
#include <server/model/RealGameController.h>
#include <server/ProtectedGameController.h>
#include <cereal/archives/binary.hpp>
#include "PlayersManager.h"
#include "EventSender.h"
#include "CommandReceiver.h"
std::vector<Socket *> getClients(unsigned short playersExpected,
                                 const std::string &port);

std::vector<serverCommandReceiver *> getCommandReceivers(const std::map<Socket *,
                                                                        PlayerID> &clients,
                                                         ProtectedGameController &pgc);
void sendMapToClients(const std::vector<Socket *> &clients, const Map &map);

bool anyPlayerConnected(std::vector<serverCommandReceiver *> vector);

int main(int argc, char *argv[]) {

  //Espera a que se conecten todos los jugadores
  std::vector<Socket *> clients = getClients(std::stoi(argv[2]), argv[1]);

  std::string mapPath;
  //carga los equipos y le dice a cada cliente que id tiene
  PlayersManager playersManager(clients);
  playersManager.receivePlayers();
  mapPath = playersManager.getMap();
  //carga el mapa y se lo envia a los clientes
  mapPath += ".json";
  Game_Loader game_loader(mapPath,
                          playersManager.getPlayers(),
                          playersManager.getTeams(),
                          playersManager.getGaiaPlayer());
  Map map = game_loader.run();
  sendMapToClients(clients, map);
  //crea el gc
  Queue<ServerEvent *> evqueue;
  RealGameController gameController(map, game_loader, evqueue);
  ProtectedGameController pgc(gameController);
  //lanza los threads
  EventSender eventSender(clients, evqueue);
  eventSender.start();
  std::vector<serverCommandReceiver *>
      commandReceivers = getCommandReceivers(playersManager.getClients(), pgc);
  for (serverCommandReceiver *commandReceiver: commandReceivers) {
    commandReceiver->start();
  }

  while (anyPlayerConnected(commandReceivers)) {
    pgc.tick();
  };
  evqueue.push(nullptr);// no se me ocurrio otra para destrabar el pop
  eventSender.stop();
  for (serverCommandReceiver *commandReceiver: commandReceivers) {
    commandReceiver->stop();
  }
  eventSender.join();
  for (serverCommandReceiver *commandReceiver: commandReceivers) {
    commandReceiver->join();
    delete (commandReceiver);
  }
  for (Socket *cli :clients) {
    delete (cli);
  }
  return 0;
}
bool anyPlayerConnected(std::vector<serverCommandReceiver *> vector) {
  for (serverCommandReceiver *player : vector) {
    if (player->isOpen())
      return true;
  }
  return false;
}

void sendMapToClients(const std::vector<Socket *> &clients, const Map &map) {
  std::stringstream ss;
  cereal::BinaryOutputArchive oarchive(ss);
  oarchive(map);
  for (Socket *cli:clients) {
    cli->send_str_preconcatenated(ss.str());
  }
}
std::vector<serverCommandReceiver *> getCommandReceivers(const std::map<Socket *,
                                                                        PlayerID> &clients,
                                                         ProtectedGameController &pgc) {
  std::vector<serverCommandReceiver *> rcvrs;
  for (auto &par :clients) {
    rcvrs.push_back(new serverCommandReceiver(*par.first, pgc, par.second));
  }
  return rcvrs;
}

std::vector<Socket *> getClients(unsigned short playersExpected,
                                 const std::string &port) {
  Socket accpt;
  accpt.bindandlisten(port);
  unsigned short connectedPlayers = 0;
  std::vector<Socket *> clients;
  while (connectedPlayers < playersExpected) {
    Socket *cli = new Socket(std::move(accpt.acceptConnection()));
    if (cli->isValid()) {
      clients.push_back(cli);
    } else {
      delete cli;
    }
    connectedPlayers++;
  }
  return clients;
}