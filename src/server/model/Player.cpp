#include "Player.h"
#include "Data.h"

Player::Player(const PlayerColor &color)
    : id(color), capturedTerritories(data.playerInitialTerritories),
      unitsAlives(data.playerInitialUnits), alive(true) {}

void Player::addTerritory() {
  if (this->isAlive())
    this->capturedTerritories++;
}

void Player::subTerritory() {
  if (this->isAlive()) {
    this->capturedTerritories--;
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

void Player::disconnect() {
  alive = false;
}

void Player::buildDestroyed(const BuildType &type) {
  if (type == BuildType::FORT)
    alive = false;
}

unsigned short Player::getAmountOfTerritories() const{
  return capturedTerritories;
}

PlayerID Player::getID() const {
  return id;
}

Player::~Player() {}
