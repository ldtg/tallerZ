#ifndef TALLERZ_SERVER_H
#define TALLERZ_SERVER_H

#include <common/Thread/Thread.h>
#include <common/Socket/Socket.h>
#include <vector>
#include <common/IDs/PlayerID.h>
#include <server/model/Player.h>
#include <map>
#include <server/model/Team.h>
#include <common/Map/Map.h>
#include <server/model/protectedGameController.h>
class Server : public Thread{
 private:
  std::string service;
  std::vector<Socket *> clients;
  std::map<PlayerID, Player*> players;
  std::map<TeamID, Team> teams;
  bool open;
  void getClients();
 public:
  Server(const std::string &service);
  virtual void run() override;
  void stop();
  bool isOpen() const;
};

#endif //TALLERZ_SERVER_H
