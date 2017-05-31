#ifndef TALLERZ_TERRAINOBJECTDESTROYEDEVENT_H
#define TALLERZ_TERRAINOBJECTDESTROYEDEVENT_H

#include <model/Events/Event.h>
class TerrainObjectDestroyedEvent : public Event{
 private:
  TerrainObjectID id;
 public:
  explicit TerrainObjectDestroyedEvent(const TerrainObjectID &id);
  virtual void process() override;
};

#endif //TALLERZ_TERRAINOBJECTDESTROYEDEVENT_H
