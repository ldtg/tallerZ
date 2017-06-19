#include "EndGameEvent.h"

EndGameEvent::EndGameEvent(const TeamID &winner) : winner(winner) {}

void EndGameEvent::process() {
  TeamID clientTeamId = model->getTeamID();
  if (clientTeamId == winner) {
    view->show_victory();
  }
}
