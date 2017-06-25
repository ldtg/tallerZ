#include <client/view/sounds/SoundsFactory.h>
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
  }

  model->getMap().removeTerrainObject(id);

//  SoundPlayer &soundPlayer = view->getSoundPlayer();
//  Sound *sound = SoundsFactory::getTargetDestroyedSound();
//  soundPlayer.add(sound);
}
