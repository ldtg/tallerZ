#include <view/Sprite.h>
#include "BuildDestroyedEvent.h"

BuildDestroyedEvent::BuildDestroyedEvent(const BuildID &id) : id(id) {}

void BuildDestroyedEvent::process() {
  ObjectMapaVista* unitVista = view->getBuildVista(id);
  Position pos = unitVista->getPos();

  view->removeBuildVista(id);
  std::string state("destroyed");
  ObjectMapaVista *buildVista = VistasFactory::getBuildVista(id.getType(), state);
  view->addBuildVista(id, buildVista);

//  Sprite *deathBuildVista = new Sprite("../src/view/images/effects/explosion/"
//                                                    "tank_missile_explosion1_n", 12, 10, 0);
  Sprite *deathBuildVista = VistasFactory::getEffectVista(TANK_MISSILE);

  view->addExplosionVista(deathBuildVista, pos.add(BUILDWIDHT/3, 0));
}
