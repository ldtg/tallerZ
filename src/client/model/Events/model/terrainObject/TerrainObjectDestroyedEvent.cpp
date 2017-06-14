#include "TerrainObjectDestroyedEvent.h"

TerrainObjectDestroyedEvent::TerrainObjectDestroyedEvent(const TerrainObjectID &id)
    : id(id) {}

void TerrainObjectDestroyedEvent::process() {
  ObjectMapaVista *terrainObjVista = view->getTerrainObjectVista(id);
  Position pos = terrainObjVista->getPos();

  view->removeTerrainObjectVista(id);

  Sprite *explosion = VistasFactory::getEffectVista(SIDE_EXPLOSION);
  explosion->setPos(pos);
  view->addExplosionVista(explosion);
}
