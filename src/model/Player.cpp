#include "Player.h"
Player::Player(const std::string &name)
    : id(name), capturedTerritories(0), unitsAlives(0), alive(
    true) {}
unsigned short Player::getAmountOfTerritories() {
  return capturedTerritories;
}
void Player::addTerritory() {
  if (this->isAlive())
    this->capturedTerritories++;
}
void Player::subTerritory() {
  if (this->isAlive()) {
    this->capturedTerritories--;
    this->alive = capturedTerritories != 0;
  }

}
void Player::addUnit() {
  if (this->isAlive())
    this->unitsAlives++;
}
void Player::subUnit() {
  if (this->isAlive()) {
    this->unitsAlives--;
    this->alive = unitsAlives != 0;
  }
}
bool Player::isAlive() const {
  return alive;
}
PlayerID Player::getID() const {
  return id;
}
void Player::buildDestroyed(const BuildType &type) {
  if(type == BuildType::FORT)
    alive = false;
}
