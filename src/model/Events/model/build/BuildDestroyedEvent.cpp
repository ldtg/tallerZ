#include <view/Sprite.h>
#include "BuildDestroyedEvent.h"

BuildDestroyedEvent::BuildDestroyedEvent(const BuildID &id) : id(id) {}

void BuildDestroyedEvent::process() {
  ObjectMapaVista* unitVista = view->getBuildVista(id);
  Position pos = unitVista->getPos();

  view->removeBuildVista(id);
  std::string state("destroyed");
  ObjectMapaVista *buildVista = VistasFactory::getBuildVista(id.getType(), state, pos);
//  buildVista->setPos(pos);
  view->addBuildVista(id, buildVista);

  Sprite *deathBuildVista = VistasFactory::getEffectVista(TANK_MISSILE);
  deathBuildVista->setPos(pos.add(BUILDWIDHT/3, 0));
  view->addExplosionVista(deathBuildVista);

  Sprite *deathBuildVista2 = VistasFactory::getEffectVista(FIRE_SMOKE);
  deathBuildVista2->setPos(pos.add(BUILDWIDHT/4, BUILDHEIGHT/4));
  view->addEffectVista(deathBuildVista2);

  Sprite *deathBuildVista3 = VistasFactory::getEffectVista(FIRE_EFFECT);
  deathBuildVista3->setPos(pos.add(3*BUILDWIDHT/4, 3*BUILDHEIGHT/4));
  view->addEffectVista(deathBuildVista3);

  Sprite *deathBuildVista4 = VistasFactory::getEffectVista(FIRE_EFFECT);
  deathBuildVista4->setPos(pos.add(3*BUILDWIDHT/4-5, BUILDHEIGHT/4));
  view->addEffectVista(deathBuildVista4);

  Sprite *deathBuildVista5 = VistasFactory::getEffectVista(BIG_SMOKE);
  deathBuildVista5->setPos(pos.add(3*BUILDWIDHT/4-15, -15));
  view->addEffectVista(deathBuildVista5);

  Sprite *deathBuildVista6 = VistasFactory::getEffectVista(FIRE_SMOKE);
  deathBuildVista6->setPos(pos.add(BUILDWIDHT/4, 3*BUILDHEIGHT/4-5));
  view->addEffectVista(deathBuildVista6);
}
