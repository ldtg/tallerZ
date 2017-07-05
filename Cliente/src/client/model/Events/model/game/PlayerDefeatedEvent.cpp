#include "PlayerDefeatedEvent.h"
PlayerDefeatedEvent::PlayerDefeatedEvent(const PlayerID &playerid)
    : playerID(playerid) {}

void PlayerDefeatedEvent::process() {
  PlayerID clientId = model->getPlayer();
  if (clientId == playerID) {
    view->show_defeat();
  }
}
