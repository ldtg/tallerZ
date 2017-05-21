#ifndef TALLERZ_TEAM_H
#define TALLERZ_TEAM_H

#include <vector>
#include <map>
#include "Player.h"
class Team {
 private:
  std::map<PlayerID, Player *> players;
 public:
  explicit Team(const std::vector<Player *> players);
  void addPlayer(Player *player);
  void removePlayer(Player *player);
  bool isEnemy(const PlayerID &playerID) const;
  unsigned short getAmountOfTerritories(const PlayerID &playerID);
  void addTerritory(const PlayerID &playerID);
  void subTerritory(const PlayerID &playerID);
  void addUnit(const PlayerID &playerID);
  void subUnit(const PlayerID &playerID);
  bool isPlayerAlive(const PlayerID &playerID) const;
  bool isTeamAlive() const;
};

#endif //TALLERZ_TEAM_H
