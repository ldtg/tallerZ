#include "UnitAttackTerrainObjectCommand.h"
UnitAttackTerrainObjectCommand::UnitAttackTerrainObjectCommand(const DataUnitAttackTOCommand &data)
    : data(data) {

}
void UnitAttackTerrainObjectCommand::execute(GameController &gc) {
  gc.attack(data.attacker, data.attacked);
}
