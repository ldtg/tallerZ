#include <algorithm>
#include "Team.h"

Team::Team(const std::map<PlayerID, Player *> &players)
    : players(players), id() {
}

Team::Team() {}

void Team::addPlayer(Player *player) {
  this->players.emplace(player->getID(), player);
}

void Team::removePlayer(Player *player) {
  this->players.erase(player->getID());
}

bool Team::isEnemy(const PlayerID &playerID) const {
  if (playerID.isGaia())
    return true;
  return !isaPlayerOfTheTeam(playerID);
}

bool Team::isaPlayerOfTheTeam(const PlayerID &id) const {
  for (auto &par : players) {
    if (par.first == id)
      return true;
  }
  return false;
}

bool Team::isTeamAlive() const {
  for (auto &par : players) {
    if (par.second->isAlive())
      return true;
  }
  return false;
}

TeamID Team::getID() const {
  return id;
}
