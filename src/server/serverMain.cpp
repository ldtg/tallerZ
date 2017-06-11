#include <common/Socket/Socket.h>
#include <iostream>
#include <vector>
#include <common/DataClientServerMessages/dataClientConnectedMessage.h>
#include <storage/Game_Loader.h>
#include <server/model/realGameController.h>
#include <server/model/protectedGameController.h>
#include <cereal/archives/binary.hpp>
#include "serverPlayersManager.h"
#include "serverGameRunner.h"
#include "serverEventSender.h"
#include "serverCommandReceiver.h"
std::vector<Socket *> getClients();

std::vector<serverCommandReceiver *> getCommandReceivers(const std::vector<
    Socket *> &clients, protectedGameController &pgc);
void sendMapToClients(const std::vector<Socket *> &clients, const Map &map);

int dmain(int argc, char *argv[]) {
  //Espera a que se conecten todos los jugadores
  std::vector<Socket *> clients = getClients();

  std::string mapPath;
  //carga los equipos y le dice a cada cliente que id tiene
  serverPlayersManager playersManager(clients);
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
  Queue<serverEvent *> evqueue;
  realGameController gameController(map, game_loader, evqueue);
  protectedGameController pgc(gameController);
  //lanza los threads
  serverGameRunner gameRunner(pgc);
  gameRunner.start();
  serverEventSender eventSender(clients, evqueue);
  eventSender.start();
  std::vector<serverCommandReceiver *>
      commandReceivers = getCommandReceivers(clients, pgc);
  for (serverCommandReceiver *commandReceiver: commandReceivers) {
    commandReceiver->start();
  }

  while (getc(stdin) != 'q' && !gameController.isGameEnded()) {};

  gameRunner.stop();
  eventSender.stop();
  for (serverCommandReceiver *commandReceiver: commandReceivers) {
    commandReceiver->stop();
  }
  gameRunner.join();
  eventSender.join();
  for (serverCommandReceiver *commandReceiver: commandReceivers) {
    commandReceiver->join();
    delete (commandReceiver);
  }
  return 0;
}
void sendMapToClients(const std::vector<Socket *> &clients, const Map &map) {
  std::stringstream ss;
  cereal::BinaryOutputArchive oarchive(ss);
  oarchive(map);
  for (Socket *cli:clients) {
    cli->send_str_preconcatenated(ss.str());
  }
}
std::vector<serverCommandReceiver *> getCommandReceivers(const std::vector<
    Socket *> &clients, protectedGameController &pgc) {
  std::vector<serverCommandReceiver *> rcvrs;
  for (Socket *cli:clients) {
    rcvrs.push_back(new serverCommandReceiver(*cli, pgc));
  }
  return rcvrs;
}

std::vector<Socket *> getClients() {
  Socket accpt;
  accpt.bindandlisten("8080");
  unsigned short connectedPlayers = 0;
  unsigned short playersExpected = 1;
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