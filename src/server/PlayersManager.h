#ifndef TALLERZ_SERVERPLAYERSMANAGER_H
#define TALLERZ_SERVERPLAYERSMANAGER_H

#include <server/model/Player.h>
#include <map>
#include <server/model/Team.h>
#include <common/Socket/Socket.h>
#include <common/DataClientServerMessages/DataClientConnectedMessage.h>
#include <common/DataClientServerMessages/DataServerClientAccepted.h>
#include <server/model/GaiaPlayer.h>
class PlayersManager { //maneja el recibimienyo de los jugadores y la asignacion de ids y equipos
 private:
  std::vector<Socket *> clients;
  std::map<PlayerID, Player *> players;
  std::map<unsigned short, Team> teams;
  std::map<Socket *, PlayerID> clientsSocket;
  unsigned short actual;
  std::string map;
  DataServerClientAccepted newPlayer(const DataClientConnectedMessage &data);
  GaiaPlayer gaiaPlayer;
 public:
  PlayersManager(const std::vector<Socket *> &clients);
  //recibe a los jugadores intercambiando la info del protocolo
  void receivePlayers();
  std::string getMap();
  std::map<TeamID, Team> getTeams() const;
  std::map<PlayerID, Player *> getPlayers() const;
  GaiaPlayer& getGaiaPlayer();
  std::map<Socket *, PlayerID> getClients() const;
  ~PlayersManager();
};

#endif //TALLERZ_SERVERPLAYERSMANAGER_H
