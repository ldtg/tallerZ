#ifndef TALLERZ_TEAM_H
#define TALLERZ_TEAM_H

#include <vector>
#include "Player.h"
class Team {
 private:
  std::vector<Player *> players;
 public:
  explicit Team(const std::vector<Player *> players);
  void addPlayer(Player *player);
  void removePlayer(Player *player);
  bool isEnemy(const PlayerID &playerID) const
  bool isAlive() const;
};

#endif //TALLERZ_TEAM_H
