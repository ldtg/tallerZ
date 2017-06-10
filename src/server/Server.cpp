#include "Server.h"
Server::Server(const std::string &service) : service(service) {}

void Server::run() {
  getClients();
  for (Socket *cli: clients) {

  }
}
void Server::getClients(){
  Socket accpt;
  accpt.bindandlisten("8080");
  unsigned short connectedPlayers = 0;
  unsigned short playersExpected = 2;
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
}
