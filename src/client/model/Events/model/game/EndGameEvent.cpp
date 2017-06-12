#include "EndGameEvent.h"

EndGameEvent::EndGameEvent(const TeamID &winner) : winner(winner) {}

void EndGameEvent::process() {
  std::cerr<<"endgame"<<std::endl;
}
