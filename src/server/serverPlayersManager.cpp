#include <cereal/archives/binary.hpp>
#include "serverPlayersManager.h"
serverPlayersManager::serverPlayersManager(const std::vector<Socket *> &clients)
    : clients(clients), actual(0) {
  for (int j = 1; j < 5; ++j) {
    teams.emplace(j, Team());
  }
}
dataServerClientAccepted serverPlayersManager::newPlayer(const dataClientConnectedMessage &data) {
  Player *player = new Player((PlayerColor) actual);
  teams.at(data.team).addPlayer(player);
  actual++;
  players.emplace(player->getID(), player);
  return dataServerClientAccepted(player->getID(), teams.at(data.team).getID());
}
std::map<TeamID, Team> serverPlayersManager::getTeams() const {
  std::map<TeamID, Team> mapteams;
  for (auto &team : teams) {
    if (team.second.isTeamAlive())
      mapteams.emplace(team.second.getID(), team.second);
  }
  return mapteams;
}
std::map<PlayerID, Player *> serverPlayersManager::getPlayers() const {
  return players;
}
serverPlayersManager::~serverPlayersManager() {
  for (auto &player : players) {
    delete (player.second);
  }
}
void serverPlayersManager::receivePlayers() {
  for (Socket *cli: clients) {
    std::stringstream ss(cli->rcv_str_preconcatenated());
    cereal::BinaryInputArchive iarchive(ss);
    std::string string = ss.str();
    dataClientConnectedMessage datarcv;
    iarchive(datarcv);
    dataServerClientAccepted datasnd = this->newPlayer(datarcv);
    std::stringstream out;
    cereal::BinaryOutputArchive oarchive(out);
    oarchive(datasnd);
    cli->send_str_preconcatenated(out.str());
    clientsSocket.emplace(cli, datasnd.id);
    map = datarcv.map;
  }
}
std::string serverPlayersManager::getMap() {
  return map;
}
GaiaPlayer &serverPlayersManager::getGaiaPlayer() {
  return gaiaPlayer;
}
std::map<Socket *, PlayerID> serverPlayersManager::getClients() const {
  return clientsSocket;
}
