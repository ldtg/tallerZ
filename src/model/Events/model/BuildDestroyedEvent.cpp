#include <view/Sprite.h>
#include "BuildDestroyedEvent.h"

BuildDestroyedEvent::BuildDestroyedEvent(const BuildID &id) : id(id) {}

void BuildDestroyedEvent::process() {
  ObjectMapaVista* unitVista = view->getBuildVista(id);
  Position pos = unitVista->getPos();

  view->removeBuildVista(id);

  std::string state("_destroyed");
  ObjectMapaVista *buildVista = view->getBuildVista(id.getType(), state);

  view->addBuildVista(id, buildVista);

//  ObjectMapaVista *deathBuildVista = new Sprite("../src/view/images/buildings/fort/"
//                                                "destroyed_effect/destroyed_effect_n", 12, 1);
  ObjectMapaVista *deathBuildVista = new Sprite("../src/view/images/explosion/"
                                                    "tank_missile_explosion1_n", 12, 1);
  view->addExplosionVista(deathBuildVista, pos.add(BUILDWIDHT/4, BUILDHEIGHT/4));
}
