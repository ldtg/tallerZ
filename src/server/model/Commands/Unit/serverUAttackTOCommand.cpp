#include "serverUAttackTOCommand.h"
serverUAttackTOCommand::serverUAttackTOCommand(const dataUnitAttackTOCommand &data)
    : data(data) {

}
void serverUAttackTOCommand::execute(GameController &gc) {
  gc.attack(data.attacker, data.attacked);
}
