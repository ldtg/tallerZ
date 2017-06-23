#include <client/view/Sprite.h>
#include <client/view/sounds/SoundsFactory.h>
#include "BuildDestroyedEvent.h"
#define BUILDWIDHT 100
#define BUILDHEIGHT 100
BuildDestroyedEvent::BuildDestroyedEvent(const BuildID &id) : id(id) {}

void BuildDestroyedEvent::process() {
  ObjectMapaVista* buildVista = view->getBuildVista(id);
  Position pos = buildVista->getPos();

  view->removeBuildVista(id);
  std::string state("destroyed");
  buildVista = VistasFactory::getBuildVista(id.getType(), state, pos);

  view->addBuildVista(id, buildVista);

//  Sprite *deathBuildVista = VistasFactory::getEffectVista(TANK_MISSILE, pos);
//  deathBuildVista->setPos(pos.add(BUILDWIDHT / 3, 0));
//  view->addExplosionVista(deathBuildVista);

  Sprite *deathBuildVista2 = VistasFactory::getEffectVista(FIRE_SMOKE, pos);
  deathBuildVista2->setPos(pos.add(BUILDWIDHT / 4, BUILDHEIGHT / 4));
  view->addEffectVista(deathBuildVista2);

  Sprite *deathBuildVista3 = VistasFactory::getEffectVista(FIRE_EFFECT, pos);
  deathBuildVista3->setPos(pos.add(3 * BUILDWIDHT / 4, 3 * BUILDHEIGHT / 4));
  view->addEffectVista(deathBuildVista3);

  Sprite *deathBuildVista4 = VistasFactory::getEffectVista(FIRE_EFFECT, pos);
  deathBuildVista4->setPos(pos.add(3 * BUILDWIDHT / 4 - 5, BUILDHEIGHT / 4));
  view->addEffectVista(deathBuildVista4);

  Sprite *deathBuildVista5 = VistasFactory::getEffectVista(BIG_SMOKE, pos);
  deathBuildVista5->setPos(pos.add(3 * BUILDWIDHT / 4 - 15, -15));
  view->addEffectVista(deathBuildVista5);

  Sprite *deathBuildVista6 = VistasFactory::getEffectVista(FIRE_SMOKE, pos);
  deathBuildVista6->setPos(pos.add(BUILDWIDHT / 4, 3 * BUILDHEIGHT / 4 - 5));
  view->addEffectVista(deathBuildVista6);

  Map &map = model->getMap();
  BuildState buildState = map.getBuildState(id);
  buildState.health=0;
  map.updateBuild(id, buildState);

//  SoundPlayer &soundPlayer = view->getSoundPlayer();
//  Sound *sound = SoundsFactory::getBuildDestroyedSound();
//  soundPlayer.add(sound);
}
