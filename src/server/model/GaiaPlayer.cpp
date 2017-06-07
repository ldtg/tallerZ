#include "GaiaPlayer.h"
GaiaPlayer::GaiaPlayer() : Player(PlayerColor::GREY){}
unsigned short GaiaPlayer::getAmountOfTerritories() {
  return 0;
}
void GaiaPlayer::addTerritory() {}
void GaiaPlayer::subTerritory() {}
void GaiaPlayer::addUnit() {}
void GaiaPlayer::subUnit() {}
bool GaiaPlayer::isAlive() const {
  return true;
}
void GaiaPlayer::buildDestroyed(const BuildType &type) {}
