#include "TerrainObjectDestroyedEvent.h"

TerrainObjectDestroyedEvent::TerrainObjectDestroyedEvent(const TerrainObjectID &id)
    : id(id) {}

void TerrainObjectDestroyedEvent::process() {
  ObjectMapaVista *terrainObjVista = view->getTerrainObjectVista(id);
  Position pos = terrainObjVista->getPos();

  view->removeTerrainObjectVista(id);

  Sprite *explosion = VistasFactory::getEffectVista(SIDE_EXPLOSION);
  explosion->setPos(pos.add(25, 25));
  view->addExplosionVista(explosion);

  TerrainObjectType type = id.getType();
  if (type == _WOODENBRIDGE || type == _ASPHALTEDBRIDGE) {
    std::string state("destroyed");
    ObjectMapaVista
        *destBridge = VistasFactory::getTerrainObjectVista(type, state, pos);
    destBridge->setPos(pos);
    view->addTerrainObjectVista(id, destBridge);
  }
  model->getMap().removeTerrainObject(id);
}
