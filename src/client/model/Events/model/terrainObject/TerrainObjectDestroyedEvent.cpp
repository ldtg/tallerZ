#include "TerrainObjectDestroyedEvent.h"

TerrainObjectDestroyedEvent::TerrainObjectDestroyedEvent(const TerrainObjectID &id)
    : id(id) {}

void TerrainObjectDestroyedEvent::process() {
  ObjectView *terrainObjVista = view->getTerrainObjectView(id);
  Position pos = terrainObjVista->getPos();

  view->removeTerrainObjectView(id);

  TerrainObjectType type = id.getType();
  if (type == _WOODENBRIDGE || type == _ASPHALTEDBRIDGE) {
    std::string state("destroyed");
    Image *destBridge = ViewFactory::getTerrainObjectVista(type, state, pos);
    destBridge->setPos(pos);
    view->addTerrainObjectView(id, destBridge);

    Sprite *effect1 = ViewFactory::getEffectVista(FIRE_SMOKE, pos);
    effect1->setPos(pos.add(25,30));
    view->addEffectView(effect1);

    Sprite *effect2 = ViewFactory::getEffectVista(BIG_SMOKE, pos);
    effect2->setPos(pos.add(53,53));
    view->addEffectView(effect2);

    Sprite *effect3 = ViewFactory::getEffectVista(FIRE_EFFECT, pos);
    effect3->setPos(pos.add(80,15));
    view->addEffectView(effect3);
  }

  model->getMap().removeTerrainObject(id);
}
