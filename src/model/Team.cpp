#include <algorithm>
#include "Team.h"
Team::Team(const std::map<PlayerID, Player *> &players) : players(players) {
}
void Team::addPlayer(Player *player) {
  this->players.emplace(player->getID(), player);
}
void Team::removePlayer(Player *player) {
  this->players.erase(player->getID());
}
bool Team::isEnemy(const PlayerID &playerID) const {
  return !isaPlayerOfTheTeam(playerID);
}
bool Team::isaPlayerOfTheTeam(const PlayerID &id) const {
  for (auto &par : players) {
    if (par.first == id)
      return true;
  }
  return false;
}/*
unsigned short Team::getAmountOfTerritories(const PlayerID &playerID) {
  return players.at(playerID)->getAmountOfTerritories();
}
void Team::addTerritory(const PlayerID &playerID) {
  players.at(playerID)->addTerritory();
}
void Team::subTerritory(const PlayerID &playerID) {
  players.at(playerID)->subTerritory();
}
void Team::addUnit(const PlayerID &playerID) {
  players.at(playerID)->addUnit();
}
void Team::subUnit(const PlayerID &playerID) {
  players.at(playerID)->subUnit();
}
bool Team::isPlayerAlive(const PlayerID &playerID) const {
  return players.at(playerID)->isAlive();
}*/
bool Team::isTeamAlive() const {
  for (auto &par : players) {
    if (par.second->isAlive())
      return true;
  }
  return false;
}
Team::Team() {
}
