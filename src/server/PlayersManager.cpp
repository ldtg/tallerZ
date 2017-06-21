#include <cereal/archives/binary.hpp>
#include "PlayersManager.h"
PlayersManager::PlayersManager(const std::vector<Socket *> &clients)
    : clients(clients), actual(0) {
  for (int j = 1; j < 5; ++j) {
    teams.emplace(j, Team());
  }
}

DataServerClientAccepted PlayersManager::newPlayer(const DataClientConnectedMessage &data) {
  Player *player = new Player((PlayerColor) actual);
  teams.at(data.team).addPlayer(player);
  actual++;
  players.emplace(player->getID(), player);
  return DataServerClientAccepted(player->getID(), teams.at(data.team).getID());
}

void PlayersManager::receivePlayers() {
  for (Socket *cli: clients) {
    std::stringstream ss(cli->rcv_str_preconcatenated());
    cereal::BinaryInputArchive iarchive(ss);
    std::string string = ss.str();
    DataClientConnectedMessage datarcv;
    iarchive(datarcv);
    DataServerClientAccepted datasnd = this->newPlayer(datarcv);
    std::stringstream out;
    cereal::BinaryOutputArchive oarchive(out);
    oarchive(datasnd);
    cli->send_str_preconcatenated(out.str());
    clientsSocket.emplace(cli, datasnd.id);
    map = datarcv.map;
  }
}

std::map<TeamID, Team> PlayersManager::getTeams() const {
  std::map<TeamID, Team> mapteams;
  for (auto &team : teams) {
    if (team.second.isTeamAlive())
      mapteams.emplace(team.second.getID(), team.second);
  }
  return mapteams;
}

std::map<PlayerID, Player *> PlayersManager::getPlayers() const {
  return players;
}

std::string PlayersManager::getMap() {
  return map;
}

GaiaPlayer &PlayersManager::getGaiaPlayer() {
  return gaiaPlayer;
}

std::map<Socket *, PlayerID> PlayersManager::getClients() const {
  return clientsSocket;
}

PlayersManager::~PlayersManager() {
  for (auto &player : players) {
    delete (player.second);
  }
}
