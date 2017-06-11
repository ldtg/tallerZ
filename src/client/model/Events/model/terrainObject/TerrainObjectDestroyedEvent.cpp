#include "TerrainObjectDestroyedEvent.h"

TerrainObjectDestroyedEvent::TerrainObjectDestroyedEvent(const TerrainObjectID &id)
    : id(id) {}

void TerrainObjectDestroyedEvent::process() {
  ObjectMapaVista *terrainObjVista = view->getTerrainObjectVista(id);
  Position pos = terrainObjVista->getPos();

  view->removeTerrainObjectVista(id);

  std::string state("destroyed");
  terrainObjVista = VistasFactory::getTerrainObjectVista(id.getType(), state, pos);
//  buildVista->setPos(pos);
  view->addTerrainObjectVista(id, terrainObjVista);
}
