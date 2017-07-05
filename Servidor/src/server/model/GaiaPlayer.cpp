#include "GaiaPlayer.h"
GaiaPlayer::GaiaPlayer() : Player(PlayerColor::GREY) {}

void GaiaPlayer::addTerritory() {}

void GaiaPlayer::subTerritory() {}

void GaiaPlayer::addUnit() {}

void GaiaPlayer::subUnit() {}

void GaiaPlayer::buildDestroyed(const BuildType &type) {}

bool GaiaPlayer::isAlive() const {
  return true;
}

GaiaPlayer::~GaiaPlayer() {}
