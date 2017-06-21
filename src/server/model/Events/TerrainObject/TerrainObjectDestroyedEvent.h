#ifndef TALLERZ_SERVERTODESTROYEDEVENT_H
#define TALLERZ_SERVERTODESTROYEDEVENT_H

#include <common/DataEvents/TerrainObject/DataTerrainObjectIDEvent.h>
#include <server/model/Events/ServerEvent.h>

class TerrainObjectDestroyedEvent : public ServerEvent {
private:
  DataTerrainObjectIDEvent data;

 public:
  TerrainObjectDestroyedEvent(const TerrainObjectID &id);
  virtual std::stringstream getDataToSend() const;
};

#endif //TALLERZ_SERVERTODESTROYEDEVENT_H
