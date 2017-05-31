#ifndef TALLERZ_TEAM_H
#define TALLERZ_TEAM_H

#include <vector>
#include <map>
#include "Player.h"
#include "TeamID.h"
class Team {
 private:
  TeamID id;
  std::map<PlayerID, Player *> players;
 public:
  explicit Team(const std::map<PlayerID, Player *> &players);
  Team();
  void addPlayer(Player *player);
  void removePlayer(Player *player);
  bool isEnemy(const PlayerID &playerID) const;
  bool isTeamAlive() const;
  bool isaPlayerOfTheTeam(const PlayerID &id) const;
};

#endif //TALLERZ_TEAM_H
