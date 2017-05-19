#include "UnitDeathEvent.h"
UnitDeathEvent::UnitDeathEvent(UnitID id) :id(id){
}
void UnitDeathEvent::process(Map &map) const {
  map.removeUnit(id);
}
