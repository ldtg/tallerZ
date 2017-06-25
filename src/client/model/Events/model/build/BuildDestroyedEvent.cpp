#include <client/view/Sprite.h>
#include <client/view/sounds/SoundsFactory.h>
#include "BuildDestroyedEvent.h"
#define BUILDWIDHT 100
#define BUILDHEIGHT 100
BuildDestroyedEvent::BuildDestroyedEvent(const BuildID &id) : id(id) {}

void BuildDestroyedEvent::process() {
  BuildingView *buildingView = view->getBuildingView(id);
  buildingView->destroyed();

  Map &map = model->getMap();
  BuildState buildState = map.getBuildState(id);
  buildState.health=0;
  map.updateBuild(id, buildState);

//  SoundPlayer &soundPlayer = view->getSoundPlayer();
//  Sound *sound = SoundsFactory::getBuildDestroyedSound();
//  soundPlayer.add(sound);
}
