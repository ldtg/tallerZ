#ifndef TALLERZ_SERVERPLAYERSMANAGER_H
#define TALLERZ_SERVERPLAYERSMANAGER_H

#include <server/model/Player.h>
#include <map>
#include <server/model/Team.h>
#include <common/Socket/Socket.h>
#include <common/DataClientServerMessages/dataClientConnectedMessage.h>
#include <common/DataClientServerMessages/dataServerClientAccepted.h>
#include <server/model/GaiaPlayer.h>
class serverPlayersManager {
 private:
  std::vector<Socket *> clients;
  std::map<PlayerID, Player *> players;
  std::map<unsigned short, Team> teams;
  std::map<Socket *, PlayerID> clientsSocket;
  unsigned short actual;
  std::string map;
  dataServerClientAccepted newPlayer(const dataClientConnectedMessage &data);
  GaiaPlayer gaiaPlayer;
 public:
  serverPlayersManager(const std::vector<Socket *> &clients);
  void receivePlayers();
  std::string getMap();
  std::map<TeamID, Team> getTeams() const;
  std::map<PlayerID, Player *> getPlayers() const;
  GaiaPlayer& getGaiaPlayer();
  std::map<Socket *, PlayerID> getClients() const;
  ~serverPlayersManager();
};

#endif //TALLERZ_SERVERPLAYERSMANAGER_H
